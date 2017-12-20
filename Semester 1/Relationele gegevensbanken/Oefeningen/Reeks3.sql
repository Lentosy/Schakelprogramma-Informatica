-- 2.
SELECT hasc, iso, ROUND(gebruik,9),
  CASE WHEN MAX(gebruik) OVER(PARTITION BY hasc) = gebruik THEN 'max' ELSE ' ' END
FROM Taalgebruik
WHERE hasc IN ('BE', 'NL' , 'FR')
ORDER BY hasc;

-- 3.
SELECT resort, discipline, gender, COUNT(1),
  CASE WHEN SUM(COUNT(1)) OVER(PARTITION BY resort, discipline) = COUNT(1) THEN 'X' ELSE ' ' END AS "C"
FROM Races
GROUP BY resort,discipline,gender
ORDER BY resort,discipline,gender;


-- 4.
SELECT iso, ROUND(MAX(gebruik),9) AS "GEBRUIK",
  CASE WHEN MIN(gebruik) = MIN(MAX(gebruik)) OVER() THEN 'X' ELSE ' ' END AS "C"
FROM taalgebruik
WHERE hasc IN ('BE', 'DE')
GROUP BY iso;

-- 5.
SELECT resort,discipline,COUNT(1),
  COUNT(DISTINCT discipline) OVER(PARTITION BY resort) AS "AANTDISCIPLINE",
  COUNT(resort) OVER(PARTITION BY discipline) AS "AANTRESORTS"
FROM Races
GROUP BY resort,discipline
ORDER BY resort, discipline;

-- 6.
SELECT rid,name,rank,points,
rank() OVER(ORDER BY rid, rank) AS "RANKNR",
row_number() OVER(ORDER BY rid) AS "NR"
FROM Results
WHERE rid BETWEEN 180 AND 182 AND points >0
ORDER BY rid,points DESC;

-- 7.
SELECT lev1, lev2, MAX(population),
RANK() OVER(ORDER BY MAX(population) DESC) AS "NR",
SUBSTR(lev1,0 ,2) || RANK() OVER(PARTITION BY lev1 ORDER BY MAX(population) DESC, lev1) 
FROM Cities
WHERE iso = 'BE'
GROUP BY lev1, lev2;

-- 8.
SELECT   name, population, area, 
	 ROUND(elevation - SUM(area * elevation) OVER() / SUM(area) OVER(), 0) AS "REL HOOGTELIGGING",
	 RANK() OVER(ORDER BY (population / area) DESC) AS "RANG BEVOLKINGSDICHTHEID"
FROM     regios
WHERE    parent = 'EUR'
         AND area IS NOT NULL
         AND elevation IS NOT NULL
ORDER BY name;

-- 9.
SELECT   resort, racedate,
         RANK()       OVER(PARTITION BY resort ORDER BY racedate) AS "RIJNR PER RESORT",
         ROW_NUMBER() OVER(ORDER BY resort, racedate)             AS "RIJNR VOLGENS RESORT/DATUM",
         RANK()       OVER(ORDER BY racedate)                     AS "RIJNR VOLGENS DATUM"
FROM     races
WHERE    EXTRACT(YEAR FROM racedate) = 2008
ORDER BY resort;


-- 10.
SELECT hasc,
      ROUND(SUM(CASE WHEN iso IN ('ned','fra','dui') THEN gebruik * 100 END), 2) AS "NED/FR/DUI",
      rank() OVER(ORDER BY SUM(CASE WHEN iso IN ('ned','fra','dui') THEN gebruik * 100 END) DESC) AS "RANK",
      CASE WHEN rank() OVER(ORDER BY SUM(CASE WHEN iso IN ('ned','fra','dui') THEN gebruik * 100 END) DESC) = 1 THEN 'max' ELSE ' ' END AS "MAX",
      ROUND(SUM(CASE WHEN iso IN ('tur','spa','ita','ara') THEN gebruik * 100 END), 2) AS "TUR/SPA/ARA/ITA",
      ROUND(sum(gebruik) * 100, 2) AS "SOM" 
FROM  taalgebruik
WHERE 
      iso in ('ned','fra','dui','tur','spa','ita','ara')
      and hasc in ('BE','NL','FR','DE') 
GROUP BY hasc
ORDER BY som DESC


-- 12.
select 
      case 2 * grouping(extract(year from racedate + 183)) + grouping(discipline)
        when 0 then to_char(extract(year from racedate + 183))
        when 1 then ' '
        when 3 then ' '
        else 'alle seizoenen'
      end as seizoen,      
      case 
        when grouping(discipline) = 1
        then '--------'
        else
          case discipline
            when 'DH' then 'Afdaling'
            when 'SG' then 'SuperG'
            when 'GS' then 'Reuzeslalom'
            when 'SL' then 'Slalom'
            when 'KB' then 'Combinatie'
        end 
       end as discipline,
       sum(case when gender = 'M' then 1 end) as man,
       sum(case when gender = 'L' then 1 end) as vrouw,
       sum(1) as totaal,
       case 
         when grouping(discipline) = 0
         then to_char(rank() over(partition by extract(year from racedate + 183) order by sum(1) desc) - 1)
         else ' ' 
       end as ranking,
       case when grouping(discipline) = 1 then
          to_char(round(sum(1) / count(distinct discipline), 2))
          else ' '
       end as "#/DISCIPLINE",
       case when 2 * grouping(extract(year from racedate + 183)) + grouping(discipline) = 2
        then to_char(count(discipline) over (partition by discipline))
        else ' '
       end as "#seizoenen"
from races
where discipline in ('DH', 'SG', 'GS', 'SL', 'KB')
group by cube(extract(year from racedate + 183), discipline)
order by extract(year from racedate + 183),
         case discipline
          when 'Afdaling' then 1
          when 'SuperG' then 2
          when 'Reuzeslalom' then 3
          when 'Slalom' then 4
          when 'Combinatie' then 5
         end

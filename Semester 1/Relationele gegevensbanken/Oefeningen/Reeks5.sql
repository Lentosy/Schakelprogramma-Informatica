-- 1.
select   ra.*
from     resorts re
  join   races ra on ra.resort = re.name
where    re.nation = 'FRA'
order by ra.racedate


-- 2.
select   case
	  when grouping(discipline) = 0
	  then discipline
    	  else 'totaal aantal resorts'
         end,
         count(distinct ra.resort)
from     races ra
  join   resorts re on ra.resort = re.name
where    re.nation = 'FRA'
group by rollup(discipline)
order by discipline;


-- 3.
-- TODO: 2de count
select nation,
       count(distinct ra.resort) AS "AANTRESORTS",
       count(case when re.finishaltitude >= 1500 then 1 end) AS "AANT_1500"
from   resorts re
       join races ra on re.name = ra.resort    
where  ra.discipline = 'DH'
       and finishaltitude is not null
group  by nation
order  by nation;

-- 4.
select   distinct trunc( months_between(to_date('01/01/2007','dd/mm/yyyy'),birthdate) /12) AS "LEEFTIJD",
         coalesce('    ' || round(avg(case when c.gender = 'M' then points end),2), ' ') as "MAN",
         coalesce('    ' || round(avg(case when c.gender = 'L' then points end),2), ' ') as "VROUW"
from     competitors c
  join   ranking r on r.cid = c.cid
where    birthdate is not null
  and    season = 2007
group by trunc( months_between(to_date('01/01/2007','dd/mm/yyyy'),birthdate) /12)
order by "LEEFTIJD";
  
-- 6.
SELECT x.discipline,x.gender,x.racedate,x.resort,y.racedate,y.resort
FROM     Races x
    JOIN Races y ON ( x.discipline=y.discipline
                      and       x.gender=y.gender
                      and       x.rid <> y.rid
                      and      x.resort<>y.resort
                      and    y.racedate between x.racedate and x.racedate +1)
   ORDER BY x.racedate,x.discipline
  
-- 7.
-- todo?
select distinct a.name, a.population, b.population
from   regios a
  join regios b on (b.cid = a.cid
               and b.parent = a.parent
               and b.population between a.population and a.population + 5)
where  substr(a.hasc,1,2) = 'BE'
  and  a.niveau = 4
order by a.name;



-- 13.
select a.season, a.gender, a.discipline, a.name, a.points, 1 + count(case when a.points < b.points then 1 end) ranking
from ranking a
     join ranking b on a.season = b.season
                    and a.gender = b.gender
               	    and a.discipline = b.discipline
            	    and a.points <= b.points
where a.season between 1986 and 1990
group by a.season, a.gender, a.discipline, a.name, a.points
having count(case when a.points < b.points then 1 end ) < 3
order by a.season, a.gender, a.discipline, a.points desc;

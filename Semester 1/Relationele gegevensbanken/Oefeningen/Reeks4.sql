-- 1.
SELECT   birthplace
FROM     competitors
WHERE    nation = 'RUS' AND birthplace IS NOT NULL
  UNION ALL
SELECT   'Moscou'
FROM     dual
  UNION ALL
SELECT   'Vladivostok'
FROM     dual
ORDER BY 1;

-- 3.
SELECT name,gender, points * 2
FROM   Ranking
WHERE  season=2006
  AND  gender = 'M'
  UNION
SELECT name,gender, points * 3
FROM   Ranking
WHERE  season=2006
  AND  gender = 'L';

 -- 4.
SELECT iso AS "LA" , lev1 AS "REGIO", count(1) AS "AANT"
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL
GROUP BY iso, lev1
  UNION ALL
SELECT ' ', '**totaal land *' || iso , COUNT(1)
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL
GROUP BY iso
  UNION ALL
SELECT ' ', '**totaal**', COUNT(1)
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL;


-- 5.
-- TODO: enkel hoogste 
select hasc, iso, max(gebruik)
from taalgebruik
where hasc in ('NL', 'FR', 'DE')
group by hasc, iso
  intersect
select hasc, iso, max(gebruik) over(partition by hasc)
from taalgebruik
where hasc in ('NL', 'FR', 'DE');

-- 6.
select season, name, 
  case
    when max(sum(points)) over(partition by season) = sum(points) then sum(points) 
  end AS "MAXPUNTEN"
from ranking
group by season, name
  intersect
select season, name, sum(points)
from ranking
group by season, name;

-- 8.
SELECT resort, discipline, gender, COUNT(1),
  CASE WHEN SUM(COUNT(1)) OVER(PARTITION BY resort, discipline) = COUNT(1) THEN 'X' ELSE ' ' END AS "C"
FROM Races
GROUP BY resort,discipline,gender
  INTERSECT
select resort, discipline, gender, COUNT(1), 'X'
FROM Races
GROUP BY resort,discipline,gender
ORDER BY resort,discipline,gender

-- 9.
(select name, weight, gender, rank() over(partition by gender order by max(weight) desc)
from competitors
where weight is not null
group by name, weight, gender
  intersect
select name, weight, gender, 1
from competitors)
  union
(select name, weight, gender, rank() over(partition by gender order by max(weight) desc)
from competitors
where weight is not null
group by name, weight, gender
  intersect
select name, weight, gender, 2
from competitors)
order by weight desc, gender, 4; 


-- 10.
(select season, gender, discipline, name, points, rank() over(partition by gender, discipline, season order by points desc) AS "RANKING"
from ranking
where season between 1986 and 1990
      and discipline IS NOT NULL
  intersect
select season, gender, discipline, name, points, 1
from ranking)
  union all
(select season, gender, discipline, name, points, rank() over(partition by gender, discipline, season order by points desc) AS "RANKING"
from ranking
where season between 1986 and 1990
      and discipline IS NOT NULL
  intersect
select season, gender, discipline, name, points, 2
from ranking)
  union all
(select season, gender, discipline, name, points, rank() over(partition by gender, discipline, season order by points desc) AS "RANKING"
from ranking
where season between 1986 and 1990
      and discipline IS NOT NULL
  intersect
select season, gender, discipline, name, points, 3
from ranking)
order by season, gender, discipline, points desc, name, 5



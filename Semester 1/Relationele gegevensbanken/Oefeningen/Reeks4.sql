-- 1.
SELECT birthplace
FROM competitors
WHERE nation = 'RUS' AND birthplace IS NOT NULL
  UNION 
SELECT 'Moscou'
FROM dual
  UNION
SELECT 'Vladivostok'
FROM dual;

-- 3.
SELECT name,gender, points * 2
FROM Ranking
WHERE season=2006 AND gender = 'M'
  UNION
SELECT name,gender, points * 3
FROM Ranking
WHERE season=2006 AND gender = 'L';

 -- 4.
 -- TODO: sorteren
SELECT iso AS "LA" , lev1 AS "REGIO", count(1) AS "AANT"
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL
GROUP BY iso, lev1
  UNION
SELECT ' ', '**totaal**', COUNT(1)
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL
  UNION
SELECT ' ', '**totaal land *' || iso , COUNT(1)
FROM cities
WHERE iso IN ('DE', 'FR') AND lev1 IS NOT NULL
GROUP BY iso







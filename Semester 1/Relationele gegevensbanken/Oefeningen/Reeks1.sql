-- 1.
SELECT DISTINCT CASE nation 
  WHEN 'ITA' THEN 'Italie'
  WHEN 'GER' THEN 'Duitsland'
  WHEN 'AUT' THEN 'Oostenrijk'
  WHEN 'SUI' THEN 'Zwitserland'
  ELSE nation 
  END land
FROM Resorts;


-- 2.
SELECT name, finishaltitude, 
  CASE 
    WHEN finishaltitude <  1300  THEN 'laag'
    WHEN finishaltitude >= 1300 AND finishaltitude <= 1700 THEN 'middelmatig'
    WHEN finishaltitude > 1700 THEN 'hoog'
  END hoogte
FROM Resorts
WHERE nation = 'ITA'
  AND finishaltitude IS NOT NULL
ORDER BY finishaltitude;


-- 3.
SELECT name, finishaltitude,
  CASE 
    WHEN finishaltitude < 1300 
    THEN 'X' 
    ELSE ' '
  END laag,
  CASE 
    WHEN finishaltitude >= 1300 
      AND finishaltitude <=1700 
    THEN 'X' 
    ELSE ' '
  END midden,
  CASE 
    WHEN finishaltitude > 1700 
    THEN 'X'
    ELSE ' ' 
  END hoog
FROM Resorts
WHERE nation = 'ITA'
  AND finishaltitude IS NOT NULL
ORDER BY finishaltitude;


-- 4.
-- TODO: per discipline elk resort max 1 keer
SELECT  discipline, resort
FROM races

ORDER BY 
  CASE discipline
    WHEN 'KB' THEN 0
    WHEN 'GS' THEN 1
    WHEN 'SL' THEN 2
    WHEN 'DH' THEN 3
    WHEN 'SG' THEN 4
  END,
  resort;
  
-- 5.
SELECT rid, modus
FROM Races
WHERE discipline = 'SL'
  AND gender = 'M'
ORDER BY 
  CASE 
    WHEN modus IS NULL THEN -1
    ELSE modus
  END;

-- 6.
SELECT name,
  ROUND((weight/(height * height)), 7) AS bmi,
  CASE 
    WHEN weight/(height * height) < 18.5 THEN 'ondergewicht'
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 THEN 'gewicht ok'
    WHEN weight/(height * height) >= 25 THEN 'overgewicht'
  END resultaat
FROM competitors
WHERE weight IS NOT NULL
  AND height IS NOT NULL
  AND gender = 'M'
ORDER BY bmi;

-- 7.
SELECT name,
  ROUND((weight/(height * height)), 7) AS bmi,
  CASE 
    WHEN weight/(height * height) < 18.5 THEN 'ondergewicht'
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 THEN 'gewicht ok'
    WHEN weight/(height * height) >= 25 THEN 'overgewicht'
  END resultaat
FROM competitors
WHERE weight IS NOT NULL
  AND height IS NOT NULL
  AND gender = 'M'
ORDER BY 
  CASE 
    WHEN weight/(height * height) < 18.5 THEN 2
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 THEN 0
    WHEN weight/(height * height) >= 25 THEN 1
  END,
  bmi;
  
-- 8.
SELECT name,
  ROUND((weight/(height * height)), 7) AS bmi,
  CASE 
    WHEN weight/(height * height) < 18.5 AND gender = 'M' THEN 'ondergewicht'
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 AND gender = 'M' THEN 'gewicht ok'
    WHEN weight/(height * height) >= 25 AND gender = 'M' THEN 'overgewicht'
    WHEN weight/(height * height) < 17 AND gender = 'L' THEN 'ondergewicht'
    WHEN weight/(height * height) >= 17 AND weight/(height * height) <= 23.9999 AND gender = 'L' THEN 'gewicht ok'
    WHEN weight/(height * height) >= 24 AND gender = 'L' THEN 'overgewicht'
  END resultaat
FROM competitors
WHERE weight IS NOT NULL
  AND height IS NOT NULL
ORDER BY 
  CASE 
    WHEN weight/(height * height) < 18.5 THEN 2
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 then 0
    WHEN weight/(height * height) >= 25 THEN 1
  END,
  bmi;

-- 9.
SELECT name,
  gender as g,
  ROUND((weight/(height * height)), 7) AS bmi,
  CASE
    WHEN weight/(height * height) < 18.5 AND gender = 'M' THEN 'X'
    WHEN weight/(height * height) < 17 AND gender = 'L' THEN 'X'
    ELSE ' '
  END ondergewicht,
    
  CASE  
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 AND gender = 'M' THEN 'X'
    WHEN weight/(height * height) >= 17 AND weight/(height * height) <= 23.9999 AND gender = 'L' THEN 'X'
    ELSE ' '
  END gewichtok,
  
  CASE 
    WHEN weight/(height * height) >= 25 AND gender = 'M' THEN 'X'
    WHEN weight/(height * height) >= 24 AND gender = 'L' THEN 'X'
    ELSE ' '
  end overgewicht
FROM competitors
WHERE weight IS NOT NULL
  AND height IS NOT NULL
ORDER BY 
  CASE 
    WHEN weight/(height * height) < 18.5 THEN 2
    WHEN weight/(height * height) >= 18.5 AND weight/(height * height) <= 24.9999 then 0
    WHEN weight/(height * height) >= 25 THEN 1
  END,
  bmi;

-- 10.
SELECT racedate,
       resort, 
       CASE discipline
        WHEN 'SL' THEN 'Slalom'
        WHEN 'GS' THEN 'Reuzeslalom'
        WHEN 'SG' THEN 'Super-G'
        WHEN 'DH' THEN 'Afdaling'
        ELSE 'Combinatie'
       END 
FROM Races
WHERE racedate LIKE '%/%/06'
ORDER BY 
  CASE discipline
    WHEN 'SL' THEN 0
    WHEN 'GS' THEN 1
    WHEN 'SG' THEN 2
    WHEN 'DH' THEN 3
  END;

-- 11.
SELECT racedate,
       resort, 
       CASE 
         WHEN discipline LIKE 'DH' 
         THEN 'X'
         ELSE ' '
       END afdaling,
       CASE 
         WHEN discipline LIKE 'SG' 
         THEN 'X'
         ELSE ' '
       END superg,
       CASE 
         WHEN discipline LIKE 'GS' 
         THEN 'X'
         ELSE ' '
       END reuzeslalom,
       CASE 
         WHEN discipline LIKE 'SL' 
         THEN 'X'
         ELSE ' '
       END slalom,
       CASE 
         WHEN discipline LIKE 'KB' 
         THEN 'X'
         ELSE ' '
       END combinatie
FROM Races
WHERE racedate LIKE '%/%/06'
ORDER BY 
  racedate, resort;
  
  
-- 12.
SELECT rid, rank, 
  CASE 
    WHEN points IS NULL then 0
    ELSE points
  END points
FROM Results
WHERE rank = 4 
  AND points < 12


-- 13.
SELECT name,
  CASE gender
    WHEN NULL THEN 'onbekend'
    WHEN 'M' THEN 'man'
    WHEN 'L' THEN 'vrouw'
  END geslacht
FROM competitors
ORDER BY name;

-- 14.
SELECT name,nation,
  CASE 
    WHEN finishaltitude < 1300 THEN 'laag'
    WHEN finishaltitude >=1300 AND finishaltitude < 1700 THEN 'middelmatig'
    WHEN finishaltitude > 1700 THEN 'hoog'
  END
FROM resorts
WHERE finishaltitude is not null
ORDER BY 
  CASE nation
    WHEN 'ITA' THEN 1
    WHEN 'SUI' THEN 2
    WHEN 'AUT' THEN 3
  END,
  finishaltitude;

-- 15.
-- todo: sorteren
SELECT 
  CASE
    WHEN EXTRACT(YEAR FROM racedate + 183) >= 1990 
      AND EXTRACT(YEAR FROM racedate + 183) < 1993
      THEN EXTRACT(YEAR FROM racedate + 183)
    END seizoen
    , racedate,
    
    CASE 
      WHEN 
        EXTRACT(MONTH FROM racedate) >= 3 
         AND EXTRACT(MONTH FROM racedate) < 6
         AND EXTRACT(DAY FROM racedate) >= 21
        OR EXTRACT(MONTH FROM racedate) BETWEEN 4 AND 5
        OR EXTRACT(MONTH FROM racedate) = 6
         AND EXTRACT(DAY FROM racedate) <= 20
      THEN 'X'
      ELSE ' '
    END lente,
    
    CASE 
      WHEN 
        EXTRACT(MONTH FROM racedate) >= 6 
         AND EXTRACT(MONTH FROM RACEDATE) < 9
         AND EXTRACT(DAY FROM racedate) >= 21
        OR EXTRACT(MONTH FROM racedate) BETWEEN 7 AND 8
        OR EXTRACT(MONTH FROM racedate) = 9
         AND EXTRACT(DAY FROM racedate) <= 20
      THEN 'X'
      ELSE ' '
    END zomer,
    
    CASE 
      WHEN 
        EXTRACT(MONTH FROM racedate) >= 9 
         AND EXTRACT(MONTH FROM RACEDATE) < 12
         AND EXTRACT(DAY FROM racedate) >= 21
        OR EXTRACT(MONTH FROM racedate) BETWEEN 10 AND 11
        OR EXTRACT(MONTH FROM racedate) = 12
         AND EXTRACT(DAY FROM racedate) <= 20
      THEN 'X'
      ELSE ' '
    END herfst,
    
    CASE 
      WHEN 
        EXTRACT(MONTH FROM racedate) = 12
         AND EXTRACT(DAY FROM racedate) >= 21
        OR EXTRACT(MONTH FROM racedate) <= 2
        OR EXTRACT(MONTH FROM racedate) = 2
         AND EXTRACT(DAY FROM racedate) <= 20    
      THEN 'X'
      ELSE ' '
    END winter
    
FROM races
WHERE discipline = 'SL'
ORDER BY zomer, lente, herfst, winter, seizoen ;


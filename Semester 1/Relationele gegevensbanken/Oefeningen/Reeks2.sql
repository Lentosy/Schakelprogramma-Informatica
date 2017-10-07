-- 1.

SELECT 
  MIN(birthdate) AS oudste,
  MAX(birthdate) AS jongste
FROM competitors;

-- 2.
SELECT AVG(finishaltitude)
FROM resorts
WHERE nation = 'ITA';

-- 3.
SELECT COUNT(1)
FROM races
WHERE modus IS NULL;

-- 4.
SELECT COUNT(DISTINCT nation) AS aantal_landen
FROM resorts;

-- 5.
SELECT nation, ROUND(AVG(finishaltitude), 1)
FROM resorts
WHERE nation IN ('AUT', 'ITA', 'SUI')
GROUP BY nation;

-- 6.
SELECT nation, 
  ROUND(AVG(CASE 
    WHEN nation IN ('AUT', 'ITA', 'SUI') 
    THEN finishaltitude
  END),2) gemhoogte
FROM resorts
GROUP BY nation
ORDER BY nation;

-- 7.
SELECT cid, name,
  SUM(
  CASE 
    WHEN rank = 1 
    THEN 1 
    ELSE 0 
  END ) aantal
FROM results
GROUP BY cid, name
ORDER BY aantal DESC;

-- 8.
SELECT resort,
  COUNT(DISTINCT discipline) as aantal
FROM races
WHERE gender = 'L'
  AND EXTRACT(YEAR FROM racedate) = 2006
GROUP BY resort
HAVING COUNT(DISTINCT discipline) < 4
ORDER BY aantal

-- 9.
SELECT cid, name,
  SUM(
    CASE
      WHEN rank <= 2 THEN 1
      ELSE 0
    END) aantal
FROM results
GROUP BY cid, name
HAVING SUM(
    CASE
      WHEN rank = 1 OR rank = 2 THEN 1
      ELSE 0
    END) >= 2
ORDER BY aantal DESC

-- 11.
SELECT 
  EXTRACT(YEAR from racedate) AS racejaar,
  discipline,
  COUNT(discipline)
FROM Races
WHERE EXTRACT(YEAR FROM racedate) > 1999
  AND discipline IN ('SG', 'SL')
GROUP BY discipline, EXTRACT(YEAR from racedate)
ORDER BY racejaar, discipline;

-- 12.
SELECT cid, name,
  SUM(CASE 
    WHEN season = 2005 THEN points
    END ) P05,
  SUM(CASE
    WHEN season = 2006 THEN points
    END ) P06
FROM ranking
WHERE season >= 2005 
  AND season <= 2006 
GROUP BY cid, name
HAVING SUM(CASE 
    WHEN season = 2005 THEN points
    END ) > 1
    AND SUM(CASE 
    WHEN season = 2006 THEN points
    END ) > 1
ORDER BY SUM(points);

-- 14.
SELECT cid, name,
  CASE 
    WHEN rank <= 3 THEN 'fantastisch'
    WHEN rank <= 6 THEN 'goed'
    WHEN rank <= 9 THEN 'bijna goed'
    WHEN rank <= 12 THEN 'slecht'
    ELSE 'zeer slecht'
  END keuze,
  COUNT(rank)
FROM Results
GROUP BY cid, name,
  CASE 
    WHEN rank <= 3 THEN 'fantastisch'
    WHEN rank <= 6 THEN 'goed'
    WHEN rank <= 9 THEN 'bijna goed'
    WHEN rank <= 12 THEN 'slecht'
    ELSE 'zeer slecht'
  END
ORDER BY name, 
  CASE keuze
    WHEN 'fantastisch' THEN 0
    WHEN 'goed' THEN 1
    WHEN 'bijna goed' THEN 2
    WHEN 'slecht' THEN 3
    ELSE 4
  END

-- 15.
SELECT cid, name,
  COUNT(CASE WHEN RANK <= 3 THEN 1 END) fantastisch,
  COUNT(CASE WHEN RANK BETWEEN 4 AND 6 THEN 1 END) goed,
  COUNT(CASE WHEN RANK BETWEEN 7 AND 9 THEN 1 END) bijnagoed,
  COUNT(CASE WHEN RANK BETWEEN 10 AND 12 THEN 1 END) slect,
  COUNT(CASE WHEN RANK > 12 THEN 1 END) zeerslecht
FROM Results
GROUP BY cid, name
ORDER BY name


-- 16.
-- TODO: aantal
SELECT nation,
  CASE 
    WHEN COUNT(CASE WHEN finishaltitude < 1300 THEN 1 END) > 0 THEN CAST(COUNT(CASE WHEN finishaltitude < 1300 THEN 1 END) AS CHAR) ELSE ' '
  END laag,
  CASE 
    WHEN COUNT(CASE WHEN finishaltitude >= 1300 AND finishaltitude < 2150 THEN 1 END) > 0 THEN CAST(COUNT(CASE WHEN finishaltitude >= 1300 AND finishaltitude < 2150 THEN 1 END) AS CHAR) ELSE ' '
  END middelmatig,
  CASE
    WHEN COUNT(CASE WHEN finishaltitude >= 2150 THEN 1 END) > 0 THEN CAST(COUNT(CASE WHEN finishaltitude >= 2150 THEN 1 END) AS CHAR) ELSE ' '
  END hoog,
  COUNT(
    CASE 
      WHEN finishaltitude < 1300 THEN 1
      WHEN finishaltitude >= 1300 AND finishaltitude < 2150 THEN 1
      WHEN finishaltitude >= 2150 THEN 1
    END
  ) aantal
FROM resorts
WHERE finishaltitude is not null
GROUP BY nation
ORDER BY 
  CASE
    WHEN nation = 'ITA' THEN 0
    WHEN nation = 'SUI' THEN 1
    WHEN nation = 'AUT' THEN 2
  END,
  nation;

-- 17.
SELECT hasc,
  SUM(CASE WHEN iso = 'ned' THEN 1 ELSE 0 END) nederlands,
  SUM(CASE WHEN iso = 'fra' THEN 1 ELSE 0 END) frans,
  SUM(CASE WHEN iso = 'dui' THEN 1 ELSE 0 END) duitsland,
  CASE WHEN COUNT(
    CASE 
      WHEN iso = 'ned' THEN 1 
      WHEN iso = 'fra' THEN 1 
      WHEN iso = 'dui' THEN 1 
    END) = 3 THEN 'X' ELSE ' ' END AA
FROM Taalgebruik
GROUP BY hasc
HAVING COUNT(
    CASE 
      WHEN iso = 'ned' THEN 1 
      WHEN iso = 'fra' THEN 1 
      WHEN iso = 'dui' THEN 1 
    END) > 1 
ORDER BY hasc;




-- 19.
-- TODO: sorteren
SELECT 
  CASE 
    WHEN iso = 'ned' THEN 'nederlands'
    WHEN iso = 'fra' THEN 'frans'
    WHEN iso = 'dui' THEN 'duits'
  END taal,
  COUNT(gebruik)
FROM taalgebruik
WHERE iso IN ('ned', 'fra', 'dui')
GROUP BY 
  CASE 
    WHEN iso = 'ned' THEN 'nederlands'
    WHEN iso = 'fra' THEN 'frans'
    WHEN iso = 'dui' THEN 'duits'
  END;
























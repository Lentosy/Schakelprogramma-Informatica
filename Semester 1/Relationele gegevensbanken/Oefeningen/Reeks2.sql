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
  MAX(CASE WHEN finishaltitude BETWEEN    0 AND 1300 THEN 1 ELSE 0 END)
 + MAX(CASE WHEN finishaltitude BETWEEN 1301 AND 2150 THEN 1 ELSE 0 END)
 + MAX(CASE WHEN finishaltitude                > 2150 THEN 1 ELSE 0 END) "#"
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

-- 18.
SELECT hasc
FROM  Taalgebruik
GROUP BY hasc
HAVING
    sum(case when iso in ('eng','fra','spa') then 1 else -1 end) =3


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
  END,
  CASE 
    WHEN iso = 'ned' THEN 1
    WHEN iso = 'fra' THEN 2
    WHEN iso = 'dui' THEN 3
  END
ORDER BY 
  CASE 
    WHEN iso = 'ned' THEN 1
    WHEN iso = 'fra' THEN 2
    WHEN iso = 'dui' THEN 3
  END;

-- 24.
SELECT  lev1 regio, lev2 department,avg(elevation) gem, count(elevation) aant
FROM Cities
WHERE iso='FR'
    AND lev1 is not null AND lev2 is not null
GROUP BY rollup(lev1,lev2)
ORDER BY coalesce(lev1,'zz'), coalesce(lev2,'zz');

-- 25.
SELECT hasc, iso, ROUND(SUM(gebruik), 9) AS gebruik
FROM taalgebruik
WHERE hasc IN ('BE', 'FR', 'NL')
GROUP BY ROLLUP(hasc, iso)
ORDER BY hasc, iso;

-- 26.
SELECT 
  COALESCE(iso, ' ') as code,
  CASE GROUPING(iso) + GROUPING(lev1)
    WHEN 1 THEN '   totaal land ' || iso
    WHEN 2 THEN '   **totaal**'
    ELSE lev1
  END as loc,
 COUNT(1)
FROM cities
WHERE iso IN ('DE', 'FR')
GROUP BY ROLLUP(iso, lev1)
ORDER BY iso, lev1;

-- 27.
SELECT
  COALESCE(CASE
    WHEN richting(50.830, 4.330, latitude, longitude) < 45 OR richting(50.830, 4.330, latitude, longitude) > 315
      THEN 'noord'
    WHEN richting(50.830, 4.330, latitude, longitude) BETWEEN 45 AND 135 
      THEN 'oost'
    WHEN richting(50.830, 4.330, latitude, longitude) BETWEEN 136 AND 225
      THEN 'zuid'
    WHEN richting(50.830, 4.330, latitude, longitude) BETWEEN 226 AND 315
      THEN 'west'
  END, ' ') " ",
  COUNT(CASE WHEN elevation < 50 THEN 1 END) LAAG,
  COUNT(CASE WHEN elevation BETWEEN 50 AND 200 THEN 1 END) MIDDEN,
  COUNT(CASE WHEN elevation >= 200 THEN 1 END) HOOG,
  COUNT(elevation) TOTAAL
FROM regios
WHERE PARENT LIKE 'BE.__.__'
GROUP BY ROLLUP(CASE
    WHEN richting(50.830, 4.330, latitude, longitude) < 45 OR richting(50.830, 4.330, latitude, longitude) > 315
      THEN 'noord'
    WHEN richting(50.830, 4.330, latitude, longitude) BETWEEN 45 AND 135 
      THEN 'oost'
    WHEN richting(50.830, 4.330, latitude, longitude) BETWEEN 136 AND 225
      THEN 'zuid'
    WHEN richting(50.830, 4.330, latitude, longitude) BETWEEN 226 AND 315
      THEN 'west'
  END);
  
-- 28.
SELECT 
  CASE GROUPING(season)
    WHEN 1 THEN 'totaal aantal'
    ELSE 'season   ' || season || '                     '
  END AS "RESULT",
  COUNT(CASE discipline WHEN 'DH' THEN 1 END) AS "AFDALING",
  COUNT(CASE discipline WHEN 'SG' THEN 1 END) AS "SUPERG",
  COUNT(CASE discipline WHEN 'GS' THEN 1 END) AS "REUZESLALOM",
  COUNT(CASE discipline WHEN 'SL' THEN 1 END) AS "SLALOM",
  COUNT(CASE discipline WHEN 'KB' THEN 1 END) AS "COMBINATIE",
  COUNT(CASE gender WHEN 'M' THEN 1 END) AS "MAN",
  COUNT(CASE gender WHEN 'L' THEN 1 END) AS "VROUW",
  COUNT(gender) AS "TOTAAL",
  ROUND(COUNT(discipline) / COUNT(DISTINCT discipline),2) AS "GEMPERDISC"
FROM ranking
GROUP BY ROLLUP(season)
ORDER BY season;


-- 29.
SELECT 
  CASE
    WHEN GROUPING(hasc) = 1 THEN iso || ' wordt gesproken in ' || count(1) || ' landen'
    WHEN GROUPING(iso) = 1 THEN 'in ' || hasc || ' spreekt men ' || count(1) || ' talen'
  END AS " "
FROM Taalgebruik
WHERE gebruik > 0.02
GROUP BY CUBE(hasc,iso)
HAVING COUNT(1) >= 10
ORDER BY GROUPING(Hasc)

-- Naam student: 
--
-- Status implementatie: 
--
-- Te raadplegen tabellen: cities en synoniemen
--
-- Beperkingen:
--      - de oplossing moet bestaan uit één enkele SQL opdracht, eventueel
--        voorafgegaan door CTE's. het gebruik van PL/SQL is niet toegelaten
--      - samengestelde opdrachten (UNION, ...) zijn niet toegelaten
--      - gecorreleerde subqueries zijn niet toegelaten
--      - recursieve (hiërarchische) queries zijn niet toegelaten
--      - je mag enkel de standaard beschikbare vormen van analytische functies
--        (de van aggregaatsfuncties afgeleide reportingfuncties, en de ranking-
--        functies row_number, rank, dense_rank en ntile) gebruiken, niet de
--        Oracle-specifieke vormen ervan (zoals windowing of top clausules, lag,
--        lead, first, first_value, ...)
--  (!) - je mag GEEN ENKELE ANALYTISCHE FUNCTIE (functie met over-extentie)
--        gebruiken, ook niet de Oracle-specifieke vormen ervan (zoals windowing
--      - je mag geen gebruik maken van pseudokolommen zoals ROWNUM of ROWID.
--      - je mag geen gebruik maken van de PERCENTILE_CONT en MEDIAN functies.
-- 
-- Je moet nagenoeg dezelfde uitvoer krijgen als volgende query.
--
-- WITH X AS (...)
--  SELECT DISTINCT provincie
--        ,PERCENTILE_CONT(0.25) WITHIN GROUP(order by elevation) over(partition by provincie) "1e kwartiel"
--        ,MEDIAN(elevation) over(partition by provincie) "2e kwartiel"
--        ,PERCENTILE_CONT(0.75) WITHIN GROUP(order by elevation) over(partition by provincie) "3e kwartiel"
--        
--  FROM x
--  ORDER BY by 3
--
-- PROVINCIE       1e kwartiel 2e kwartiel 3e kwartiel                        
-- --------------- ----------- ----------- ----------- 
-- Antwerpen               6          13          18                           
-- West-Vlaanderen         6          15          25                     
-- Oost-Vlaanderen         3          11          37                    
-- Vlaams-Brabant         20          40          60                    
-- Limburg                35          47          73                             
-- Brussel                48.5        60.5        83           
-- Henegouwen             44          70         138  
-- Waals-Brabant          88         111         132                                      
-- Namen                 180         229         269                              
-- Luik                  154         230         342.25                              
-- Luxemburg             332.5       394         460                         
--
-- 11 rows selected 
--


WITH x AS (SELECT coalesce(lev2, lev1) provincie, elevation
           FROM cities
           WHERE elevation IS NOT NULL 
             AND iso = 'BE'
         )


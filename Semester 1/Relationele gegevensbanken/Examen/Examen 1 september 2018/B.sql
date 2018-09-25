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
--      - je mag geen gebruik maken van pseudokolommen zoals ROWNUM of ROWID.
--      - je mag enkel join(s) gebruiken bij het bepalen van de namen van de
--        meetpunten. Verder zal je beroep moeten doen op eventuele CTE's 
--        of analytische functies.
--
-- Geef voor elke provincie in België ( en het Brussels gewest ) de langste afstand
-- van een bepaald meetpunt tot het meetpunt met de hoogste populatie in
-- diezelfde provincie. Vertrek van onderstaande CTE.
--
-- PROVINCIE          X                        Y                 D
-- ------------------ -----------------------  ------------------ ----
-- Antwerpen          De Most                  Antwerpen          58.3 
-- Brussel            Zavelberg                Brussel            22.3 
-- Henegouwen         Ploegsteert              Charleroi          114.4 
-- Limburg            Housie                   Hasselt            49.6 
-- Luik               Ouren                    Liège              68.5 
-- Luxemburg          Barrière de Champlon     Arlon              93.8 
-- Namen              L'Hamais                 Namur              69.1 
-- Oost-Vlaanderen    Doel                     Gent               48.5 
-- Vlaams-Brabant     Rode                     Leuven             55.2 
-- Waals-Brabant      Linsmeau                 Braine-l'Alleud    44.9 
-- West-Vlaanderen    De Seule                 Brugge             63.3 

-- 11 rows selected 

with x as (select id, coalesce(lev2, lev1), population, latitude, longitude           
           from cities
           where iso = 'BE'
           )

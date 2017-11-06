--Virtualbox
--   => nieuwe VM aanmaken (Windows Server 2012 R2)
--   => Memory -> min 4GB
--   => vdi -> downloaden http://files.tiwi.be

--1. Toon alle gegevens van alle resorts.
SELECT * FROM resorts;
--2. Geef enkel de name en de nation van alle resorts.
SELECT name, nation FROM resorts;
--3. Geef de verschillende mogelijkheden weer van het veld gender
--   bij de tabel Races. Zorg voor een andere kolomtitel.
SELECT DISTINCT gender AS geslacht FROM races;
--4. Geef de verschillende disciplines weer welke voorkomen in
--   de tabel Ranking
SELECT DISTINCT discipline from ranking;
--5. Geef de naam en het gewicht van alle competitors, met daar
--   tussenin (in een aparte kolom) de tekst 'heeft als gewicht'
SELECT name, 'heeft als gewicht' , weight FROM competitors;
--6. Geef naam en gewicht van alle competitors weer als één
--   kolom, met naam en gewicht gescheiden door een spatie
SELECT name || ' ' || weight FROM competitors;


--7. Bereken met een sql opdracht 12% van 120. In Oracle kunnen we
--   de tabel dual gebruiken
SELECT 120 * 0.12 FROM dual;
--8. Kijk eens hoe de namen van de competitors zijn opgeslagen.
--   Geef van alle competitors de eerste letter van hun familienaam
--   in een hoofdletter weer, de rest van de familie naam in kleine 
--   letters (vb. Tomas Hermandez Vicente).
SELECT NLS_INITCAP(name) AS name FROM competitors;
--9. Geef de (verschillende) huidige leeftijden van alle competitors,
--  van oudste naar jongste. Voor de berekening van de leeftijd nemen
--  we het verschil tussen het huidige jaartal en het geboortejaar
SELECT name, ROUND((CURRENT_DATE - birthdate) / 365)
FROM competitors
ORDER BY birthdate ASC;
--10. Geef de namen en de geboortedatums van die competitors welke geboren
--    zijn in de maanden september of oktober, en geef deze in het
--    formaat waarbij de maand voluit geschreven wordt
--    (bijvoorbeeld 11 oktober 1996). Berpekt het resultaat tot
--    deze competitors welke een voornaam hebben die de substring
--    'bert' bevat. Orden volgens geboortedatum
SELECT name, birthdate 
FROM competitors
WHERE name LIKE '% %bert%'
AND EXTRACT(MONTH FROM birthdate) IN (9,10)
ORDER BY birthdate ASC;
--11. Geef de datum en de discipline van alle races welke doorgegaan
--    zijn in het resort Cortina d'Ampezzo, vanaf 1996 en voor het jaar 2000.
SELECT racedate, discipline 
FROM races
WHERE EXTRACT(YEAR FROM racedate) IN (1996, 1997, 1998, 1999)
AND resort = 'Cortina d''Ampezzo';
--12. Geef de verschillende resortnamen waar een wedstrijd
--    is doorgegaan met als discipline 'DH', 'KB' of 'SL'
SELECT DISTINCT resort
FROM races
WHERE discipline IN ('DH', 'KB', 'SL');
--13. Geef alle gegevens van die competitors welke een cid hebben
--    welke begint met 3. Orden ze aflopend volgens geboortedatum
--    en alfabetisch op naam.
SELECT *
FROM competitors
WHERE cid LIKE '3%'
ORDER BY birthdate DESC, name ASC;
--14. Geef de naam en geboortedatum + 1 maand van alle competitors 
--    waarvan de naam begint met VAN.
SELECT name, ADD_MONTHS(birthdate, 1) 
FROM competitors
WHERE name LIKE 'VAN%';
--15. Geef de weekdag van 01/01/2008 op verschillende manieren weer
--    (vb Woensdag, wo, Wo).
SELECT TO_DATE('01/01/2008') FROM dual;
--16. Op welke dag ben (of was) je precies 10000 dagen oud?
--    Geef ook op welke dag van de week dat valt/viel?
SELECT ROUND(CURRENT_DATE - TO_DATE('13/10/1995')) FROM dual;
--17. Geef de maand van vandaag op verschillende manieren 
--    weer (vb. SEPTEMBER SEP 09 ).
SELECT to_char(sysdate,'MONTH  MON MM ') FROM DUAL;

--18. Onderzoek volgende reguliere expressie. De ampersand & vraagt een waarde voor tekst. 
SELECT 'tekst voldoet aan regexp !' AS resultaat
FROM DUAL
WHERE regexp_like('&tekst','^.a{1,2}.+$','i');

--19. Zoek met REGEXP_INSTR naar de namen van competitors welke minsters vier
--    niet-lege substrings bevatten gescheiden door een spatie

--    NIET JUIST
SELECT name
FROM competitors
WHERE REGEX_INSTR(name, '[^[:space]]*[[:space:]]{3}[^[:space]]*') = 1;
--20. Gebruik REGEXP_SUBSTR om de birthplaces van de competitors weer te geven

--    NIET JUIST
--    welke in de birthplace-tekst een string tussen haakjes bevatten zoals bv. (ITA)
SELECT REGEXP_SUBSTR(birthplace, '.*\(.*\).*')
FROM competitors
WHERE birthplace IS NOT NULL



--21. Schrijf zelf een query met elk van de volgende functies: NULLIF, COALESCE, NVL, NVL2, DECODE
SELECT
	NVL(height, 0) AS height,
	NVL2(birthplace, 'V', 'X') as birthplace_known
	COALESCE(birthplace, nation) as birthplace
	DECODE(gender, 'M', 'Male', 'Female') as gender
FROM competitors

--22. Zoek op in de SQL Reference het verschil tussen MOD en REMAINDER
--    MOD gebruikt FLOOR in zijn formule, terwijl REMAINDER de functie ROUND gebruikt
-- Mod gebruikt FLOOR en REMAINDER ROUND

--23. Vervang de REMAINDER en MOD functies in volgende query, door andere functies en/of bewerkingen te gebruiken:
select finishaltitude
     ,(finishaltitude - (7*round(finishaltitude/7))) - REMAINDER(finishaltitude,7)
     ,(finishaltitude - (7*trunc(finishaltitude/7))) - MOD(finishaltitude,7)
from   Resorts
WHERE  finishaltitude is not NULL

--24. Zoek op in de SQL Reference: CREATE OR REPLACE FUNCTION. Schrijf vervolgens een functie cart_afstand,
--    om de afstand tussen twee punten (met cartesische coördinaten) te bepalen. Test ook uit.
CREATE OR REPLACE
FUNCTION CART_AFSTAND(x1 NUMBER, y1, NUMBER, x2 NUMBER, y2 NUMBER) RETURN NUMBER IS
BEGIN
	RETURN SQRT(POWER(x2 - x1, 2) + POWER(y2 - y1, 2))
END;

--25. Schrijf een functie full_name. Voorzie twee parameters voor de voornaam en de familienaam.
--    De functie moet de volledige naam teruggeven met formaat: 
--    familienaam, komma en spatie,voornaam en elke eerste lettter een hoofdletter 
CREATE OR REPLACE 
FUNCTION FULL_NAME (voornaam IN VARCHAR2, familienaam IN VARCHAR2) RETURN VARCHAR2 AS
BEGIN
	RETURN INITCAP(voornaam) || ', ' || INITCAP(familienaam);
END;


--26.
create or replace FUNCTION datumverschil(d1 date) RETURN VARCHAR2 AS
 jaren   number;
 dagen    number;
 d2 date;
BEGIN
     d2:= sysdate;
     jaren := trunc( months_between( d1, d2 ) / 12 );
     dagen  := floor(d2 - add_months( d1, jaren*12 ));
    RETURN 'jaren='||jaren|| ' en dagen='||dagen;
END ;


--27.
select  name
       ,extract(minute from time)*60+extract(second from time) as "tijd(sec)"
       ,width_bucket(extract(minute from time)*60 + extract(second from time),109.38,105.43,24)  as tijdsgroep
from results
where rid=9086
     and time is not null
order by time 


--28.
SELECT name,birthdate
from   competitors
where birthdate is not null and extract(day from birthdate+1)=1

--29.
SELECT name, substr(name,instr(name,' ',1,1)) voornaam
     FROM competitors
     WHERE 
     SOUNDEX(substr(name,instr(name,' ',1,1)))
       = SOUNDEX('Mariane')
 order by 2

--30.
SELECT  XMLElement("Belgen"
        ,XMLAgg(XMLElement("competitor"
                ,XMLAttributes(c.cid as "cid")
                , initcap(c.name)||' '||to_char(c.birthdate, 'dd-mon-yyyy'))
                order by c.birthdate
                )
                )
AS "RESULT"
FROM  Competitors c
WHERE gender='M' and  nation like 'BEL' and birthdate is not null



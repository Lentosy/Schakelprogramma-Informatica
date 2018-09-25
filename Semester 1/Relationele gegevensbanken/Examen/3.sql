-- Naam student: 
--
-- Status implementatie: 
--
-- Enige te raadplegen tabel: ranking
--
-- Beperkingen:
--      - de oplossing moet bestaan uit ��n enkele SQL opdracht, eventueel
--        voorafgegaan door CTE's. het gebruik van PL/SQL is niet toegelaten
--      - samengestelde opdrachten (UNION, ...) zijn niet toegelaten
--      - gecorreleerde subqueries zijn niet toegelaten
--      - recursieve (hi�rarchische) queries zijn niet toegelaten
--  (!) - je mag GEEN ENKELE ANALYTISCHE FUNCTIE (functie met over-extentie)
--        gebruiken, ook niet de Oracle-specifieke vormen ervan (zoals windowing
--        of top clausules, lag, lead, first, first_value, ...).
--      - je mag geen gebruik maken van pseudokolommen zoals ROWNUM of ROWID.
--
-- Bereken in eerste instantie het totaal aantal wereldbekerpunten, over alle
-- disciplines heen, die elke skiester in elk seizoen (vanaf 1993) verzameld
-- heeft. Voeg vervolgens een kolom toe, die aangeeft in welke discipline(s)
-- elke skiester in elk seizoen de meeste punten verzameld heeft. Je mag
-- hierbij de identificaties van de disciplines ('DH', 'SG', 'GS', 'SL' en 'KB')
-- hardcoderen.
-- Voeg tenslotte een kolom toe die voor elke skiester in elk seizoen het
-- cumulatieve totaal (het aantal wereldbekerpunten vanaf 1993 en tot en met
-- dat seizoen) berekent. 
-- Beperk de uitvoer tot skiesters die, over alle disciplines en seizoenen
-- (vanaf 1993) heen, in totaal minstens 2850 punten verzameld hebben.
--
-- Het script moet volgend resultaat reproduceren:
--
--        NAME                 SEASON  POINTS  BEST   TOTAAL
--        -------------------- ------  ------  -----  ------
--        . . .		
--        FENNINGER Anna        2007     15    GS       15
--        FENNINGER Anna        2008     83    KB       98
--        FENNINGER Anna        2009    338    SG      436
--        FENNINGER Anna        2010    260    SG      696
--        FENNINGER Anna        2011    555    DH     1251
--        FENNINGER Anna        2012    994    GS     2245
--        FENNINGER Anna        2013   1029    GS     3274
--        . . .		
--        HOSP Nicole           2002      2    GS        2
--        HOSP Nicole           2003    558    GS      560
--        HOSP Nicole           2004    566    SL     1126
--        HOSP Nicole           2005    492    GS     1618
--        HOSP Nicole           2006   1112    GS     2730
--        HOSP Nicole           2007   1572    GS     4302
--        HOSP Nicole           2008   1183    SL     5485
--        HOSP Nicole           2009    496    SL     5981
--        HOSP Nicole           2011    454    SL     6435
--        HOSP Nicole           2012    367    KB     6802
--        HOSP Nicole           2013    423    SL     7225
--        . . .		
--        SCHUSTER Stefanie     1993    226    DH      226
--        SCHUSTER Stefanie     1994     90    DH/SG   316
--        SCHUSTER Stefanie     1995    212    DH      528
--        SCHUSTER Stefanie     1996    215    SG      743
--        SCHUSTER Stefanie     1997    397    DH     1140
--        SCHUSTER Stefanie     1998    500    GS     1640
--        SCHUSTER Stefanie     1999    148    SG     1788
--        SCHUSTER Stefanie     2000    536    DH     2324
--        SCHUSTER Stefanie     2001    223    SG     2547
--        SCHUSTER Stefanie     2002    323    SG     2870
--        . . .		
--        WACHTER Anita         1993   1286    GS     1286
--        WACHTER Anita         1994   1057    GS     2343
--        WACHTER Anita         1995    593    GS     2936
--        WACHTER Anita         1996   1044    GS     3980
--        WACHTER Anita         1997    741    GS     4721
--        WACHTER Anita         1998    274    GS     4995
--        WACHTER Anita         1999    756    GS     5751
--        WACHTER Anita         2000    546    GS     6297
--        WACHTER Anita         2001    118    GS/SL  6415
--        . . .		
--        

SELECT   name, season, points
FROM     Ranking
WHERE    season >= 1993
         AND gender = 'L'

-- 2.
with dagen as (select     to_date('31-12-2012', 'dd-mm-yyyy') + level dag
               from       dual
               connect by level < 366)
               
select   extract(year from dag) as jaar,
         extract(month from dag) as mnd,
         count( case to_char(dag, 'd') when '7' then 1 end) zondagen
         from dagen
group by extract(year from dag),
         extract(month from dag)
order by mnd;



-- 3.
with maanden as (select     level maand
                 from       dual
                 connect by level <= 12)
select maand, count(racedate) as "#RACES"
from maanden
left join races on extract(month from racedate) = maand
group by maand
order by maand;



-- 4.
with x as ( select Regios.name land,Synoniemen.name
                  ,row_number() over (partition by eid order by dup) aantal
                  ,count(1) over (partition by eid) totaal
            from Synoniemen 
            join Regios on eid=cid and parent='EUR'
          )
select *
from x;
Select land,ltrim(sys_connect_by_path(name,';'),';') namen
from   x
where level = totaal
start with aantal = 1
connect by prior land = land 
       and prior aantal = aantal - 1;

-- 5.
with eu as (select r.name as land, 
                   k.taal as taal, 
                   rank() over(partition by r.hasc order by t.gebruik desc) as rank,
                   count(1) over(partition by r.hasc) as aantal
            from   regios r
            join   taalgebruik t on r.hasc = t.hasc
            join   talen k on t.iso = k.iso
            where  r.parent = 'EUR')
select land, ltrim(sys_connect_by_path(taal,';'),';') taalgebruik
from eu
where level = aantal
start with rank = 1
connect by prior land = land
      and prior rank = rank - 1
order by land, rank;

-- 6.
-- Oplossing met start with en connect by
select     hasc, name, niveau, level
from       regios
start with hasc like 'BE.OV.GT'
connect by prior hasc = parent
order by   hasc;


-- Oplossing met recursive subquery factoring
with s(hasc, name, nivea, lvl) as (
                       select hasc, name, niveau, 1 lvl
                       from   regios
                       where  hasc = 'BE.OV.GT'
                       union all
                       select r2.hasc, r2.name, niveau, lvl + 1
                       from   regios r2, s
                       where  r2.parent = s.hasc)
select *
from s;


-- 7.
-- Oplossing met start with en connect by
select name, niveau , level
from   regios
start with name = 'Melle'
connect by prior parent = hasc;

-- Oplossing met recursive subquery factoring
with s(name, niveau, lvl, parent) as (select name, niveau, 1 lvl, parent
                                      from   regios
                                      where  name = 'Melle'
                                      union all
                                      select r2.name, r2.niveau, lvl + 1, r2.parent
                                      from   regios r2 join s on r2.hasc = s.parent)
select name, niveau, lvl
from   s;



-- 8.
-- Oplossing met start with en connect by
select     hasc, niveau, level, CONNECT_BY_ISLEAF as blad
from       regios
start with hasc = 'BE'
connect by prior parent = hasc;
-- Oplossing met recursive subquery factoring
with r1(hasc, niveau, lvl, blad, parent) 
     as (select hasc, niveau, 1 lvl, 0 blad, parent
         from regios
         where hasc = 'BE'
         union all
         select r2.hasc, r2.niveau, lvl + 1, 1, r2.parent
         from regios r2 join r1 on r2.hasc = r1.parent)
select hasc, niveau, lvl, blad
from r1;

-- 9.
-- Oplossing met start with en connect by
select hasc, name, niveau, level, CONNECT_BY_ISLEAF
from regios
start with hasc='BE.OV.GT'
connect by prior hasc = parent;
-- Oplossing met recursive subquery factoring
with s(hasc, name, niveau, lvl, blad, parent) as (select hasc, name, niveau, 1 lvl, 0 blad, parent
                                            from regios
                                            where hasc = 'BE.OV.GT'
                                            union all
                                            select r2.hasc, r2.name, r2.niveau, lvl + 1, 1, r2.parent
                                            from regios r2 join s on r2.parent = s.hasc)
select hasc, name, niveau, lvl, blad
from s;



-- 10.
select LPAD('.', 10 * (level - 1), '.') ||name||'('||hasc||')' as "Oost-Vlaanderen"
from regios
start with hasc = 'BE.OV'
connect by prior hasc = parent;




-- 11.
-- Oplossing met start with en connect by
with x as(select name, ltrim(sys_connect_by_path(name, '/'),'/') as ouders, level as lvl
          from regios
          start with hasc = 'BE'
          connect by prior hasc = parent)
select name, ouders, lvl || '  België'
from x
where lvl >= 4;


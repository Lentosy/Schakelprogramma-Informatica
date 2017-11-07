-- 2.
with x as(select   lev2,
         min(elevation) as laagstehoogte , 
         max(elevation) as maxhoogte
from     cities
where    iso = 'BE' and lev2 is not null
group by lev2)
select lev2, maxhoogte, laagstehoogte, maxhoogte - laagstehoogte as hoogteverschil
from x
order by hoogteverschil;


-- 3.
 with g as (select   hasc1,hasc2 from Grenzen where hasc1 like 'BE.%'
                       union all
           select   hasc2,hasc1 from Grenzen where hasc2 like 'BE.%')
    ,x as (select   hasc1,hasc2,count(1) over(partition by hasc1) aantal
           from     g )
    ,y as (select   hasc1,hasc2
           from     x
           where    aantal>=10 )
select   p.name,q.name,rank() over(partition by p.name order by q.name) " "
from     y
    join regios p on hasc1=p.hasc
    join regios q on hasc2=q.hasc
order by p.name,q.name;


-- 4.
with 
x as ( select gender, discipline, name, rank() over (partition by gender, discipline order by points desc) rank 
       from   ranking
       where  season = 2007)
select   gender, discipline,
         max(case rank when 1 then name end) as "1",
         max(case rank when 2 then name end) as "2",
         max(case rank when 3 then name end) as "3"
from     x
group by gender, discipline
order by gender, discipline


-- 5.
with x as (
    select   extract(year from racedate + 183) seizoen, discipline, count(1) as totaal
    from     races
    where    extract(year from racedate + 183) >= 1999
      and    discipline in ('DH', 'SG', 'GS', 'SL')
    group by cube(extract(year from racedate + 183), discipline))
select case 
        when seizoen is null then 'totaal' 
        else cast(seizoen as char(4))
       end as seizoen,
       sum(case when discipline = 'DH' then totaal else 0 end) as DH,
       sum(case when discipline = 'SG' then totaal else 0 end) as SG,
       sum(case when discipline = 'GS' then totaal else 0 end) as GS,
       sum(case when discipline = 'SL' then totaal else 0 end) as SL,
       sum(case when discipline is null then totaal else 0 end) totaal
from x
group by seizoen
order by seizoen;


-- 6.
with maanden as ( select 1 as maandnr from dual
                union all
               select 2 from dual
                union all
               select 3 from dual
                union all
               select 4 from dual
                union all
               select 5 from dual
                union all
               select 6 from dual
                union all
               select 7 from dual
                union all
               select 8 from dual
                union all
               select 9 from dual
                union all
               select 10 from dual
                union all
               select 11 from dual
                union all
               select 12 from dual),
     geslachten as ( select 'M' as geslacht from dual union all select 'L' from dual),
     resultaten as ( select gender, cast(to_char(racedate, 'mm') as int) maand
                     from   races ra
                       join results re on re.rid = ra.rid
                       union all
                     select *
                     from geslachten, maanden )
select   maand,
         sum(case when gender = 'L' then 1 end) - 1 as "L",
         sum(case when gender = 'M' then 1 end) - 1 as "M",
         sum(1) - 2 as "#"
from     resultaten
group by maand
order by maand;


-- 7.
with x as (select   distinct coalesce(lev2, lev1) as provincie,
                             elevation
                    from     cities
                    where    iso = 'BE'
                      and    lev2 is not null
                      and    lev2 is not null
                    order by elevation desc)
, y as (select provincie, elevation,
                      avg(elevation) over(partition by provincie) avg ,
                      2 * row_number() over (partition by provincie order by elevation)
                      -1 - count(1) over(partition by provincie) med
               from x)
, z as (select provincie, elevation, avg
        from   y
        where med between -1 and 1)
select provincie, round(avg(avg), 2), avg(elevation) mediaan
from z
group by provincie
order by 2;


-- 8.
with x as (
      select   lev1, lev2, max(elevation) as hoogste
      from     cities
      where    iso = 'BE'
        and    elevation is not null
        and    lev1      is not null
        and    lev2      is not null
      group by lev1, lev2
      order by max(elevation))
, y as (select lev1, lev2, hoogste, min(hoogste) over(partition by lev1) as laagste 
        from x
        )
, z as (select lev1, lev2, hoogste - laagste as verschil
        from y)
select case verschil when 0 then lev1 else ' ' end as gewest,
       lev2,
       verschil
from z
order by lev1, verschil;


-- 9.
with x as (SELECT r.parent,r.hasc,r.name,r.area ,m.afkorting
           FROM   regios  r 
           JOIN   members m ON r.hasc=m.hasc
           WHERE  m.afkorting IN ( 'G-3','G-5','G-6','G-7','G-8'))
           
,    y as (select   parent, name, area,
                    rank() over(partition by parent order by area desc) seq,
                    count(afkorting) "#",
                    max(case when afkorting = 'G-3' then 'X' else ' ' end) as "G-3",
                    max(case when afkorting = 'G-5' then 'X' else ' ' end) as "G-5",
                    max(case when afkorting = 'G-6' then 'X' else ' ' end) as "G-6",
                    max(case when afkorting = 'G-7' then 'X' else ' ' end) as "G-7",
                    max(case when afkorting = 'G-8' then 'X' else ' ' end) as "G-8"
           from     x
           group by parent, name, area)
select case when seq = 1 then to_char( parent) else ' ' end as "parent",
         name, area, "#", "G-3", "G-5", "G-6", "G-7", "G-8"
from y
order by parent, area desc;


-- 10.
with x as (select iso, elevation, elevation - dense_rank() over(partition by iso order by elevation) groep
           from cities
           where iso = 'IS')
select *
from x;
select min(elevation) elevation, case when max(elevation) = min(elevation) then ' ' else cast(max(elevation) as char(4)) end as "             "
from x
group by groep, iso
order by elevation


-- 11.
with x as(select b.name as provincie,
                 a.name as arrondissement,
                 c.population as stadpop,
                 c.elevation stadelev,
                 case when c.population = max(c.population) over(partition by a.parent) then c.elevation end as maxelev
          from   regios a
            join cities c on a.cid = c.id
          join   regios b on a.parent = b.hasc
          where  b.parent like 'BE.VL%')
,    y as (select provincie, arrondissement, stadpop, stadelev, max(maxelev) over(partition by provincie) as hoogste
           from   x)
,    z as (select provincie, arrondissement, stadpop, stadelev, stadelev - hoogste as verschil, row_number() over(partition by provincie order by stadelev) as seq
           from   y)
select case seq
        when 1 then to_char(provincie)
        else ' '
       end as provincie, 
       arrondissement, stadpop, stadelev, verschil
from   z
where seq <= 3;




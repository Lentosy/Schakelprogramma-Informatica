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


with x as (
select    hasc1, count(hasc2) as aantal
from     grenzen
where    hasc1 like 'BE%'
group by hasc1)
,y as(
  select *
  from regios

)

select *
from x,y;

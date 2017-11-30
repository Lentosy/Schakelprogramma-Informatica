-- 1.
-- MET SCALAIRE SUBQUERIES
select name,
       nation,
       (select   count(1) 
        from     ranking r 
        where    c.name = r.name 
        group by name
        having count(1) > 40) aantranking,

       (select   count(1) 
        from     ranking r 
        where    c.name = r.name 
             and r.discipline = 'SL'
        group by name
        having count(1) > 10) aantslalom
from competitors c
where (select   count(1) 
        from     ranking r 
        where    c.name = r.name 
        group by name
        having count(1) > 40) is not null
  and (select   count(1) 
        from     ranking r 
        where    c.name = r.name 
             and r.discipline = 'SL'
        group by name
        having count(1) > 10) is not null 
order by aantranking;


-- MET JOINS
select   c.name, c.nation,
	 count(1) as aantranking,
	 count(case when r.discipline = 'SL' then 1 end) as aantslalom
from     competitors c
  join   ranking r on c.name = r.name
group by c.name, c.nation
having   count(1) > 40
   and   count(case when r.discipline = 'SL' then 1 end) > 10
order by c.nation;




-- 2.
select   x.parent, x.name, x.capital, x.population,
         round(100.* population / (select sum(y.population)
                                   from regios y
                                   where x.parent = y.parent
                                   group by x.parent), 2)  "t.o.v. regio",
         round(100. * population / (select sum(population)
                                    from regios
                                    where parent like 'FR._'
                                    ),2) "t.o.v. land",
         x.area,
         x.elevation
from     regios x
where    x.parent like 'FR._'
order by x.parent, x.name;



-- 3.
select x.name, x.nation, x.finishaltitude
from resorts x
where x.finishaltitude is not null
  and (select avg(finishaltitude)
       from resorts y
       where finishaltitude is not null and x.nation = y.nation
       group by nation) < x.finishaltitude;


-- 4.
-- MET EEN SUBQUERY IN DE WHERE TODOTODOTODO
select   name, weight
from     competitors x
where    gender = 'M'
  and    weight is not null
  
          
order by weight desc;


-- MET EEN JOIN
select   x.name, x.weight
from     competitors x
  join   competitors y on x.name <> y.name
                      and y.weight is not null
                      and y.gender = 'M'
where    x.weight is not null
   and   x.gender = 'M'
group by x.name, x.weight
having   count(case when x.weight < y.weight then 1 end) < 5
order by weight desc;

-- MET EEN CTE en rank()
with x as(select name, weight, rank() over(partition by gender order by weight desc) rank
          from   competitors
          where  weight is not null
             and gender = 'M')
select name, weight
from x
where rank <= 5;



-- 8. TODO : enkel de drie grootste
with y as (select hasc1, hasc2, length
           from   grenzen
           where  length is not null
             and  (select parent
                   from   regios
                   where  hasc1 = hasc) = 'EUR'
           union 
           select hasc2, hasc1, length
           from   grenzen
           where  length is not null
             and  (select parent
                   from   regios
                   where  hasc1 = hasc) = 'EUR')
select (select name 
        from   regios 
        where  hasc1 = hasc) as hasc1
      ,(select name 
        from   regios 
        where  hasc2 = hasc) as hasc2
      ,length
      ,length - (select max(length) 
        from   y x 
        where  y.hasc1 = x.hasc1 
          and  length is not null 
        group by x.hasc1)  as verschil
from y y
order by hasc1, verschil desc;

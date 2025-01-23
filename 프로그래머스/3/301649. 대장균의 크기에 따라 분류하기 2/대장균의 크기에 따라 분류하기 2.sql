with T as(
    select id, percent_rank() over(order by size_of_colony desc) as per
    from ecoli_data
)
select E.id, 
    case 
        when per <= 0.25 then "CRITICAL"
        when per <= 0.5 then "HIGH"
        when per <= 0.75 then "MEDIUM"
        else "LOW"
    end as COLONY_NAME
from ecoli_data E
join T on T.id = E.id
order by e.id
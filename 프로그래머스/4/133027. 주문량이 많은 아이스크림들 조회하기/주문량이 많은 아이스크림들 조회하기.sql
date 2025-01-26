with A as(
    select *
    from first_half F
    union all
    select * 
    from july J
)

select flavor
from A
group by flavor
order by sum(total_order) desc
limit 3
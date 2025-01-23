with recursive hours as (
    select 0 as hour
    union all
    select hour+1
    from hours
    where hour<23
)

select H.hour, count(hour(A.datetime)) as count
from hours H
left join animal_outs A on hour(A.datetime) = H.hour
group by H.hour

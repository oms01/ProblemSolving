with recursive T as(
    select id, parent_id, 1 as generation
    from ecoli_data
    where parent_id is null
    
    union all
    
    select C.id, C.parent_id, P.generation + 1 as generation
    from ecoli_data C
    join T P on C.parent_id = P.id
)

select count(*) as count, generation
from T
where id not in(
    select parent_id
    from T
    where parent_id is not null
)
group by generation
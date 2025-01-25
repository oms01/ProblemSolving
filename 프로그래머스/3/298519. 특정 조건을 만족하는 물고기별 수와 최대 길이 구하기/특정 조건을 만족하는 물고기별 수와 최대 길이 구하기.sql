with T as(
    select id, fish_type, 
        case
            when length is null then 10
        else length
        end as length
    from fish_info
)


select fish_count, max_length, fish_type
from (
    select avg(length) avglen, fish_type, count(fish_type) fish_count, max(length) max_length, min(length) min_length
    from T
    group by fish_type
) A
where avglen >= 33
order by fish_type
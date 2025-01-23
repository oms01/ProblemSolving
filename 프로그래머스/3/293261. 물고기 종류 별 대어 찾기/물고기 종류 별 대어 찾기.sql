with MX as(
    select fish_type, max(length) as length
    from fish_info
    group by fish_type
)

select id, fish_name, length
from fish_info I
join fish_name_info N on I.fish_type = N.fish_type
where (N.fish_type, length) in (select * from MX)

select count(I.fish_type) fish_count, N.fish_name
from fish_info I
join fish_name_info N on I.fish_type = N.fish_type
group by N.fish_name
order by fish_count desc
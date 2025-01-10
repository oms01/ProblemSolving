select distinct(D.id), D.email, D.first_name, D.last_name
from developers D, skillcodes S
where S.name in ('Python','C#') and
    D.skill_code & S.code != 0
order by 1
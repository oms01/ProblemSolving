with A as(
    select sum(score) score, E.emp_no, E.emp_name, E.position, E.email
    from hr_grade G
    join hr_employees E on E.emp_no = G.emp_no
    where year = 2022
    group by emp_no
)
select *
from A
where score = (
    select max(score) from A
)
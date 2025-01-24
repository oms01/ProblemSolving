select E.dept_id, D.dept_name_en, round(avg(E.sal)) avg_sal
from hr_employees E
join hr_department D on D.dept_id = E.dept_id
group by E.dept_id
order by avg_sal desc
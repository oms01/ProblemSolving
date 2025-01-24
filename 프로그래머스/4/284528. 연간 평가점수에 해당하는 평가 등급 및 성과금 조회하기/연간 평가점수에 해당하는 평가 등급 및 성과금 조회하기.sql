select emp_no, emp_name,
    case
        when score >= 96 then 'S'
        when score >= 90 then 'A'
        when score >= 80 then 'B'
        else 'C'
    end as grade,
    case 
        when score >= 96 then sal * 0.2
        when score >= 90 then sal * 0.15
        when score >= 80 then sal * 0.1
        else sal * 0 
    end as bonus
from (
    select G.emp_no, avg(G.score) score, E.emp_name, E.sal
    from hr_grade G
    join hr_employees E on G.emp_no = E.emp_no
    group by emp_no
) as A
order by emp_no
select YEAR(OS.sales_date) as YEAR, MONTH(OS.sales_date) as MONTH, GENDER, count(distinct UI.user_id) as USERS
from online_sale as OS
join user_info as UI on UI.user_id = OS.user_id
where UI.gender is not null
group by YEAR, MONTH, GENDER
order by YEAR, MONTH, GENDER
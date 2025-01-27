select year(O.sales_date) as year, month(O.sales_date) as month,
    count(distinct O.user_id) as purchased_users,
    round((count(distinct O.user_id))/(select count(*) from user_info where year(joined)=2021),1) as purchased_ratio
from online_sale O
join user_info I on I.user_id = O.user_id
where O.user_id in (
    select user_id
    from user_info
    where year(joined) = 2021
)
group by year, month
order by year, month
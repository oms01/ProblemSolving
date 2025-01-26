select P.product_id, P.product_name, sum(O.amount)*P.price as total_sales
from food_product P
join food_order O on P.product_id = O.product_id 
where produce_date like '2022-05%'
group by O.product_id
order by sum(O.amount)*P.price desc, P.product_id
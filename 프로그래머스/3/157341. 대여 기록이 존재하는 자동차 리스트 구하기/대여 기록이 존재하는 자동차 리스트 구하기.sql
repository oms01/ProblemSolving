select distinct C.car_id
from car_rental_company_car C
join car_rental_company_rental_history H on H.car_id = C.car_id
where C.car_type = '세단' and month(H.start_date) = 10
order by 1 desc
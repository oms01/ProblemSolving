select C.car_id, C.car_type, round(C.daily_fee*30*(100-D.discount_rate)/100,0) as fee
from car_rental_company_car C
join car_rental_company_discount_plan D on C.car_type = D.car_type
where D.duration_type like '30%'
    and C.car_type in ('세단', 'SUV')
    and C.car_id not in (
        select car_id
        from car_rental_company_rental_history
        where (start_date < '2022-11-30' and end_date > '2022-11-01')
    )
    and (500000 <= C.daily_fee*30*(100-D.discount_rate)/100 and C.daily_fee*30*(100-D.discount_rate)/100 < 2000000)
order by fee desc, C.car_type asc, C.car_id desc

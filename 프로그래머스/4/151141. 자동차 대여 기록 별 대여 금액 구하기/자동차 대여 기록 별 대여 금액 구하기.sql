select R.history_id,
    case when D.duration_type is null then round((datediff(R.end_date,R.start_date)+1) * C.daily_fee)
        else round((datediff(R.end_date,R.start_date)+1)*(C.daily_fee*(1-D.discount_rate/100)))
    end fee
from car_rental_company_rental_history R
join car_rental_company_car C on R.car_id = C.car_id and C.car_type = '트럭'
left join car_rental_company_discount_plan D on D.car_type = C.car_type
    and case
            when datediff(R.end_date,R.start_date)+1 >= 90 then D.duration_type = '90일 이상'
            when datediff(R.end_date,R.start_date)+1 >= 30 then D.duration_type = '30일 이상'
            when datediff(R.end_date,R.start_date)+1 >= 7 then D.duration_type = '7일 이상'
        end
order by 2 desc, 1 desc

# select R.history_id, C.car_id,datediff(end_date+1,start_date),
#     case    
#         when datediff(end_date+1,start_date) >= 90 then '90일 이상'
#         when datediff(end_date+1,start_date) >= 30 then '30일 이상'
#         when datediff(end_date+1,start_date) >= 7 then '7일 이상'
#         else null
#     end duration
# from car_rental_company_car C
# join car_rental_company_rental_history R on R.car_id = C.car_id
# join car_rental_company_discount_plan D on D.car_type = C.car_type
# where C.car_type = '트럭'
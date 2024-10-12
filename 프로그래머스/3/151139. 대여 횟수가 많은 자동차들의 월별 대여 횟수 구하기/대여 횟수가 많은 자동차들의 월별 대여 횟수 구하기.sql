-- 코드를 입력하세요
SELECT MONTH, CAR_ID, RECORDS
from (
    select month(start_date) as MONTH, car_id as CAR_ID, count(car_id) as RECORDS
    from car_rental_company_rental_history
    where start_date between '2022-08-01' and '2022-10-31'
        and car_id in (
            select car_id
            from car_rental_company_rental_history
            where start_date between '2022-08-01' and '2022-10-31'
            group by car_id
            having count(car_id)>=5
        )
    group by MONTH, CAR_ID
) as R
order by MONTH asc, CAR_ID desc
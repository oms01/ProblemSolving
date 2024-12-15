select I.rest_id, I.rest_name, I.food_type, I.favorites, I.address, round(avg(R.review_score),2) score
from rest_info I
join rest_review R on I.rest_id = R.rest_id
where address like '서울%'
group by I.rest_id
order by score desc, I.favorites desc;

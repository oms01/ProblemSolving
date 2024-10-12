# select category, max(price), product_name
# from food_product
# where category in ('과자','국','김치','식용유')
# group by category
# order by price desc

select CATEGORY, price as MAX_PRICE, PRODUCT_NAME
from food_product
where (price, category) in (
        select max(price), category
        from food_product
        group by category
    ) and category in ('과자','국','김치','식용유')
order by price desc
    
# select product_name, category, price
# from food_product
# where category in ('과자','국','김치','식용유')
# 1. 카테고리별 최대 가격 구하기
# 2. 최대가격의 id구하기

# select category, max(price), product_name
# from food_product
# where category in ('과자','국','김치','식용유')
# group by category
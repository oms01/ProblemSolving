select ingredient_type, sum(TOTAL_ORDER)
from (
        select FH.flavor, sum(total_order) as TOTAL_ORDER, II.ingredient_type
        from FIRST_HALF as FH
        join ICECREAM_INFO as II on FH.flavor = II.flavor
        group by FH.flavor
    ) as T
group by ingredient_type
select U.user_id, U.nickname, concat(U.city, ' ', street_address1, ' ', street_address2) 전체주소, 
    concat(substring(U.tlno,1,3), '-', substring(U.tlno,4,4), '-', substring(U.tlno,8,4)) 전화번호
from (
    select * ,count(*) as c
    from used_goods_board B
    join used_goods_user U on B.writer_id = U.user_id
    group by U.user_id
) U
where c >= 3
order by U.user_id desc
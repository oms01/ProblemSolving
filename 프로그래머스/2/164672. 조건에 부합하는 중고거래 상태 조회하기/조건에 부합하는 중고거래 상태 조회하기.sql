select board_id, writer_id, title, price,
    case
        when status = 'done' then '거래완료'
        when status = 'reserved' then '예약중'
        else '판매중'
    end as status
from used_goods_board
where created_date = '2022-10-05'
order by board_id desc
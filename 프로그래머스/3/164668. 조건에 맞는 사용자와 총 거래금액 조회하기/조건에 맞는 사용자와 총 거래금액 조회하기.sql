select UU.user_id, UU.nickname, sum(price)
from used_goods_board as UB
join used_goods_user as UU on UU.user_id = UB.writer_id
where status = 'DONE'
group by UB.writer_id
having sum(price) >= 700000
order by sum(price)
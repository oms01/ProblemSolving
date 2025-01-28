select concat('/home/grep/src/',F.Board_id,'/', F.file_id, F.file_name, F.file_ext) as file_path
from used_goods_board B
join used_goods_file F on F.board_id = B.board_id
where B.board_id = (
    select board_id
    from used_goods_board
    order by views desc
    limit 1
)
order by F.file_id desc
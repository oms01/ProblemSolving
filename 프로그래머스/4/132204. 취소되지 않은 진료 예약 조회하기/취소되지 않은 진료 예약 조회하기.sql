select A.apnt_no, P.pt_name, P.pt_no, A.mcdp_cd, D.dr_name, A.apnt_ymd
from appointment A
join patient P on A.pt_no = P.pt_no
join doctor D on D.dr_id = A.mddr_id
where A.apnt_ymd like '2022-04-13%'
    and A.apnt_cncl_yn = 'N'
    and A.mcdp_cd = 'CS'
order by A.apnt_ymd asc
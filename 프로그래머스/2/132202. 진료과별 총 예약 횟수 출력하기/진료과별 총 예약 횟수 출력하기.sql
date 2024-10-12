
select MCDP_CD as "진료과 코드", count(*) as '5월예약건수'
from APPOINTMENT
where apnt_ymd like '2022-05-%'
group by MCDP_CD
order by count(*), mcdp_cd
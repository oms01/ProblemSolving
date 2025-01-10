select l3.id
from ecoli_data l3
join ecoli_Data l2 on l3.parent_id = l2.id
join ecoli_Data l1 on l2.parent_id = l1.id
where l1.parent_id is null
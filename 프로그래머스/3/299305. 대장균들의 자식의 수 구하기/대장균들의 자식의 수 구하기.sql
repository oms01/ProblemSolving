select E.id,
    (select count(*)
    from ecoli_data
    where E.id = parent_id) child_count
from ecoli_data E

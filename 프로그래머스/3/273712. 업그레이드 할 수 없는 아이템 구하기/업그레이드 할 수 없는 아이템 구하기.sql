select I.item_id, I.item_name, I.rarity
from item_info I
where I.item_id not in (
    select parent_item_id
    from item_tree
    where parent_item_id is not null
)
order by 1 desc

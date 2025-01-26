select I.animal_id, I.name
from animal_ins I
join animal_outs O on I.animal_id = O.animal_id
where I.datetime > O.datetime
order by I.datetime
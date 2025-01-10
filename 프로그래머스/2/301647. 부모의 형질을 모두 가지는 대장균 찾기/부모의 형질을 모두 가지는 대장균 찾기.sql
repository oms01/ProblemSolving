select C.id, C.genotype, P.genotype parent_genotype
from ecoli_data C
join ecoli_data P on C.parent_id = P.id
where P.genotype & C.genotype = P.genotype
order by C.id
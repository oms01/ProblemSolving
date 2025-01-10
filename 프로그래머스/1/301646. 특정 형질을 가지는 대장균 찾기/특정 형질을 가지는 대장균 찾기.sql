select count(*) as count
from ecoli_data
where (genotype & 4 = 4 or genotype & 1 = 1) and genotype & 2 != 2
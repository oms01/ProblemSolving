with MX as (
    select year(differentiation_date) as year, max(size_of_colony) as size
    from ecoli_data
    group by(year(differentiation_date))
)

select year(differentiation_date) as year, abs(MX.size - E.size_of_colony) as year_dev, E.id as id
from ecoli_data E
join MX on year(E.differentiation_date) = MX.year
order by year, year_dev
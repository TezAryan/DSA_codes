# Write your MySQL query statement below
select 
Department , Employee , salary
from ( 
    select
    d.name as department,
    e.name as Employee,
    e.salary as Salary,
 DENSE_RANK() OVER(
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS rnk 
    from Employee e 
    join Department d
    on e.departmentId = d.id
) t
where rnk <= 3;

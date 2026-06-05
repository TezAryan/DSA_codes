# Write your MySQL query statement below

select 
round ( 
    avg(d.order_date = d.customer_pref_delivery_date) * 100 , 2)
    as immediate_percentage 
    from delivery d
    join (
select customer_id , MIN(order_date) AS first_order
from delivery 
group by customer_id 
) f 
on d.customer_id = f.customer_id
and d.order_date = f.first_order;

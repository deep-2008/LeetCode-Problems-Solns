# Write your MySQL query statement below
select Products.product_id, 'store1' as store, Products.store1 as price
from Products
where Products.store1 is not null

union all

select Products.product_id, 'store2' as store, Products.store2 as price
from Products
where Products.store2 is not null

union all

select Products.product_id, 'store3' as store, Products.store3 as price
from Products
where Products.store3 is not null

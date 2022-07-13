# Write your MySQL query statement below
select Person.email
from Person
group by (Person.email)
having count(Person.email)>1;
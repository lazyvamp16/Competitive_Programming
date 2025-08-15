# Write your MySQL query statement below
SELECT 
IF( 
    (SELECT count(DISTINCT salary) from Employee) <2, null,
    (
        SELECT DISTINCT SALARY 
        FROM Employee
        ORDER BY salary desc
        LIMIT 1 OFFSET 1
    )
)
AS SecondHighestSalary;





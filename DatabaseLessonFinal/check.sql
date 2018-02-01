DROP PROCEDURE IF EXISTS check_income;
DELIMITER //
CREATE PROCEDURE check_income
    (IN producer_name VARCHAR(40))
BEGIN
    SELECT SUM(prod.price)
        FROM products prod
    JOIN (
        SELECT prod_ord.product_id_fk
            FROM prod_ord
        WHERE (SELECT products.producer_id_fk
                   FROM products
               WHERE product_id = prod_ord.product_id_fk) = 
              (SELECT producers.producer_id
                   FROM producers
               WHERE name=producer_name)
    ) ord ON prod.product_id = ord.product_id_fk
    INTO @sum_income;
    SELECT income = @sum_income AS IS_SAME
        FROM producers
    WHERE name = producer_name;
END
//
DELIMITER ;

DROP PROCEDURE IF EXISTS check_consumption;
DELIMITER //
CREATE PROCEDURE check_consumption
    (IN customer_name VARCHAR(40))
BEGIN
    SELECT SUM(price)
        FROM products prod
    JOIN (
        SELECT prod_ord.product_id_fk
            FROM prod_ord
        WHERE prod_ord.order_id_fk =
            (SELECT order_id
                FROM orders
             WHERE customer_id_fk = 
                (SELECT customers.customer_id
                   FROM customers
                WHERE name=customer_name)
            )
    ) ord ON prod.product_id = ord.product_id_fk
    INTO @sum_consumption;
    SELECT consumption = @sum_consumption AS IS_SAME
        FROM customers
    WHERE name = customer_name;
END
//
DELIMITER ;

DROP PROCEDURE IF EXISTS find_max_income;
DELIMITER //
CREATE PROCEDURE find_max_income ()
BEGIN
    SELECT @lucky_shop:=producer_id
        FROM prod_ord
    JOIN (
        SELECT product_id, producer_id, producers.name, price FROM products
        JOIN producers ON producer_id_fk = producer_id        
    ) AS products_producers
    ON prod_ord.product_id_fk = products_producers.product_id
    WHERE (SELECT time FROM orders WHERE order_id=prod_ord.order_id_fk) BETWEEN DATE_SUB(NOW(), INTERVAL 1 MONTH) AND NOW()
    GROUP BY producer_id
    ORDER BY SUM(price) DESC
    LIMIT 1;
    SELECT name AS MAX_INCOME_SHOP
        FROM producers
    WHERE producer_id=@lucky_shop;
END
//
DELIMITER ;

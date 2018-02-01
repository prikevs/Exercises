DROP PROCEDURE IF EXISTS insert_producer; 
DELIMITER //
CREATE PROCEDURE insert_producer
    (IN in_name VARCHAR(40))
BEGIN
    INSERT INTO producers (name) VALUES (in_name);
END
//
DELIMITER ;

DROP PROCEDURE IF EXISTS insert_customer; 
DELIMITER //
CREATE PROCEDURE insert_customer
    (IN in_name VARCHAR(40))
BEGIN
    INSERT INTO customers (name) VALUES(in_name);
END
//
DELIMITER ;

DROP PROCEDURE IF EXISTS insert_product; 
DELIMITER //
CREATE PROCEDURE insert_product
    (IN product_name VARCHAR(40), IN producer_name VARCHAR(40), IN _price DOUBLE(9,2))
BEGIN
    INSERT INTO products
        SET name = product_name,
            price = _price,
            producer_id_fk = (
                    SELECT producer_id
                        FROM producers
                    WHERE name = producer_name);
END
//
DELIMITER ;

DROP PROCEDURE IF EXISTS add_prod;
DELIMITER //
CREATE PROCEDURE add_prod
    (IN product_name VARCHAR(40), IN in_order_id INTEGER)
BEGIN
    INSERT INTO prod_ord
        SET product_id_fk = (
                SELECT product_id
                    FROM products
                WHERE name=product_name
                LIMIT 1),
            order_id_fk = in_order_id;
    UPDATE producers
        SET income = income + (
                SELECT price
                    FROM products
                WHERE name = product_name
                LIMIT 1)
        WHERE producer_id = (
                SELECT producer_id_fk
                    FROM products
                WHERE name = product_name
                LIMIT 1);
    UPDATE customers
        SET consumption = consumption + (
                SELECT price
                    FROM products
                WHERE name = product_name
                LIMIT 1)
        WHERE customer_id = (
                SELECT customer_id_fk
                    FROM orders
                WHERE order_id=in_order_id);
END
//
DELIMITER ;

DROP PROCEDURE IF EXISTS create_order;
DELIMITER //
CREATE PROCEDURE create_order
    (IN customer_name VARCHAR(40),
     IN product_name_1 VARCHAR(40),
     IN product_name_2 VARCHAR(40),
     IN product_name_3 VARCHAR(40),
     IN product_name_4 VARCHAR(40),
     IN product_name_5 VARCHAR(40),
     IN product_name_6 VARCHAR(40))
BEGIN
    START TRANSACTION;
    SAVEPOINT init_point;
    INSERT INTO orders
        SET customer_id_fk = (
                SELECT customer_id
                    FROM customers
                WHERE name = customer_name
                LIMIT 1),
            time = CURDATE();
    SET @last_id_in_orders = LAST_INSERT_ID();
    SELECT @last_id_in_orders;
    IF product_name_1 IS NOT NULL THEN
        CALL add_prod(product_name_1, @last_id_in_orders);
    END IF;
    IF product_name_2 IS NOT NULL THEN
        CALL add_prod(product_name_2, @last_id_in_orders);
    END IF;
    IF product_name_3 IS NOT NULL THEN
        CALL add_prod(product_name_3, @last_id_in_orders);
    END IF;
    IF product_name_4 IS NOT NULL THEN
        CALL add_prod(product_name_4, @last_id_in_orders);
    END IF;
    IF product_name_5 IS NOT NULL THEN
        CALL add_prod(product_name_5, @last_id_in_orders);
    END IF;
    IF product_name_6 IS NOT NULL THEN
        CALL add_prod(product_name_6, @last_id_in_orders);
    END IF;
    COMMIT;
END
//
DELIMITER ;

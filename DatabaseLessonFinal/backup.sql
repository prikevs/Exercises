CREATE TABLE orders_backup (
    order_id INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
    customer_id_fk INTEGER NOT NULL,
    time DATE NOT NULL,
    FOREIGN KEY (customer_id_fk) REFERENCES customers(customer_id)
);

CREATE TABLE prod_ord_backup (
    product_id_fk INTEGER NOT NULL,
    order_id_fk INTEGER NOT NULL,
    FOREIGN KEY (product_id_fk) REFERENCES products(product_id),
    FOREIGN KEY (order_id_fk) REFERENCES orders(order_id)
);

DELIMITER //
CREATE TRIGGER backup_order_table
AFTER INSERT ON `orders`
FOR EACH ROW
BEGIN
    INSERT INTO orders_backup (order_id, customer_id_fk, time) VALUES (new.order_id, new.customer_id_fk, new.time);
END
//

CREATE TRIGGER backup_prod_ord_table
AFTER INSERT ON `prod_ord`
FOR EACH ROW
BEGIN
    INSERT INTO prod_ord_backup (product_id_fk, order_id_fk) VALUES (new.product_id_fk, new.order_id_fk);
END
//
DELIMITER ;

DROP DATABASE  IF EXISTS db_homework;
CREATE DATABASE db_homework DEFAULT CHARSET='utf8';
USE db_homework

CREATE TABLE producers (
    producer_id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(40),
    income DOUBLE(9,2) DEFAULT 0
); 

CREATE TABLE customers (
    customer_id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(40) NOT NULL,
    consumption DOUBLE(9,2) DEFAULT 0.0
);

CREATE TABLE products (
    product_id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(40),
    price DOUBLE(9,2) NOT NULL,
    producer_id_fk INTEGER NOT NULL,
    FOREIGN KEY (producer_id_fk) REFERENCES producers(producer_id)
);

CREATE TABLE orders (
    order_id INTEGER PRIMARY KEY AUTO_INCREMENT,
    customer_id_fk INTEGER NOT NULL,
    time DATE NOT NULL,
    FOREIGN KEY (customer_id_fk) REFERENCES customers(customer_id)
);

CREATE TABLE prod_ord (
    product_id_fk INTEGER NOT NULL,
    order_id_fk INTEGER NOT NULL,
    FOREIGN KEY (product_id_fk) REFERENCES products(product_id),
    FOREIGN KEY (order_id_fk) REFERENCES orders(order_id)
);


INSERT INTO producers (name) VALUES ('黄焖鸡米饭');
INSERT INTO producers (name) VALUES ('沙县小吃');
INSERT INTO producers (name) VALUES ('校点点');
INSERT INTO producers (name) VALUES ('战斗鸡排');

INSERT INTO products
    SET name = "大份黄焖鸡",
        price = 21.0,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '黄焖鸡米饭');

INSERT INTO products
    SET name = "小份黄焖鸡",
        price = 18.0,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '黄焖鸡米饭');

INSERT INTO products
    SET name = "红烧鸡腿饭",
        price = 14.0,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '沙县小吃');

INSERT INTO products
    SET name = "红烧狮子头饭",
        price = 13.5,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '沙县小吃');

INSERT INTO products
    SET name = "毛豆烧鸡饭",
        price = 12.0,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '校点点');

INSERT INTO products
    SET name = "梅子味鸡排",
        price = 14.0,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '战斗鸡排');

INSERT INTO products
    SET name = "原味鸡排",
        price = 12.0,
        p_id_fk = (
            SELECT id
                FROM producers
            WHERE name = '战斗鸡排');

INSERT INTO costumers (name) VALUES ('小明');
INSERT INTO costumers (name) VALUES ('小红');
INSERT INTO costumers (name) VALUES ('小杰');

INSERT INTO orders
    SET p_id_fk = (
            SELECT id
                FROM products 
            WHERE name = '梅子味鸡排'
            LIMIT 1
        ),
        c_id_fk = (
            SELECT id
                FROM costumers
            WHERE name = '小明'
            LIMIT 1
        );
UPDATE producers
    SET income = income + (
            SELECT price
                FROM products
            WHERE name = '梅子味鸡排'
            LIMIT 1
        )
    WHERE id = (
            SELECT p_id_fk
                FROM products
            WHERE name = '梅子味鸡排'
            LIMIT 1
        );
UPDATE costumers 
    SET consumption = consumption + (
            SELECT price
                FROM products
            WHERE name = '梅子味鸡排'
            LIMIT 1
        )
    WHERE name = '小明';

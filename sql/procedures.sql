CREATE OR REPLACE PROCEDURE createOrder(
    user_id INTEGER,
    product_ids INTEGER[],
    quantities INTEGER[],
    prices DECIMAL[]
)
LANGUAGE plpgsql
AS $$
DECLARE
    new_order_id INTEGER;
    total DECIMAL := 0;
    i INTEGER;
BEGIN
    IF array_length(product_ids, 1) != array_length(quantities, 1) OR
       array_length(product_ids, 1) != array_length(prices, 1) THEN
        RAISE EXCEPTION 'Arrays must have same length';
    END IF;

    BEGIN
        INSERT INTO orders (user_id, status, total_price)
        VALUES (user_id, 'pending', 0)
        RETURNING order_id INTO new_order_id;

        FOR i IN 1..array_length(product_ids, 1) LOOP
            INSERT INTO order_items (order_id, product_id, quantity, price)
            VALUES (new_order_id, product_ids[i], quantities[i], prices[i]);
            
            total := total + (quantities[i] * prices[i]);
        END LOOP;

        UPDATE orders SET total_price = total WHERE order_id = new_order_id;

        COMMIT;
    EXCEPTION
        WHEN OTHERS THEN
            ROLLBACK;
            RAISE;
    END;
END;
$$;
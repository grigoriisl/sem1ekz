CREATE OR REPLACE FUNCTION getOrderStatus(order_id INTEGER)
RETURNS VARCHAR AS $$
DECLARE
    order_status VARCHAR;
BEGIN
    SELECT status INTO order_status FROM orders WHERE order_id = $1;
    RETURN order_status;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION getUserOrderCount(user_id INTEGER)
RETURNS INTEGER AS $$
DECLARE
    order_count INTEGER;
BEGIN
    SELECT COUNT(*) INTO order_count FROM orders WHERE user_id = $1;
    RETURN order_count;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION getTotalSpentByUser(user_id INTEGER)
RETURNS DECIMAL AS $$
DECLARE
    total DECIMAL;
BEGIN
    SELECT COALESCE(SUM(total_price), 0) INTO total FROM orders WHERE user_id = $1;
    RETURN total;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION canReturnOrder(order_id INTEGER)
RETURNS BOOLEAN AS $$
DECLARE
    order_status VARCHAR;
    order_date TIMESTAMP;
BEGIN
    SELECT status, order_date INTO order_status, order_date FROM orders WHERE order_id = $1;
    
    IF order_status = 'completed' AND order_date > CURRENT_TIMESTAMP - INTERVAL '30 days' THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION getOrderStatusHistory(order_id INTEGER)
RETURNS TABLE(history_id INTEGER, old_status VARCHAR, new_status VARCHAR, changed_at TIMESTAMP, changed_by INTEGER) AS $$
BEGIN
    RETURN QUERY
    SELECT h.history_id, h.old_status, h.new_status, h.changed_at, h.changed_by
    FROM order_status_history h
    WHERE h.order_id = $1
    ORDER BY h.changed_at;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION getAuditLogByUser(user_id INTEGER)
RETURNS TABLE(log_id INTEGER, entity_type VARCHAR, entity_id INTEGER, operation VARCHAR, performed_at TIMESTAMP) AS $$
BEGIN
    RETURN QUERY
    SELECT a.log_id, a.entity_type, a.entity_id, a.operation, a.performed_at
    FROM audit_log a
    WHERE a.performed_by = $1
    ORDER BY a.performed_at;
END;
$$ LANGUAGE plpgsql;
#ifndef ORDER_ITEM_H
#define ORDER_ITEM_H

class OrderItem {
private:
    int orderItemId;
    int productId;
    int quantity;
    double unitPrice;

public:
    OrderItem(int id, int productId, int quantity, double price);
    
    int getOrderItemId() const { return orderItemId; }
    int getProductId() const { return productId; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return unitPrice; }
    double getTotalPrice() const { return quantity * unitPrice; }
};

#endif
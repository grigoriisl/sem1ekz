#include "OrderItem.h"

OrderItem::OrderItem(int id, int productId, int quantity, double price)
    : orderItemId(id), productId(productId), quantity(quantity), unitPrice(price) {
}
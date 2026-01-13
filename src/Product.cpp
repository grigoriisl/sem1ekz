#include "Product.h"

Product::Product(int id, const string& name, double price, int quantity)
    : productId(id), name(name), price(price), stockQuantity(quantity) {
}

void Product::updatePrice(double newPrice) {
    price = newPrice;
}

void Product::updateQuantity(int newQuantity) {
    stockQuantity = newQuantity;
}

void Product::decreaseQuantity(int amount) {
    if (amount <= stockQuantity) {
        stockQuantity -= amount;
    }
}
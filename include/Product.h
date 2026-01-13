#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int stockQuantity;

public:
    Product(int id, const string& name, double price, int quantity);
    
    void updatePrice(double newPrice);
    void updateQuantity(int newQuantity);
    void decreaseQuantity(int amount);
    
    int getProductId() const { return productId; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }
    bool isAvailable(int requested) const { return stockQuantity >= requested; }
};

#endif
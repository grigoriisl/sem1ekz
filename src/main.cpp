#include <iostream>
#include <memory>
#include "DatabaseConnection.h"
#include "Admin.h"
#include "Manager.h"
#include "Customer.h"

using namespace std;

void showAdminMenu(shared_ptr<Admin> admin) {
    while (true) {
        cout << "\n=== ADMIN MENU ===" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View All Orders" << endl;
        cout << "3. View Audit Log" << endl;
        cout << "4. Generate CSV Report" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 5) break;
        
        if (choice == 1) {
            string name;
            double price;
            int quantity;
            
            cout << "Product name: ";
            cin >> name;
            cout << "Price: ";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;
            
            admin->addProduct(name, price, quantity);
        } else if (choice == 2) {
            admin->viewAllOrders();
        } else if (choice == 3) {
            admin->viewAuditLog();
        } else if (choice == 4) {
            admin->generateCSVReport();
        }
    }
}

void showManagerMenu(shared_ptr<Manager> manager) {
    while (true) {
        cout << "\n=== MANAGER MENU ===" << endl;
        cout << "1. Approve Order" << endl;
        cout << "2. Update Stock" << endl;
        cout << "3. View Pending Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 4) break;
        
        if (choice == 1) {
            int orderId;
            cout << "Order ID to approve: ";
            cin >> orderId;
            manager->approveOrder(orderId);
        } else if (choice == 2) {
            int productId, quantity;
            cout << "Product ID: ";
            cin >> productId;
            cout << "New quantity: ";
            cin >> quantity;
            manager->updateStock(productId, quantity);
        } else if (choice == 3) {
            manager->viewPendingOrders();
        }
    }
}

void showCustomerMenu(shared_ptr<Customer> customer) {
    while (true) {
        cout << "\n=== CUSTOMER MENU ===" << endl;
        cout << "1. Create Order" << endl;
        cout << "2. Make Payment" << endl;
        cout << "3. Return Order" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 4) break;
        
        if (choice == 1) {
            customer->createOrder();
        } else if (choice == 2) {
            int orderId;
            cout << "Order ID to pay: ";
            cin >> orderId;
            customer->makePayment(orderId);
        } else if (choice == 3) {
            int orderId;
            cout << "Order ID to return: ";
            cin >> orderId;
            customer->returnOrder(orderId);
        }
    }
}

int main() {
    cout << "=== ONLINE STORE SYSTEM ===" << endl;
    
    DatabaseConnection<string> db("dbname=products_db user=postgres password=10012007 host=localhost port=5432");
    
    while (true) {
        cout << "\nSelect role:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Manager" << endl;
        cout << "3. Customer" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        
        int role;
        cin >> role;
        
        if (role == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
        
        if (role == 1) {
            auto admin = make_shared<Admin>(1, "Admin", "admin@store.com");
            showAdminMenu(admin);
        } else if (role == 2) {
            auto manager = make_shared<Manager>(2, "Manager", "manager@store.com");
            showManagerMenu(manager);
        } else if (role == 3) {
            auto customer = make_shared<Customer>(3, "Customer", "customer@store.com");
            showCustomerMenu(customer);
        }
    }
    
    return 0;
}
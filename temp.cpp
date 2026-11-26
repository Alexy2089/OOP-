#include <iostream>
#include <list>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    float price;
    int quantity;

    Product(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }
};

class ProductSystem {
    list<Product> products;
    list<Product*> hashTable[10];

    int hashFunction(int id) {
        return id % 10;
    }

public:
    void addProduct(int id, string name, float price, int qty) {
        products.push_back(Product(id, name, price, qty));

        Product* p = &products.back();
        hashTable[hashFunction(id)].push_back(p);

        cout << "Product added successfully!\n";
    }

    void searchProduct(int id) {
        int index = hashFunction(id);

        for (auto p : hashTable[index]) {
            if (p->id == id) {
                cout << "Product Found!\n";
                cout << "Name: " << p->name << endl;
                cout << "Price: " << p->price << endl;
                cout << "Quantity: " << p->quantity << endl;
                return;
            }
        }
        cout << "Product not found!\n";
    }

    void updateProduct(int id) {
        for (auto &p : products) {
            if (p.id == id) {
                cout << "Enter new name, price and quantity: ";
                cin >> p.name >> p.price >> p.quantity;
                cout << "Product updated!\n";
                return;
            }
        }
        cout << "Product not found!\n";
    }

    void removeProduct(int id) {
        int index = hashFunction(id);

        for (auto it = hashTable[index].begin();
             it != hashTable[index].end(); ++it) {
            if ((*it)->id == id) {
                Product* p = *it;
                hashTable[index].erase(it);

                for (auto jt = products.begin();
                     jt != products.end(); ++jt) {
                    if (&(*jt) == p) {
                        products.erase(jt);
                        break;
                    }
                }

                cout << "Product removed!\n";
                return;
            }
        }
        cout << "Product not found!\n";
    }

    void displayProducts() {
        cout << "\nAvailable Products:\n";

        for (auto p : products) {
            cout << "ID: " << p.id
                 << " Name: " << p.name
                 << " Price: " << p.price
                 << " Quantity: " << p.quantity << endl;
        }
    }
};

int main() {
    ProductSystem system;
    int choice, id, qty;
    string name;
    float price;

    do {
        cout << "\n1. Add Product";
        cout << "\n2. Search Product";
        cout << "\n3. Update Product";
        cout << "\n4. Remove Product";
        cout << "\n5. Display Products";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID, Name, Price, Quantity: ";
            cin >> id >> name >> price >> qty;
            system.addProduct(id, name, price, qty);
            break;

        case 2:
            cout << "Enter Product ID: ";
            cin >> id;
            system.searchProduct(id);
            break;

        case 3:
            cout << "Enter Product ID: ";
            cin >> id;
            system.updateProduct(id);
            break;

        case 4:
            cout << "Enter Product ID: ";
            cin >> id;
            system.removeProduct(id);
            break;

        case 5:
            system.displayProducts();
            break;
        }
    } while (choice != 0);

    return 0;
}

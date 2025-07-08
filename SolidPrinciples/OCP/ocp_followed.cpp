// the class is ready for extension but close for modification;
#include <iostream>
#include <vector>
using namespace std;
class Product{
public:
    double price;
    string name;
    Product(int price,string name){
        this->price=price;
        this->name=name;
    }
};
class ShopingCart{
private:
    vector<Product*> vec;
public:
    void push(Product* p){
        vec.push_back(p);
    }// setter;
    const vector<Product*>& getProducts(){
        return vec;
    }
    double calculateTotalPrice(){
        double total=0;
        for(int i=0;i<vec.size();i++){
            total=total+vec[i]->price;
        }
        return total;
    }
};
class ShoppingCartPrinter{
private:
    ShopingCart* cart;
public:
    ShoppingCartPrinter(ShopingCart* cart){
        this->cart=cart;
    }
    void printInvoice() {
        cout<<"Shopping Cart Invoice:\n";
        for(auto p:cart->getProducts()) {
            cout<<p->name<<" - Rs "<< p->price<< endl;
        }
        cout<<"Total: Rs"<< cart->calculateTotalPrice()<< endl;
    }
};
// using the concept of polymorphism,abstraction,inheritance;
// instead of adding the methods for saving product in different database in a single class we make diffrent classes for different database and the base class as a abstract class to foll open-close principle;
class Persistence{
public:
    // Persistence(ShopingCart* cart){
    //     this->cart=cart;
    // } // donot require this because we have not used cart anywhere;
    // virtual method;
    virtual void save(ShopingCart* cart)=0;
};
class SQLPersistence : public Persistence {
public:
    void save(ShopingCart* cart) override {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};
class MongoPersistence : public Persistence {
public:
    void save(ShopingCart* cart) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public Persistence {
public:
    void save(ShopingCart* cart) override {
        cout << "Saving shopping cart to a file..." << endl;
    }
};
int main() {
    ShopingCart* cart = new ShopingCart();
    cart->push(new Product(50000,"Laptop"));
    cart->push(new Product(2000,"Mouse"));
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();
    db->save(cart);   // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File
    return 0;
}
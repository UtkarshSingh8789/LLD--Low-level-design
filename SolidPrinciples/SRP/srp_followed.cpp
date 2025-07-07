#include <iostream>
#include <vector>
using namespace std;

// i have to make a one class for product
class Product{
public:
    double price;
    string name;
    Product(int price,string name){
        this->price=price;
        this->name=name;
    }
};

// i have to make a second class shoping card which provides the total cost of product that we have purchased
class ShopingCart{
private:
    vector<Product*> vec;
    int total=0;
public:
    void push(Product* p){
        vec.push_back(p);
    }// setter;
    const vector<Product*>& getProducts(){
        return vec;
    }
    double calculateTotalPrice(){
        for(int i=0;i<vec.size();i++){
            total=total+vec[i]->price;
        }
        return total;
    }
};

// i have to make a class for prining invoice;
class ShoppingCartPrinter{
    // compostion
    // first i will take the refrence of main class -> shoping cart;
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
// i have to make a class for saving product into database;
class ShoppingCartStorage {
private:
    ShopingCart* cart; 
public:
    ShoppingCartStorage(ShopingCart* cart) { 
        this->cart = cart; 
    }
    void saveToDatabase() {
        cout<< "Saving shopping cart to database..."<< endl;
    }
};
int main() {
    ShopingCart* cart=new ShopingCart();
    cart->push(new Product(50000,"Laptop"));
    cart->push(new Product(2000,"Mouse"));
    ShoppingCartPrinter* printer=new ShoppingCartPrinter(cart);
    printer->printInvoice();
    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();
    return 0;
}
#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>
using namespace std;
// no withdrawable and withdrawable account we have to make;
// non-withdrawable -> only deposit;
class DepositOnlyAccount{
public:
    virtual void deposit(double ammount)=0;
};
class WithdrawableAccount: public DepositOnlyAccount{
public:
    // it inherit from depositOnlyAccount hence it got deposit function from its parent;
    virtual void withdraw(double ammount)=0;
};
class SavingAccount: public WithdrawableAccount{
public:
    // can have both deposit and withdraw function hence it inherited from withdrawableAccount
    double balance;
    SavingAccount(){
        balance=0;
    }
    void deposit(double amount) override {
        balance=balance+amount;
        cout<<"balnce in saving account: "<<balance<<endl;
    }
    void withdraw(double amount) override {
        if(balance>=amount){
            balance=balance-amount;
            cout<<"money withdrawn: "<<amount<<" Now your current balance in Saving account: "<<balance<<endl;
        }
        else{
            cout<<"insufficent balance"<<endl;
        }
    }
};
class CurrentAccount: public WithdrawableAccount{
public:
    // can have both deposit and withdraw function hence it inherited from withdrawableAccount
    double balance;
    CurrentAccount(){
        balance=0;
    }
    void deposit(double amount) override {
        balance=balance+amount;
        cout<<"balnce in current account: "<<balance<<endl;
    }
    void withdraw(double amount) override {
        if(balance>=amount){
            balance=balance-amount;
            cout<<"money withdrawn: "<<amount<<" Now your current balance in current account: "<<balance<<endl;
        }
        else{
            cout<<"insufficent balance"<<endl;
        }
    }
};
class FixedTermAccount: public DepositOnlyAccount{
public:
    double balance;
    FixedTermAccount(){
        balance=0;
    }
    void deposit(double amount) override {
        balance=balance+amount;
        cout<<"balnce in fixed account "<<balance<<endl;
    }
};
class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;
public:
    BankClient(vector<WithdrawableAccount*> withdrawableAccounts, 
        vector<DepositOnlyAccount*> depositOnlyAccounts) { 
        this->withdrawableAccounts=withdrawableAccounts; 
        this->depositOnlyAccounts=depositOnlyAccounts;
    }
    void processTransactions() {
        for(WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for(DepositOnlyAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};
int main() {
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());
    BankClient* client=new BankClient (withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();
    return 0;
}

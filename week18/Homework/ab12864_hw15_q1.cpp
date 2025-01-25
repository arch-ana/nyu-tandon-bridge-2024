#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

class Account
{
private:
    string name;
    double amount_paid;
    double amount_owed;
    bool paid_status;
    Account* link;
public:
    Account();
    Account(string the_name, double the_amount_paid);
    Account(string the_name, double the_amount_paid, double the_amount_owed, bool the_paid_status, Account* the_next);
    string get_name() const;
    void set_name(string the_name);
    double get_amount_paid() const;
    void set_amount_paid(double the_amount_paid);
    double get_amount_owed() const;
    void set_amount_owed(double the_amount_owed);
    bool get_paid_status() const;
    void set_paid_status(bool the_paid_status);
    Account* get_link() const;
    void set_link(Account* next);

    friend class LinkedList;
};

typedef Account* AccountNodePtr;

class LinkedList{
    private:
        Account* head;

    public:
        LinkedList();
        ~LinkedList();
        void add_account(string the_name, double the_amount_paid);
        double total_cost() const;
        double total_accounts() const; //using double to address any future conversion errors
        void calculate_amount_owed(double share);
        Account* find_next_debtor(AccountNodePtr curr_node);
        Account* find_next_creditor(AccountNodePtr curr_node);
        void settle_transaction(AccountNodePtr debtor, AccountNodePtr creditor);
        void find_and_settle_all_transactions();
};

int main(){

    string in_file_name, name;
    char character;
    double amount;
    ifstream in_stream;

    cout<<"Enter the file name: ";
    cin>>in_file_name;

    in_stream.open(in_file_name);
    in_stream.setf(ios::fixed);
    if (in_stream.fail()){
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    LinkedList accounts;

    while (in_stream>>amount){
        in_stream.get(character);
        while (character != '\n' && !in_stream.eof()){
            name += character;
            in_stream.get(character);
        }
        accounts.add_account(name, amount);
        name = "";
    }

    double total = accounts.total_cost();
    double count = accounts.total_accounts();
    double share = total/count;

    accounts.calculate_amount_owed(share);
    accounts.find_and_settle_all_transactions();

    cout<<"In the end, you should have all spent: "<<share<<endl;

    in_stream.close();

    return 0;
}

//Account class function implementations

Account::Account(): name(""), amount_paid(0), amount_owed(0), paid_status(false), link(nullptr){}

Account::Account(string the_name, double the_amount_paid):name(the_name), amount_paid(the_amount_paid), amount_owed(0), paid_status(false), link(nullptr){}

Account::Account(string the_name, double the_amount_paid, double the_amount_owed, bool the_paid_status, Account* the_next): name(the_name), amount_paid(the_amount_paid), amount_owed(the_amount_owed), paid_status(the_paid_status), link(the_next){}

string Account::get_name() const{
    return name;
}

void Account::set_name(string the_name){
    name = the_name;
}

double Account::get_amount_paid() const{
    return amount_paid;
}

void Account::set_amount_paid(double the_amount_paid){
    amount_paid = the_amount_paid;
}

double Account::get_amount_owed() const{
    return amount_owed;
}

void Account::set_amount_owed(double the_amount_owed){
    amount_owed = the_amount_owed;
}

bool Account::get_paid_status() const{
    return paid_status;
}

void Account::set_paid_status(bool the_paid_status){
    paid_status = the_paid_status;
}

Account* Account::get_link() const{
    return link;
}

void Account::set_link(Account* the_next){
    link = the_next;
}

//Linked list class implementation
LinkedList::LinkedList():head(nullptr){}

LinkedList::~LinkedList(){
    while (head != nullptr){
        Account* temp = head;
        head = head->get_link();
        delete temp;
    }
}

void LinkedList::add_account(string the_name, double the_amount_paid){
    AccountNodePtr new_account = new Account (the_name, the_amount_paid);
    new_account->set_link(head);
    head = new_account;
}

double LinkedList::total_cost() const{

    double total = 0.0;

    for (AccountNodePtr iter = head; iter != nullptr; iter = iter -> get_link()){
        total += iter->get_amount_paid();
    }
    return total;
}

double LinkedList::total_accounts() const{

    double num_accounts = 0.0;

    for (AccountNodePtr iter = head; iter != nullptr; iter = iter -> get_link()){
        num_accounts ++;
    }

    return num_accounts;

}

void LinkedList::calculate_amount_owed(double share){
    for (AccountNodePtr iter = head; iter != nullptr; iter = iter ->get_link()){
        iter -> set_amount_owed(iter->get_amount_paid() - share);
        iter -> set_paid_status(iter -> get_amount_paid() == share);
    }
}

AccountNodePtr LinkedList::find_next_debtor(AccountNodePtr curr_node){
    AccountNodePtr iter = curr_node;
    while ((iter != nullptr) && iter->get_amount_owed()>=0){
        iter = iter -> get_link();
    }
    return iter; //always check if this returns a nullptr;
}

AccountNodePtr LinkedList::find_next_creditor(AccountNodePtr curr_node){
    AccountNodePtr iter = curr_node;
    while ((iter != nullptr) && iter->get_amount_owed()<=0){
        iter = iter -> get_link();
    }
    return iter; //always check if this returns a nullptr;
}

void LinkedList::settle_transaction(AccountNodePtr debtor, AccountNodePtr creditor){
    
    if (debtor != nullptr && creditor != nullptr){
        double amount_settled = min(abs(debtor ->get_amount_owed()), abs(creditor-> get_amount_owed()));
        double new_amount_debtor = debtor->get_amount_owed()+amount_settled;
        if (abs(new_amount_debtor) < 1e-9){
            new_amount_debtor = 0;
        }
        debtor->set_amount_owed(new_amount_debtor);
        double new_amount_creditor = creditor->get_amount_owed()-amount_settled;
        if (abs(new_amount_creditor) < 1e-9){
            new_amount_creditor = 0;
        }
        creditor->set_amount_owed(new_amount_creditor);
        cout<<debtor->get_name()<<" pays "<<creditor->get_name()<<" $ "<<amount_settled<<endl;
    }    
}

void LinkedList::find_and_settle_all_transactions(){
    AccountNodePtr debtor = find_next_debtor(head);
    AccountNodePtr creditor = find_next_creditor(head);

    for (AccountNodePtr iter = head; iter != nullptr; iter = iter -> get_link()){
        if (iter->get_paid_status() == true){
            cout<<iter->get_name()<<" you need not do anything\n";
        }
    }

    while (debtor != nullptr && creditor != nullptr){
        settle_transaction(debtor, creditor);
        if (debtor->get_amount_owed() == 0){
            debtor = find_next_debtor(debtor);
        }
        if (creditor->get_amount_owed() == 0){
            creditor = find_next_creditor(creditor);
        }
    }   
}

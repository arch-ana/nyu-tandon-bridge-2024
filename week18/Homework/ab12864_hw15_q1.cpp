#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>

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
};

typedef Account* AccountNodePtr;

void head_insert(AccountNodePtr& the_head, string the_name, double the_amount_paid);

int main(){

    string in_file_name, name;
    char character;
    double amount, total, share, count;
    ifstream in_stream;
    AccountNodePtr head = new Account;

    cout<<"Enter the file name: ";
    cin>>in_file_name;

    in_stream.open(in_file_name);
    if (in_stream.fail()){
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    //first node entry
    in_stream>>amount;
    in_stream.get(character);

    while(character != '\n'){
        name += character;
        in_stream.get(character);
    }

    head -> set_name(name);
    head -> set_amount_paid(amount);
    head -> set_link(nullptr);

    string name2;
    double amount2;
    char character2;

    while (in_stream>>amount2){
        in_stream.get(character2);
        while (character2 != '\n' && !in_stream.eof()){
            name2 += character2;
            in_stream.get(character2);
        }
        head_insert(head, name2, amount2);
        name2 = "";
    }

    for (AccountNodePtr iter = head; iter != nullptr; iter = iter -> get_link()){
        // cout<<"Name: "<<iter->get_name()<<endl;
        // cout<<"Amount: "<<iter->get_amount_paid()<<endl;
        total += iter -> get_amount_paid();
        count++;
    }

    share = total/count;
    //cout<<"Share is: "<<share<<endl;

    for (AccountNodePtr iter = head; iter != nullptr; iter = iter -> get_link()){
        iter -> set_amount_owed(iter->get_amount_paid() - share);
        if (iter -> get_amount_paid() == share){
            iter -> set_paid_status(true);
        }else{
            iter -> set_paid_status(false);
        }
        //cout<<"Name: "<<iter->get_name()<<" & paid status: "<<iter->get_paid_status()<<endl;
    }

    

    delete head;
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

void head_insert(AccountNodePtr& the_head, string the_name, double the_amount_paid){
    AccountNodePtr temp_ptr;
    temp_ptr = new Account(the_name, the_amount_paid);
    temp_ptr->set_link(the_head);
    the_head = temp_ptr;
}

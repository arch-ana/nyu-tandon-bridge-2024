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
    int amount_paid;
    int amount_owed;
    bool paid_status;
    Account* link;
public:
    Account();
    Account(string the_name, int the_amount_paid, int the_amount_owed, bool the_paid_status, Account* the_next);
    string get_name() const;
    void set_name(string the_name);
    int get_amount_paid() const;
    void set_amount_paid(int the_amount_paid);
    int get_amount_owed() const;
    void set_amount_owed(int the_amount_owed);
    bool get_paid_status() const;
    void set_paid_status(bool the_paid_status);
    Account* get_link() const;
    void set_link(Account* next);
};

typedef Account* AccountNodePtr;

void head_insert(AccountNodePtr& the_head, string the_name, int the_amount_paid, int the_amount_owed, bool the_paid_status, Account* the_next);

int main(){

    string in_file_name, name;
    char character;
    double amount;
    ifstream in_stream;
    AccountNodePtr head;

    cout<<"Enter the file name: ";
    cin>>in_file_name;

    in_stream.open(in_file_name);
    
    if (in_stream.fail()){
        cout<<"Input file opening failed.\n";
        exit(1);
    }


    in_stream>>amount;
    in_stream.get(character);

    while(character != '\n'){
        name += character;
        in_stream.get(character);
    }
    
    cout<<"Amount: "<<amount<<endl;
    cout<<"Name: "<<name<<endl;
        
    // while (!in_stream.eof()){

    //     in_stream>>amount;
    //     in_stream.get(character);
        
    //     while(character != '\n'){
    //         name += character;
    //         cin.get(character);
    //     }

    //     cout<<"Name: "<<name<<endl;
    //     cout<<"Amount: "<<amount<<endl;
    // }
    


    in_stream.close();

    return 0;
}

//Account class function implementations

Account::Account(): name(""), amount_paid(0), amount_owed(0), paid_status(false), link(nullptr){}

Account::Account(string the_name, int the_amount_paid, int the_amount_owed, bool the_paid_status, Account* the_next): name(the_name), amount_paid(the_amount_paid), amount_owed(the_amount_owed), paid_status(the_paid_status), link(the_next){}

string Account::get_name() const{
    return name;
}

void Account::set_name(string the_name){
    name = the_name;
}

int Account::get_amount_paid() const{
    return amount_paid;
}

void Account::set_amount_paid(int the_amount_paid){
    amount_paid = the_amount_paid;
}

int Account::get_amount_owed() const{
    return amount_owed;
}

void Account::set_amount_owed(int the_amount_owed){
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

void head_insert(AccountNodePtr& the_head, string the_name, int the_amount_paid, int the_amount_owed, bool the_paid_status, Account* the_next){
    AccountNodePtr temp_ptr;
    temp_ptr = new Account(the_name, the_amount_paid, the_amount_owed, the_paid_status, the_head);
    the_head = temp_ptr;
}

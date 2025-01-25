#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>

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
AccountNodePtr find_next_debtor(AccountNodePtr curr_node);
AccountNodePtr find_next_creditor(AccountNodePtr curr_node);
void settle_transaction(AccountNodePtr debtor, AccountNodePtr creditor);
//void find_and_settle_transactions(AccountNodePtr head);
void find_and_settle_all_transactions(AccountNodePtr head);

int main(){

    string in_file_name, name;
    char character;
    double amount, total, share, count;
    ifstream in_stream;
    AccountNodePtr head = new Account;

    cout<<"Enter the file name: ";
    cin>>in_file_name;

    in_stream.open(in_file_name);
    in_stream.setf(ios::fixed);
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

    // AccountNodePtr debtor = find_next_debtor(head);
    // cout<<"Debter is: "<<debtor->get_name()<<" and is owed "<<debtor->get_amount_owed()<<endl;
    // AccountNodePtr creditor = find_next_creditor(head);
    // cout<<"Creditor is: "<<creditor->get_name()<<" and is owed "<<creditor->get_amount_owed()<<endl;
    // settle_transaction(debtor, creditor);
    // cout<<"Debter "<<debtor->get_name()<<" is now owed "<<debtor->get_amount_owed()<<endl;
    // cout<<"Creditor "<<creditor->get_name()<<" is now owed "<<creditor->get_amount_owed()<<endl;

    // AccountNodePtr debtor1 = find_next_debtor(debtor);
    // cout<<"Debter is: "<<debtor1->get_name()<<" and is owed "<<debtor1->get_amount_owed()<<endl;
    // AccountNodePtr creditor1 = find_next_creditor(creditor);
    // cout<<"Creditor is: "<<creditor1->get_name()<<" and is owed "<<creditor1->get_amount_owed()<<endl;
    // settle_transaction(debtor1, creditor1);
    // cout<<"Debter "<<debtor1->get_name()<<" is now owed "<<debtor1->get_amount_owed()<<endl;
    // cout<<"Creditor "<<creditor1->get_name()<<" is now owed "<<creditor1->get_amount_owed()<<endl;

    // AccountNodePtr debtor2 = find_next_debtor(debtor1);
    // cout<<"Debter is: "<<debtor2->get_name()<<" and is owed "<<debtor2->get_amount_owed()<<endl;
    // AccountNodePtr creditor2 = find_next_creditor(creditor1);
    // cout<<"Creditor is: "<<creditor2->get_name()<<" and is owed "<<creditor2->get_amount_owed()<<endl;
    // settle_transaction(debtor2, creditor2);
    // cout<<"Debter "<<debtor2->get_name()<<" is now owed "<<debtor2->get_amount_owed()<<endl;
    // cout<<"Creditor "<<creditor2->get_name()<<" is now owed "<<creditor2->get_amount_owed()<<endl;

    // AccountNodePtr debtor3 = find_next_debtor(debtor2);
    // cout<<"Debter is: "<<debtor3->get_name()<<" and is owed "<<debtor3->get_amount_owed()<<endl;
    // AccountNodePtr creditor3 = find_next_creditor(creditor2);
    // cout<<"Creditor is: "<<creditor3->get_name()<<" and is owed "<<creditor3->get_amount_owed()<<endl;
    // settle_transaction(debtor3, creditor3);
    // cout<<"Debter "<<debtor3->get_name()<<" is now owed "<<debtor3->get_amount_owed()<<endl;
    // cout<<"Creditor "<<creditor3->get_name()<<" is now owed "<<creditor3->get_amount_owed()<<endl;

    find_and_settle_all_transactions(head);

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

AccountNodePtr find_next_debtor(AccountNodePtr curr_node){
    AccountNodePtr iter = curr_node;
    //cout<<"find_next_debtor: "<<iter->get_name()<<" "<<iter->get_amount_owed()<<endl;
    while ((iter != nullptr) && iter->get_amount_owed()>=0){
        iter = iter -> get_link();
        //cout<<"find_next_debtor"<<iter->get_name()<<" "<<iter->get_amount_owed()<<endl;
    }
    return iter; //always check if this returns a nullptr;
}

AccountNodePtr find_next_creditor(AccountNodePtr curr_node){
    AccountNodePtr iter = curr_node;
    //cout<<"find_next_creditor"<<iter->get_name()<<endl;
    while ((iter != nullptr) && iter->get_amount_owed()<=0){
        iter = iter -> get_link();
        //cout<<"find_next_creditor"<<iter->get_name()<<endl;
    }
    return iter; //always check if this returns a nullptr;
}

void settle_transaction(AccountNodePtr debtor, AccountNodePtr creditor){
    // cout<<"settle transaction: "<<"Debtor name "<<debtor->get_name()<<" balance "<<debtor->get_amount_owed()<<endl;
    // cout<<"settle transaction: "<<"Creditor name "<<creditor->get_name()<<" balance "<<creditor->get_amount_owed()<<endl;
    if (debtor != nullptr && creditor != nullptr){
        double amount_settled = min(abs(debtor ->get_amount_owed()), abs(creditor-> get_amount_owed()));
        // cout<<"Settle transaction: amount "<<amount_settled<<endl;
        // cout<<"Settle transaction: debtor: "<<debtor->get_amount_owed()<<endl;
        double new_amount_debtor = debtor->get_amount_owed()+amount_settled;
        if (abs(new_amount_debtor) < 1e-9){
            new_amount_debtor = 0;
        }
        //cout<<"Settle transaction: amount settled + balance: "<<new_amount<<endl;
        debtor->set_amount_owed(new_amount_debtor);
        double new_amount_creditor = creditor->get_amount_owed()-amount_settled;
        if (abs(new_amount_creditor) < 1e-9){
            new_amount_creditor = 0;
        }
        creditor->set_amount_owed(new_amount_creditor);
        //cout<<"Settle transaction, debtor balance increased to: "<<debtor->get_amount_owed()<<endl;
        //cout<<"Settle transaction, creditor balance increased to: "<<creditor->get_amount_owed()<<endl;
        cout<<debtor->get_name()<<" pays "<<creditor->get_name()<<" $ "<<amount_settled<<endl;
    }    
}

void find_and_settle_all_transactions(AccountNodePtr head){
    AccountNodePtr debtor = find_next_debtor(head);
    AccountNodePtr creditor = find_next_creditor(head);
    cout<<debtor->get_name()<<endl;
    cout<<creditor->get_name()<<endl;

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
        //cout<<"New debtor"<<debtor->get_name()<<endl;
        //cout<<"New creditor"<<creditor->get_name()<<endl;
    }

    cout<<"In the end, you should have all spent: "<<endl;
}

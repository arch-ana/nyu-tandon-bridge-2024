#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

//Money class declarations
class Money{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount);

    friend bool operator ==(const Money& amount1, const Money& amount2);

    friend bool operator < (const Money& amount1, const Money& amount2);

    Money(long dollars, int cents);

    Money(long dollars);

    Money( );

    double get_value( ) const;

    friend istream& operator >>(istream& ins, Money& amount);

    friend ostream& operator <<(ostream& outs, const Money& amount);

private:
    long all_cents;
};

//Check class declarations
class Check{
    public:
        Check(int number, Money amount, bool isCashed);

        Check();

        int getNumber() const;

        Money getAmount() const;

        bool getIsCashed() const;

        void set(int number, Money amount, bool isCashed);

        friend istream& operator >>(istream& ins, Check& currCheck);

        friend ostream& operator <<(ostream& outs, const Check& currCheck);

    private:
        int checkNumber;
        Money checkAmount;
        bool checkIsCashed;
};

//Other function declarations
int digit_to_int(char c);
void sort(Check* userChecks, int numOfChecks);

int main( ){

    int numOfDeposits, numOfChecks;
    Money oldBalance, newBalance, sumUserDeposits, sumCashedChecks, sumUncashedChecks;

    cout<<"Please enter the number of checks: ";
    cin>>numOfChecks;
    
    Check* userChecks = new Check[numOfChecks];

    if (numOfChecks>0){
        cout<<"For each check, enter the check number, amount and encashment status (Eg: 1 $ab.cd y): "<<endl;
    }
    for (int i = 0; i < numOfChecks; i++){
        cin>>userChecks[i];
        if (userChecks[i].getIsCashed()){
            sumCashedChecks = sumCashedChecks + userChecks[i].getAmount();
        }
        else{
            sumUncashedChecks = sumUncashedChecks + userChecks[i].getAmount();
        }
    }
    if (numOfChecks == 0){
        sumCashedChecks = Money();
        sumUncashedChecks = Money();
    }

    cout<<endl;
    cout<<"Please enter the number of deposits you've made: ";
    cin>>numOfDeposits;

    Money* userDeposits = new Money[numOfDeposits];

    if (numOfDeposits>0){
        cout<<"For each deposit, enter deposit amounts in the form $ab.cd, each in a new line: "<<endl;
    }
    for (int i = 0; i < numOfDeposits; i++){
        cin>>userDeposits[i];
        sumUserDeposits = sumUserDeposits + userDeposits[i];
    }
    if (numOfDeposits==0){
        sumUserDeposits = Money();
    }

    cout<<endl;
    cout<<"Please enter your old balance in the form $ab.cd: "<<endl;
    cin>>oldBalance;

    newBalance = oldBalance + sumUserDeposits - sumCashedChecks;

    cout<<endl;
    cout<<"Total checks cashed is: "<<sumCashedChecks<<endl;
    cout<<"Total deposits is: "<<sumUserDeposits<<endl;
    cout<<"New balance is: "<<newBalance<<endl;
    cout<<"After accounting for uncashed checks, the balance will be: "<<newBalance-sumUncashedChecks<<endl;
    cout<<"The difference is: "<<sumUncashedChecks<<endl;

    cout<<endl;
    sort(userChecks, numOfChecks);
    if (numOfChecks>0){
        cout<<"Cashed checks in order of check number"<<endl;
    }
    for (int i = 0; i <numOfChecks; i++){
        if (userChecks[i].getIsCashed()){
            cout<<userChecks[i];
        }    
    }
    cout<<endl;
    if (numOfChecks>0){
        cout<<"Uncashed checks in order of check number"<<endl;
    }
    for (int i = 0; i <numOfChecks; i++){
        if (!userChecks[i].getIsCashed()){
            cout<<userChecks[i];
        }    
    }

    delete [] userChecks;
    delete [] userDeposits;

    return 0;
}

//Function implementations for Money
Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}

bool operator < (const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}

Money::Money(long dollars, int cents){
    if(dollars*cents < 0){ //one positive and one negative
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100){}

Money::Money( ) : all_cents(0){}

double Money::get_value( ) const{
    return (all_cents * 0.01);
}

istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-'){
        negative = true;
        ins >> one_char; //read '$'
    }
    else{
        negative = false;
    }
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;

    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

//Function implementations for Check
Check::Check(int number, Money amount, bool isCashed): checkNumber(number), checkAmount(amount), checkIsCashed(isCashed){}

Check::Check(): checkNumber(0), checkAmount(Money()), checkIsCashed(false){}

int Check::getNumber() const{
    return checkNumber;
}

Money Check::getAmount() const{
    return checkAmount;
}

bool Check::getIsCashed() const{
    return checkIsCashed;
}

void Check::set(int number, Money amount, bool isCashed){
    checkNumber = number;
    checkAmount = amount;
    checkIsCashed = isCashed;
}

istream& operator >>(istream& ins, Check& currCheck){
    int checkNumber;
    Money checkAmount;
    string checkCashed;

    ins>>checkNumber>>checkAmount>>checkCashed;

    if (checkNumber < 1 || checkAmount < 0.0 || (checkCashed != "y" && checkCashed != "n")){
        cout << "Error illegal form for check input\n";
        exit(1);
    }

    currCheck.checkNumber = checkNumber;
    currCheck.checkAmount = checkAmount;
    
    if (checkCashed == "y"){
        currCheck.checkIsCashed = true;
    }
    else{
        currCheck.checkIsCashed = false;
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Check& currCheck){

    outs<<"Check #"<<currCheck.checkNumber<<" "<<currCheck.checkAmount<<" ";
    if (currCheck.checkIsCashed){
        outs<<"Cashed"<<endl;
    }
    else{
        outs<<"Not cashed"<<endl;
    }

    return outs;
}

//Additional functions
int digit_to_int(char c){
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

void sort(Check* userChecks, int numOfChecks){

    Check temp; 

    for (int i = 0; i < numOfChecks - 1; i++){
        for (int j = 0; j < numOfChecks-i-1; j++){
            if ((*(userChecks+j)).getNumber() > (*(userChecks+j+1)).getNumber()){
                temp = *(userChecks+j);
                *(userChecks+j) = *(userChecks+j+1);
                *(userChecks+j+1) = temp;
            }
        }
    }
}


// CH12 #7: Write a checkbook balancing program. The program will read in, from the
// console, the following for all checks that were not cashed as of the last time you balanced your
// checkbook:
// - The number of each check (int)
// - The amount of the check (double)
// - Whether or not it has been cashed (1 or 0, boolean in the array)
// Use an array with the class as the type. The class should be a class for a check. There
// should be three member variables to record the check number, the check amount, and whether
// or not the check was cashed. The class for a check will have a member variable of type Money
// (as defined on page 662 in the book; Display 11.9) to record the check amount. So, you will
// have a class used within a class. The class for a check should have accessor and mutator
// functions as well as constructors and functions for both input and output of a check. In addition
// to the checks, the program also reads all the deposits (from the console; cin), the old and the
// new account balance (read this in from the user at the console; cin). You may want another
// array to hold the deposits. The new account balance should be the old balance plus all deposits,
// minus all checks that have been cashed.
// The program outputs the total of the checks cashed, the total of the deposits, what the new
// balance should be, and how much this figure differs from what the bank says the new balance
// is. It also outputs two lists of checks: the checks cashed since the last time you balanced your
// checkbook and the checks still not cashed. [edit: if you can, Display both lists of checks in
// sorted order from lowest to highest check number.]

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Money class declarations
class Money{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount 1 minus amount2.

    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.

    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.

    friend bool operator < (const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.

    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money( );
    //Initializes the object so its value represents $0.00.

    double get_value( ) const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.

    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in -$100.00.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.

private:
    long all_cents;
};


//Check class declarations
class Check{
    public:
        Check(int number, Money amount, bool isCashed);
        //Initializes the object so its value represents a check with
        //the checkNumber = number, checkAmount = amount and checkCashed = isCashed

        //Check(int number, long dollars, bool cashed);
        //Initializes the object so its value represents a check with
        //the checkNumber = number, checkAmount = $dollar.00 and checkCashed = isCashed

        Check();
        //Initializes the object so its value represents a check with
        //the checkNumber = 0, checkAmount = 0.0 given by Money() and checkCashed = false;

        int getNumber() const;
        //Returns the check number recorded in the data portion of the calling object

        Money getAmount() const;
        //Returns the amount recorded in the data portion of the calling object.

        bool getIsCashed() const;
        //Returns the cashing status recorded in the data portion of the calling object.

        friend istream& operator >>(istream& ins, Check& currCheck);
        //Overloads the >> operator so it can be used to input values of type
        //Check. Notation for inputting negative amounts is as in -$100.00.

        friend ostream& operator <<(ostream& outs, const Check& currCheck);
        //Overloads the << operator so it can be used to output values of type
        //Check. Precedes each output value of type Money with a dollar sign.

        friend bool operator >(const Check& checkLeft, const Check& checkRight);
        //Returns true if the check number of the check on the left side is greater than the one on the right

    private:
        int checkNumber;
        Money checkAmount;
        bool checkIsCashed;
};

//Other function declarations
int digit_to_int(char c);

int main( ){

    int numOfDeposits, numOfChecks;
    Money oldBalance, newBalance, sumUserDeposits, sumCashedChecks, sumUncashedChecks;

    cout<<"Please enter the number of checks: ";
    cin>>numOfChecks;
    
    Check* userChecks = new Check[numOfChecks];

    cout<<"For each check, enter the checkNumber (non-negative int) space checkAmount (non-negative double) space checkCashStatus (y or n)";
    for (int i = 0; i < numOfChecks; i++){
        cin>>userChecks[i];
        if (userChecks[i].getIsCashed()){
            sumCashedChecks = sumCashedChecks + userChecks;
        }
    }

    cout<<"Please enter the number of deposits you've made: ";
    cin>>numOfDeposits;

    Money* userDeposits = new Money[numOfDeposits];

    cout<<"For each deposit, enter the deposit amount in the for $ab.cd, separated by spaces: ";
    for (int i = 0; i < numOfDeposits; i++){
        cin>>userDeposits[i];
        sumUserDeposits = sumUserDeposits + userDeposits[i];
    }

    cout<<"Please enter your old balance in the form $ab.cd: ";
    cin>>oldBalance;



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

Money operator -(const Money& amount1, const Money& amount2)
{
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

double Money::get_value( ) const
{
    return (all_cents * 0.01);
}

istream& operator >>(istream& ins, Money& amount)
{
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

ostream& operator <<(ostream& outs, const Money& amount)
{
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

istream& operator >>(istream& ins, Check& currCheck){
    int checkNumber;
    double checkAmount;
    char checkCashed;

    ins>>checkNumber>>checkAmount>>checkCashed;

    if ( checkNumber < 0 || checkAmount < 0.0 || checkCashed != 'y' || checkCashed != 'n'){
        cout << "Error illegal form for check input\n";
        exit(1);
    }

    currCheck.checkNumber = checkNumber;
    currCheck.checkAmount = checkAmount;
    
    if (checkCashed == 'y'){
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

bool operator >(const Check& checkLeft, const Check& checkRight){
    return (checkLeft.checkNumber < checkRight.checkNumber);
}


//Additional functions
int digit_to_int(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}


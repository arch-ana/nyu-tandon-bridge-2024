#include <iostream>
using namespace std;

int main() {

    double price1, price2, taxRate, basePrice, offerPrice, afterTaxPrice;
    char clubCard;

    cout<<"Enter price of first item (input a non-negative price amount): ";
    cin>>price1;
    cout<<"Enter price of second item (input a non-negative price amount): ";
    cin>>price2;
    cout<<"Does customer have a club card (Y/N): ";
    cin>>clubCard;
    cout<<"Enter tax rate, e.g 5.5 for a 5.5% tax: ";
    cin>>taxRate;

    basePrice = (price1 + price2);

    // Calculates total cost of two items after discount is applied
    
    // In the case where prices of both items are equal, 
    // it does not matter which one is reduced to half. 
    // Hence, that case is being incorporated in the first if condition. 

    if (price1 >= price2) 
        offerPrice = (price1 + 0.5*price2);
    else
        offerPrice = (0.5*price1 + price2);

    //Calculates additional discount for club card owners

    if (clubCard == 'y' || clubCard == 'Y')
        offerPrice *= 0.9;

    //Adds taxes to the bill

    afterTaxPrice = offerPrice*(1 + (taxRate/100));

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout<<"Base price: "<<basePrice<<endl;
    cout<<"Price after discounts: "<<offerPrice<<endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout<<"Total price: "<<afterTaxPrice<<endl;

    return 0;
}


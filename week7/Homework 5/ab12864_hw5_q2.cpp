#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int randomNumber, userGuess, upperLimit, lowerLimit, numberOfGuesses;

    srand(time(0));
    randomNumber = (rand() % 100) +1;

    upperLimit = 100;
    lowerLimit = 1;
    numberOfGuesses = 5;
    
    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;

    while (numberOfGuesses > 1)
    {
        cout<<"Range : ["<<lowerLimit<<", "<<upperLimit<<"], Number of guesses left: "<<numberOfGuesses<<endl;
        cout<<"Your guess: ";
        cin>>userGuess;

        if (userGuess > randomNumber && userGuess <= upperLimit && userGuess >= lowerLimit)
        {
            upperLimit = userGuess - 1;
            numberOfGuesses -= 1;
            cout<<"Wrong, my number is smaller."<<endl;
        }
        else if (userGuess < randomNumber && userGuess <= upperLimit && userGuess >= lowerLimit)
        {
            lowerLimit = userGuess + 1;
            numberOfGuesses -= 1;
            cout<<"Wrong, my number is bigger."<<endl;
        }
        else if (userGuess < randomNumber && (userGuess > upperLimit || userGuess < lowerLimit))
        {
            numberOfGuesses -= 1;
            cout<<"Wrong, my number is bigger."<<endl;
        }
        else if (userGuess > randomNumber && (userGuess > upperLimit || userGuess < lowerLimit))
        {
            numberOfGuesses -= 1;
            cout<<"Wrong, my number is smaller."<<endl;
        }
        else
        {
            cout<<"Congrats! You guessed my number in "<<(5-(numberOfGuesses-1))<<" guesses"<<endl;
            numberOfGuesses = 0;
        }
        cout<<endl;

    }

    if (numberOfGuesses == 1)
    {
        cout<<"Range : ["<<lowerLimit<<", "<<upperLimit<<"], Number of guesses left: "<<numberOfGuesses<<endl;
        cout<<"Your guess: ";
        cin>>userGuess;

        if (userGuess == randomNumber)
        {
            cout<<"Congrats! You guessed my number in "<<(5-(numberOfGuesses-1))<<endl;
        }
        else
        {
            cout<<"Out of guesses! My number is "<<randomNumber<<endl;
        }
    }
    
    return 0;
}
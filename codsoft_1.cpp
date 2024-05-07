#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));

    
    int randomNumber = rand() % 100 + 1;

    
    int guess;
    int attempts = 0;

    
    do 
    {
        
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;
        attempts++;

        
        if (guess == randomNumber) 
        {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        } 
        else if (guess < randomNumber) 
        {
            std::cout << "Too low! Try again." << std::endl;
        } 
        else 
        {
            std::cout << "Too high! Try again." << std::endl;
        }

        
    } while (guess != randomNumber);

    return 0;
}

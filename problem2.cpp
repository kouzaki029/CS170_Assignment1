#include <cmath>
#include <iostream>
#include <random>
using std::cin, std::cout, std::numeric_limits, std::streamsize, std::string;

int main()
{
    int marble = -1;
    int computerTurn = 0;
    int playerTurn = 0;
    bool done = false;
    string currentPlayer = "";

    while(!done)
    {
        cout << "Enter marble quantity: ";
        cin >> marble;

        do
        {
            if (marble == -1)
            {
                cout << "Enter marble quantity (i.e., 10 to 100): ";
                cin >> marble;
            }
            else if(cin.fail() || marble == 0 || marble > 100 || marble < 10)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Entry.\n";
                cout << "Enter marble quantity (i.e., 10 to 100): ";
                cin >> marble;
            }
        }while(cin.fail() || marble == -1 || marble > 100 || marble < 10);

        string gameMode = "";
        cout << "Please select playing mode (i.e., simple or smart): ";
        cin >> gameMode;

        while(!cin.fail() && marble > 1)
        {
            if(gameMode == "simple" || gameMode == "Simple" || gameMode == "smart" || gameMode == "Smart" && marble > 1)
            {
                while(currentPlayer == "" || cin.fail())
                {
                    cout << "Please select who is player #1 (i.e., computer or me): ";
                    cin >> currentPlayer;
                }

                while(currentPlayer == "computer" || currentPlayer == "Computer" && (gameMode == "smart" || gameMode == "Smart"))
                {
                    //the number of marbles is currently one less than a power of 2
                    if (marble == (log2(3) + 1))
                    {
                        //computer takes a random number between 1 and marbles/2
                        computerTurn = rand() % (marble/2) + 1;
                        //the random number for computerTurn isn't one less than a power of 2, then regenerate the random number until it is
                        while(computerTurn != (log2(3) + 1))
                        {
                            computerTurn = rand() % (marble/2) + 1;
                        }

                        cout << "The computer takes " << computerTurn << " marbles.\n";

                        //subtract the total number of marbles
                        marble -= computerTurn;
                        cout << "There are " << marble << " marbles left.\n\n";
                    }
                    //the number of marbles is currently a power of 2
                    else
                    {
                        //computer takes a random number between 1 and marbles/2
                        computerTurn = rand() % (marble/2) + 1;
                        cout << "The computer takes " << computerTurn << " marbles.\n";

                        //subtract the total number of marbles
                        marble -= computerTurn;
                        cout << "There are " << marble << " marbles left.\n\n";
                    }
                    
                    currentPlayer = "me";
                }
                while(currentPlayer == "computer" || currentPlayer == "Computer" && (gameMode == "simple" || gameMode == "Simple"))
                {
                    //computer takes a random number between 1 and marbles/2
                    computerTurn = rand() % (marble/2) + 1;
                    cout << "The computer takes " << computerTurn << " marbles.\n";

                    //subtract the total number of marbles
                    marble -= computerTurn;
                    cout << "There are " << marble << " marbles left.\n\n";

                    currentPlayer = "me";
                }
                while(marble > 1 && (currentPlayer == "me" || currentPlayer == "Me"))
                {
                    cout << "How many marbles would you like to draw?: ";
                    cin >> playerTurn;

                    //player entered too small of a number, or too large of a number
                    while(playerTurn < 1 || playerTurn > marble/2)
                    {
                        cin.clear();
                        cout << "Invalid Entry.\n";
                        cout << "Please enter a number between 1 and " << marble/2 << ".\n";
                        cout << "How many marbles would you like to draw?: ";
                        cin >> playerTurn;
                    }
                    //subtract the total number of marbles
                    marble -= playerTurn;
                    cout << "There are " << marble << " marbles left.\n\n";

                    currentPlayer = "computer";
                }

                if(currentPlayer != "computer" && currentPlayer != "me" && currentPlayer != "Computer" && currentPlayer != "Me")
                {
                    cin.clear();
                    cout << "Invalid Entry.\n";
                    currentPlayer = "";
                }
            }
            else
            {
                cin.clear();
                cout << "Invalid Entry.\n";
                cout << "Please select playing mode (i.e., simple or smart): ";
                cin >> gameMode;
            }
        }

        //game is over
        if (currentPlayer == "computer")
            cout << "You win!\n";
        else
            cout << "The computer wins.\n";
        done = true;
    }


    return 0;
}

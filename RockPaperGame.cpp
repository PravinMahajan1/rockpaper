#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string getComputerChoice() {
    int random = rand() % 3;
    switch (random) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "Rock";
    }
}

string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    }
    
    if ((userChoice == "Rock" && computerChoice == "Scissors") ||
        (userChoice == "Paper" && computerChoice == "Rock") ||
        (userChoice == "Scissors" && computerChoice == "Paper")) {
        return "You win!";
    }
    
    return "Computer wins!";
}

string formatChoice(string choice) {
    if (choice.empty()) return "";
    string formatted = choice;
    formatted[0] = toupper(formatted[0]);
    for (size_t i = 1; i < formatted.length(); i++) {
        formatted[i] = tolower(formatted[i]);
    }
    return formatted;
}

int main() {

    srand(time(0));
    
    string userChoice, computerChoice;
    char playAgain;
    
    do {
        
        cout << "\033[2J\033[1;1H";
    
        cout << "Rock, Paper, Scissors Game\n";
        cout << "Enter your choice (rock/paper/scissors): ";
        cin >> userChoice;
        
      
        userChoice = formatChoice(userChoice);

        if (userChoice != "Rock" && userChoice != "Paper" && userChoice != "Scissors") {
            cout << "Invalid choice! Please choose rock, paper, or scissors.\n";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }
        
        computerChoice = getComputerChoice();
        cout << "\nYour choice: " << userChoice << endl;
        cout << "Computer's choice: " << computerChoice << endl;
        cout << determineWinner(userChoice, computerChoice) << endl;
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to print 1D array
void printArray(int arr[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Mini number-guessing game
void numberGuessingGame() {
    const int MAX_ATTEMPTS = 5;
    int guesses[MAX_ATTEMPTS];
    int secret, guess;
    bool won = false;

    srand(time(0));
    secret = rand() % 10 + 1;

    cout << "\n🎮 Guess the number between 1 and 10 (Max " << MAX_ATTEMPTS << " tries):\n";

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        cout << "Attempt " << i + 1 << ": ";
        cin >> guess;
        guesses[i] = guess;

        if (guess == secret) {
            cout << "✅ Correct! You guessed it in " << i + 1 << " attempts.\n";
            won = true;
            break;
        } else {
            cout << "❌ Wrong guess.\n";
        }
    }

    if (!won) {
        cout << "🔴 Sorry, the correct number was " << secret << ".\n";
    }

    cout << "Your guesses: ";
    printArray(guesses, MAX_ATTEMPTS);
}

int main() {
    // 1D Array
    int scores[] = {88, 92, 76, 81, 95};
    printArray(scores, 5);

    // 2D Array
    int matrix[2][2] = {
        {1, 2},
        {3, 4}
    };

    cout << "\n2D Array (Matrix):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Game
    numberGuessingGame();

    return 0;
}

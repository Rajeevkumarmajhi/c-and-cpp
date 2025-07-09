#include <iostream>
#include <random>
#include <limits>

int main() {
    constexpr int kMaxAttempts = 5;
    constexpr int kMinNumber = 1;
    constexpr int kMaxNumber = 100;

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(kMinNumber, kMaxNumber);

    int secretNumber = distrib(gen);
    int guess;

    std::cout << "🎯 Welcome to Guess the Number Game!\n";
    std::cout << "I'm thinking of a number between " << kMinNumber << " and " << kMaxNumber << ".\n";
    std::cout << "You have " << kMaxAttempts << " attempts to guess it correctly.\n\n";

    for (int attempt = 1; attempt <= kMaxAttempts; ++attempt) {
        std::cout << "Attempt " << attempt << "/" << kMaxAttempts << " - Enter your guess: ";

        // Input validation
        while (!(std::cin >> guess) || guess < kMinNumber || guess > kMaxNumber) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "⚠️  Please enter a valid number between " << kMinNumber << " and " << kMaxNumber << ": ";
        }

        if (guess == secretNumber) {
            std::cout << "🎉 Congratulations! You guessed it right. The number was " << secretNumber << ".\n";
            return 0;
        } else if (guess < secretNumber) {
            std::cout << "🔻 Your guess is too low.\n\n";
        } else {
            std::cout << "🔺 Your guess is too high.\n\n";
        }
    }

    std::cout << "❌ Sorry, you've used all your attempts. The number was " << secretNumber << ". Better luck next time!\n";
    return 0;
}

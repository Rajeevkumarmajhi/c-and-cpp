#include <graphics.h>
#include <iostream>
#include <sstream>
#include <random>

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initwindow(640, 480, "Guess The Number Game");

    // Game constants
    constexpr int kMaxAttempts = 5;
    constexpr int kMinNumber = 1;
    constexpr int kMaxNumber = 100;

    // RNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(kMinNumber, kMaxNumber);
    int secretNumber = distrib(gen);

    int attempt = 0;
    int guess = 0;
    bool won = false;

    while (attempt < kMaxAttempts && !won) {
        cleardevice();

        // Title
        settextstyle(3, 0, 3);
        outtextxy(100, 50, (char*)"🎯 Guess The Number!");

        // Attempt info
        std::stringstream ss;
        ss << "Attempt " << (attempt + 1) << " of " << kMaxAttempts;
        outtextxy(100, 100, (char*)ss.str().c_str());

        // Prompt
        outtextxy(100, 150, (char*)"Enter your guess (1-100): ");

        // Simulate textbox input
        char input[4] = "";
        int i = 0;
        while (true) {
            char ch = getch();
            if (ch == 13) break; // Enter key
            if (ch >= '0' && ch <= '9' && i < 3) {
                input[i++] = ch;
                input[i] = '\0';
                outtextxy(400, 150, input);
            } else if (ch == 8 && i > 0) { // Backspace
                i--;
                input[i] = '\0';
                setfillstyle(SOLID_FILL, BLACK);
                bar(400, 150, 460, 170);
                outtextxy(400, 150, input);
            }
        }

        guess = atoi(input);

        // Check guess
        if (guess == secretNumber) {
            won = true;
        } else {
            attempt++;
            if (guess < secretNumber) {
                outtextxy(100, 200, (char*)"🔻 Too low!");
            } else {
                outtextxy(100, 200, (char*)"🔺 Too high!");
            }
            delay(1000);
        }
    }

    cleardevice();
    if (won) {
        settextstyle(3, 0, 3);
        outtextxy(100, 200, (char*)"🎉 You guessed it!");
    } else {
        std::stringstream ss2;
        ss2 << "❌ The number was " << secretNumber;
        settextstyle(3, 0, 3);
        outtextxy(100, 200, (char*)ss2.str().c_str());
    }

    getch();
    closegraph();
    return 0;
}

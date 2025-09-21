#include <iostream>
#include <string>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds

void displayProgressBar(int progress, int total, int barWidth = 50) {
    float percentage = static_cast<float>(progress) / total;
    int filledWidth = static_cast<int>(barWidth * percentage);

    std::cout << "\r["; // Carriage return to move cursor to beginning of line
    for (int i = 0; i < barWidth; ++i) {
        if (i < filledWidth) {
            std::cout << "=";
        } else if (i == filledWidth) {
            std::cout << ">"; // Indicator for the current progress
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << static_cast<int>(percentage * 100) << "%";
    std::cout.flush(); // Ensure the output is immediately written to the console
}

int main() {
    int totalSteps = 100;

    for (int i = 0; i <= totalSteps; ++i) {
        displayProgressBar(i, totalSteps);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
    std::cout << std::endl; // New line after the progress bar is complete

    return 0;
}

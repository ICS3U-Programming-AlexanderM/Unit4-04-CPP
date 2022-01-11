// Copyright (c) 2022 Alexander Matheson All rights reserved.
//
// Created by: Alexander matheson
// Created on: Jan 11 2022
// This program gets the user to guess a number
// between 0 and 9 and tells them if it is correct.
// If the guess is incorrect, the progran is looped.
#include <iostream>
#include <random>


int main() {
    // this function checks the user's number
    std::string userString;
    int correct;
    int userNumber;

    std::random_device rseed;

    std::mt19937 rgen(rseed());

    std::uniform_int_distribution<int> idist(0, 9);

    correct = idist(rgen);

    // loop
    while (true) {
        // Get user's guess
        std::cout << "Enter your number: ";
        std::getline(std::cin, userString);

        // error cheking
        try {
            userNumber = std::stoi(userString);

            // check number size
            if (userNumber == correct) {
                // for correct
                std::cout << "Correct!";
                break;
            } else if (userNumber >= 10) {
                std::cout << "Number must be between 0 and 9.\n";
            } else if (userNumber <= -1) {
                std::cout << "Number must be between 0 and 9.\n";
            } else {
                std::cout << "Incorrect.\n";
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid input.\n";
        }
    }
}

/* Program name: Grade Statistics 
Author: Heritage Adigun
Date last updated: 06/24/2024
Purpose: A program that analyzes a student's quiz scores.*/


#include <iostream>

const int NUM_MODULES = 16;

//Function to prompt quiz scores from the user
void getData(int quizScores[NUM_MODULES]) {
    std::cout << "Enter quiz scores for each module (0-15):\n";
    for (int i = 0; i < NUM_MODULES; ++i) {
        std::cout << "Module " << (i + 1) << ": ";
        std::cin >> quizScores[i];
    }
}

//Function to find the module with the highest score
int highScore(const int quizScores[NUM_MODULES]) {
    int maxIndex = 0;
    for (int i = 1; i < NUM_MODULES; ++i) {
        if (quizScores[i] > quizScores[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex + 1; //Adding 1 to make it module number 
}

//Function to find the module with the lowest score
int lowScore(const int quizScores[NUM_MODULES]) {
    int minIndex = 0;
    for(int i = 1; i < NUM_MODULES; ++i) {
        if (quizScores[i] < quizScores[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex + 1; //Adding 1 to make it module number 
}

int main() {
    int quizScores[NUM_MODULES];

    //Get quiz scores from the user
    getData(quizScores);

    //Find highest & lowest scores
    int highestModule = highScore(quizScores);
    int lowestModule = lowScore(quizScores);

    //Cal avg score
    int sum = 0;
    for (int i = 0; i < NUM_MODULES; ++i) {
        sum+= quizScores[i];
    }
    double average = static_cast<double>(sum) / NUM_MODULES;

    //Output
    std::cout << "\nFall 2019 Quiz Grades:\n";
    for (int i = 0; i < NUM_MODULES; ++i) {
        std::cout << "Module " << (i + 1) << ": " << quizScores[i] << '\n';
    }
    std::cout << "Average Grade: " << int(average) << '\n';
    std::cout << "Your lowest score was in Module " << lowestModule << " with " << quizScores[lowestModule - 1] << ".\n";
    std::cout << "Your highest score was in Module " << highestModule << " with " << quizScores[highestModule - 1] << ".\n";
    return 0;
}
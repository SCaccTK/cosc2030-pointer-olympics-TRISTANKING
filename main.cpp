#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std; 

// Function prototypes
void sortScores(double* scores, int numScores);
double calculateAverage(double* scores, int numScores);
void awardMedals(double* scores, int numScores);
void displayResults(double* scores, int numScores, double average);

int main() {
    // Get number of scores from user
    int numScores;
    cout << "=== Olympic Scores Program ===\n";

    cout << "how many athletes?: ";
    cin >> numScores;
    double* scores = new double[numScores]; // Dynamically allocate array for scores

    cout << "\nEnter the scores of " << numScores << "atheletes:\n";
    for (int i = 0; i < numScores; ++i)
    {
        cout << " Athelete " << (i + 1) << ": ";
        cin >> *(scores +i);
    }

    sortScores(scores, numScores);
    double average = calculateAverage(scores, numScores);
    awardMedals(scores, numScores);
    displayResults(scores, numScores, average);
    delete[] scores;
    return 0;

}


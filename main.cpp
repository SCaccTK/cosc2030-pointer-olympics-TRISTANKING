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

    cout << "\nEnter the scores of " << numScores  << " atheletes:\n";
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

void awardMedals(double* scores, int numScores)
{
    cout << "\n=== Medal Ceremony ===\n";
    if (numScores >= 3)
    {
        cout << "Gold : " << *(scores + (numScores -1)) << '\n'; //best rewaRD
        cout << "Silver : " << *(scores + (numScores -2)) << '\n'; // 2ND PLACE
        cout << "Bronze : " << *(scores + (numScores -3)) << '\n'; // LAST PLACE but not really
    }
    else 
    cout << "not enough medals for contestants";
}

void sortScores(double* scores, int numScores)
{
    for (int i = 0; i < numScores -1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < numScores; ++j)
        {
            if (*(scores + j) < *(scores + minIndex))
                minIndex = j;
        }

        if (minIndex != i)
        {
            double temp = *(scores + i);
            *(scores + i) = *(scores + minIndex);
            *(scores + minIndex) = temp;
        }
    }
}

double calculateAverage(double* scores, int numScores)
{
    double sum = 0.0;
    for (int i = 0; i < numScores; ++i)
        sum += *(scores + i);
    return sum / numScores;
}

void displayResults(double* scores, int numScores, double average)
{
    cout << "\n=== Sorted Scores (Ascending) ===\n";
    cout << "RANK   ATHELETE    SCORE\n";
    for (int i = numScores - 1; i >= 0; --i)
    {
        cout << (numScores - i)
            << "\tAthelete " << (i + 1)
            << "\t"
            << fixed << setprecision(2)
            << *(scores + i) << '\n';
    }
}
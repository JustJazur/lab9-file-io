/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 9 - File I/O
 * Description: [program that reads the readiness report and analyzes the motor current data]
 * Due Date: [10/18/2026]
 */

#include <fstream>                                       // Provides ifstream and ofstream for file access
#include <iomanip>                                       // Provides fixed and setprecision
#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

double calculateAverage(double total, int count);
bool isWithinLimit(double average, double maximum);

int main() {                                             // Starts the program
    int requestedSamples;                                // Stores the number of readings requested by the user
    int samplesRead = 0;                                 // Counts readings successfully read from the file
    double maximumCurrent;                               // Stores the allowed average-current limit
    double currentReading;                               // Stores one current reading at a time
    double totalCurrent = 0.0;                           // Accumulates the readings obtained from the file
    double averageCurrent;                               // Stores the average returned by a function

    cout << "Enter the number of samples to analyze: ";
    if (!(cin >> requestedSamples) || requestedSamples <= 0) {
        cout << "Error: Enter a positive number of samples." << endl;
        return 1;
    }
    cout << "Enter the maximum allowed average current: ";
    if (!(cin >> maximumCurrent) || maximumCurrent < 0.0) {
        cout << "Error: Enter a non-negative maximum current." << endl;
        return 1;
    }

    ofstream outputFile("motor_current_readings.txt");
    if (!outputFile) {
        cout << "Error: Could not create the output file." << endl;
        return 1;
    }

    for (int sample = 0; sample < requestedSamples; sample++) {
        cout << "Enter current reading " << sample + 1 << ": ";
        if (!(cin >> currentReading) || currentReading < 0.0) {
            cout << "Error: Enter a non-negative current reading." << endl;
            outputFile.close();
            return 1;
        }
        outputFile << currentReading << endl;
    }

    outputFile.close();
    if (!outputFile) {
        cout << "Error: Could not write all current readings to the output file." << endl;
        return 1;
    }

    ifstream inputFile("motor_current_readings.txt");
    if (!inputFile) {
        cout << "Error: Could not open the input file." << endl;
        return 1;
    }

    while (inputFile >> currentReading) {
        totalCurrent += currentReading;
        samplesRead++;
    }

    averageCurrent = calculateAverage(totalCurrent, samplesRead);

    cout << "Readings successfully read: " << samplesRead << endl;
    cout << "Average Current: " << fixed << setprecision(2) << averageCurrent << endl;
    if (isWithinLimit(averageCurrent, maximumCurrent)) {
        cout << "Average current is within the limit." << endl;
    } else {
        cout << "Average current exceeds the limit." << endl;
    }

    inputFile.close();

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

double calculateAverage(double total, int count) {
    if (count == 0) {
        return 0.0;
    }
    return total / count;
}

bool isWithinLimit(double average, double maximum) {
    return average <= maximum;
}

/*
 * Analysis:
 * 1. Why does the average function return double instead of int?
 * because double is more precise since it has decimal values.
 * 2. What exact comparison makes the Boolean function return true?
 * the comparison that makes the Boolean function return true is when the average is less than or equal to the maximum.
 * 3. Why is samplesRead more reliable than requestedSamples for calculating the average?
 * samplesReadis better because it actually reads the lines fromthe files and does not give incomplete information.
 * 4. Why must the output stream close before the input stream opens the same file?
 * because the output stream needs to finish writing to the file before the input stream can read from it, otherwise it may not read all the data.
 */
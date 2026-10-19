/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 9 - File I/O
 * Description: [program that reads the readiness report]
 * Due Date: [10/18/2026]
 */

#include <fstream>                                       // Provides ifstream for file input
#include <iostream>                                      // Provides cout and endl
#include <string>                                        // Provides the string data type
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    ifstream inputFile("lab_readiness_report.txt");     // Prepares the existing report for input
    string line;                                         // Stores one complete line read from the file

    // TODO: Test whether inputFile opened successfully and handle an error in English.
    if (!inputFile) {
        cout << "Error: Could not open the report file." << endl; // Reports an opening failure in English
        return 1;                                       // Ends the program with an error status
    }                                                    // Ends the input-file validation
    // TODO: Display a terminal heading before reading the report contents.
    cout << "Lab Readiness Report" << endl;
    // TODO: Use getline in a while loop to display each line from the report.
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    // TODO: Close the input stream after all lines have been processed.
    inputFile.close();

    return 0;                                            // Ends the program successfully
}           

/*
 * Analysis:
 * 1. Why does this program use ifstream instead of ofstream?
 * because ifstream is to read the files on a stream.
 * 2. What causes the while loop to stop?
 * the while loop stops once it has gotten all the lines from the text it was reading from.
 * 3. Why must the program test the input stream before reading?
 * Because we are using c++ and it follows a chain of actions, if we put the file at the start of
 * the code it will be able to read it once it is called later in the if and while loop.
 */
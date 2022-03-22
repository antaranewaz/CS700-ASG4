/**
 *  file: main.cpp
 *  author: Antara Newaz <anc812@uregina.ca>
 *  version: 0.1
 *  date-created: 12-mar-2022
 *  lat-modified: 20-mar-2022
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <time.h>

using namespace std;

/**
 * ascendingShakerSort
 * Purpose: This function reads number data from a file and sorts the numbers in ascending order
 * Parameter(s): N/A
 * Precondition(s): 
 *      <1> random_generation.txt must be located in the root directory of this application
 * Returns: N/A
 * Side effect: N/A
 */

void ascendingShakerSort() {
    string fileData;
    vector<int> arr;

    // read from file, and convert and store to vector
    ifstream readFile("./random_generation.txt");

    while (getline(readFile, fileData)) {
        int data = stoi(fileData);
        arr.push_back(data);
    }

    readFile.close();

    int temp;
    bool swap = true;

    clock_t startTime = clock(); // clock start time

    // ascending sort
    while (swap) {
        swap = false;

        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] > arr[i+1]) {
                swap = true;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }

        if (!swap) break;
        
        swap = false;

        for (int i = arr.size()-2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                swap = true;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    string timeTaken = to_string((double)(clock() - startTime) / CLOCKS_PER_SEC); // clock end time and total time of execution

    stringstream result;
    copy(arr.begin(), arr.end(), std::ostream_iterator<int>(result, "\n"));

    // write to file
    ofstream createFile("./ascending_order.txt");
    createFile << result.str();
    createFile << "\nExecution Time: " << timeTaken << "s";
    createFile.close();

    cout << "\nAscending Order file created. Time taken for execution: " << timeTaken << "s" << endl;
}

/**
 * descendingShakerSort
 * Purpose: This function reads number data from a file and sorts the numbers in descending order
 * Parameter(s): N/A
 * Precondition(s): 
 *      <1> random_generation.txt must be located in the root directory of this application
 * Returns: N/A
 * Side effect: N/A
 */

void descendingShakerSort() {
    string fileData;
    vector<int> arr;

    // read from file, and convert and store to vector
    ifstream readFile("./random_generation.txt");

    while (getline(readFile, fileData)) {
        int data = stoi(fileData);
        arr.push_back(data);
    }

    readFile.close();

    int temp;
    bool swap = true;

    clock_t startTime = clock(); // clock start time

    // descending sort
    while (swap) {
        swap = false;

        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] < arr[i+1]) {
                swap = true;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }

        if (!swap) break;
        
        swap = false;

        for (int i = arr.size()-2; i >= 0; i--) {
            if (arr[i] < arr[i+1]) {
                swap = true;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    string timeTaken = to_string((double)(clock() - startTime) / CLOCKS_PER_SEC); // clock end time and total time of execution

    stringstream result;
    copy(arr.begin(), arr.end(), std::ostream_iterator<int>(result, "\n"));

    // write to file
    ofstream createFile("./descending_order.txt");
    createFile << result.str();
    createFile << "\nExecution Time: " << timeTaken << "s";
    createFile.close();

    cout << "\nDescending Order file created. Time taken for execution: " << timeTaken << "s" << endl;
}

/**
 * randomGeneration
 * Purpose: This function generates random numbers and writes them to a text file
 * Parameter(s): 
 *      <1> vectorSize: an integer type variable for storing that amount of vector elements
 * Precondition(s): 
 *      <1> parameter must receive data of type integer
 * Returns: N/A
 * Side effect: N/A
 */

void randomGeneration(int vectorSize) {
    vector<string> arr;

    for (int i = 0; i < vectorSize; i++) {
        arr.push_back(to_string(rand() % vectorSize));
    }

    ofstream createFile("./random_generation.txt");
    ostream_iterator<string> output_iterator(createFile, "\n");
    copy(arr.begin(), arr.end(), output_iterator);
    createFile.close();

    cout << "Random numbers generated and file created." << endl;
}

/**
 * userPrompt
 * Purpose: This function takes in the size for creating vectors elements from the user
 * Parameter(s): N/A
 * Precondition(s): 
 *      <1> user must input an integer value
 * Returns: N/A
 * Side effect: N/A
 */

void userPrompt() {
    int vectorSize;

    cout << "Enter vector size: ";
    cin >> vectorSize;

    randomGeneration(vectorSize);
}

// driver
int main() {

    userPrompt();

    ascendingShakerSort();

    descendingShakerSort();

    return 0;
}
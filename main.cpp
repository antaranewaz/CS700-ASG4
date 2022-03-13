/*
 *  file: main.cpp
 *  author: Antara Newaz <anc812@uregina.ca>
 *  version: 0.1
 *  date-created: mar-13-2022
 *  last modified: mar-13-2022
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <time.h>

using namespace std;

// shaker sort algorithm - ascending order
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
}

// randomly generate vector elements
void randomGeneration(int vectorSize) {
    vector<string> arr;

    for (int i = 0; i < vectorSize; i++) {
        arr.push_back(to_string(rand() % vectorSize));
    }

    ofstream createFile("./random_generation.txt");

    ostream_iterator<string> output_iterator(createFile, "\n");

    copy(arr.begin(), arr.end(), output_iterator);

    createFile.close();
}

// prompt user for vector size
void userPrompt() {
    int vectorSize;

    cout << "Enter vector size: ";
    cin >> vectorSize;

    randomGeneration(vectorSize);
}

int main() {
    userPrompt();

    ascendingShakerSort();

    return 0;
}
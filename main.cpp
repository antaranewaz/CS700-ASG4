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

using namespace std;

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

    return 0;
}
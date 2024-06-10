//
// Created by Momchil Tsanov on 8.06.24.
//

#include "Maps&Sets.h"


void countSameValues() {

    map<double, int> numbers;
    vector<double> order;
    double curNum;
    int timesFound = 1;
    string input;
    getline(cin, input);
    istringstream iss(input);

    while (iss >> curNum) {

        if (numbers.find(curNum) == numbers.end()) {
            order.push_back(curNum);
        }
        auto it = numbers.find(curNum);
        if (it != numbers.end()) {
            it->second++;
        }
        numbers.insert(pair<double, int> {curNum, timesFound});

    }

    for (double num : order) {
        cout << num << " - " << numbers[num] << " times" << endl;
    }


}
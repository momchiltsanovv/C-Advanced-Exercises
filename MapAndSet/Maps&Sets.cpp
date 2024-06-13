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

void averageStudentGrade() {

    int input;
    cin >> input;

    map<string, vector<double> > studentNameAndGrades;

    string curName;
    double curGrade;

    for (int i = 0; i < input; ++i) {
        cin >> curName >> curGrade;
        studentNameAndGrades[curName].push_back(curGrade);
    }

    for (const auto& entry: studentNameAndGrades) {
        cout << entry.first << " -> ";
        for (const auto& grade: entry.second) {
            cout << setprecision(2) << fixed << grade << " ";
        }
        double curStudentSumOfGrades = 0;
        double curStudentAverageGrade = 0;
        for (auto & grade : entry.second) {
            curStudentSumOfGrades += grade;
            curStudentAverageGrade = curStudentSumOfGrades / entry.second.size();
        }
        cout << "(avg: " << setprecision(2) << fixed << curStudentAverageGrade << ")" << endl;
    }


}
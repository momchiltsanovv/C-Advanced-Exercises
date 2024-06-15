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
        numbers.insert(pair<double, int>{curNum, timesFound});

    }

    for (const double& num: order) {
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
        for (auto& grade: entry.second) {
            curStudentSumOfGrades += grade;
            curStudentAverageGrade = curStudentSumOfGrades / entry.second.size();
        }
        cout << "(avg: " << setprecision(2) << fixed << curStudentAverageGrade << ")" << endl;
    }


}

void citiesByContinentAndCountry() {

    map<string, map<string, vector<string> > > citiesByContinentAndCountry;

    int lines;
    cin >> lines;

    for (int i = 0; i < lines; ++i) {
        string continent, country, city;
        cin >> continent >> country >> city;
        citiesByContinentAndCountry[continent][country].push_back(city);
    }

    for (auto& continent: citiesByContinentAndCountry) {
        cout << continent.first << ":" << endl;
        for (auto& country: continent.second) {
            cout << "  " << country.first << " -> ";
            for (auto& city: country.second) {
                sort(country.second.begin(), country.second.end());

                if (city != country.second.back()) {
                    cout << city << ", ";
                } else {
                    cout << city;
                }
            }
            cout << endl;
        }

    }

}

void recordUniqueNames() {
    int inputCount = 0;
    cin >> inputCount;

    unordered_set<string> uniqueNames;
    vector<string> order;// vector to store the order of input

    for (int i = 0; i < inputCount; i++) {
        string name;
        cin >> name;
        if (uniqueNames.find(name) ==
            uniqueNames.end()) { //find returns end iterator to uniqueNames.end() if not found.
            order.push_back(name); // adding it to the orders if its not found in uniqueNames
        }
        uniqueNames.insert(name);
    }

    for (const auto& name: order) {
        cout << name << endl;
    }
}

void parkingLot() {

    string command;
    cin >> command;

    set<string> cars;
    vector<string> order;
    while (command != "END") {
        string curCar;
        if (command == "IN,") {
            cin >> curCar;
            if (cars.find(curCar) == cars.end()) {
                order.push_back(curCar);
            }
            cars.insert(curCar);
        } else if (command == "OUT,") {
            cin >> curCar;
            cars.erase(curCar);
        }
        cin >> command;
    }


    if (cars.empty()) {
        cout << "Parking Lot is Empty" << endl;
    }

    for (const auto& car: cars) {
        cout << car << endl;
    }
}

void uniqueUsernames() {
    int inputCount = 0;
    cin >> inputCount;

    set<string> uniqueUsername;

    for (int i = 0; i < inputCount; i++) {
        string name;
        cin >> name;
        uniqueUsername.insert(name);
    }

    for (const auto& name: uniqueUsername) {
        cout << name << endl;
    }
}

void setOfElements() {

    int n, m;
    cin >> n >> m;

    set<int> firstSet, secondSet;

    for (int i = 0; i < n; ++i) {
        int curElement;
        cin >> curElement;
        firstSet.insert(curElement);
    }
    for (int i = 0; i < m; ++i) {
        int curElement;
        cin >> curElement;
        secondSet.insert(curElement);
    }

    set<int> bothContains;
    for (const int& element: firstSet) {
        if (secondSet.find(element) != secondSet.end()) {
            bothContains.insert(element);
        }
    }

    for (const int& i: bothContains) {
        cout << i << " ";
    }

}

void periodicTable() {

    int linesInput;
    cin >> linesInput;
    cin.ignore();

    set<string> elements;

    for (int i = 0; i < linesInput; ++i) {
        string chemicals;
        getline(cin, chemicals);
        istringstream iss(chemicals);
        while (iss >> chemicals) {
            elements.insert(chemicals);
        }
    }

    for (const string& element: elements) {
        cout << element << " ";
    }
}

void evenTimes() {

    int lines;
    cin >> lines;

    map<int, int> collection;
    for (int i = 0; i < lines; i++) {
        int number;
        cin >> number;
        collection[number]++;
    }

    for (auto i : collection) {

        if (i.second % 2 == 0) {
            cout << i.first << " ";
        }

    }


}

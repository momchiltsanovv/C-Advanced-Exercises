//#include "StacksAndQueues/Stack&Queues.h"
//#include "MapAndSet/Maps&Sets.h"


#include <iostream>
#include <map>
#include <string_view>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <vector>

using std::map;
using std::unordered_map;
using std::set;
using std::pair;
using std::vector;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;




void averageStudentGrade() {

    map<string, vector<double>> numbers;
    string curStudent;
    int timesFound = 1;
    string input;
    getline(cin, input);
    istringstream iss(input);

    while (iss >> curStudent) {


        auto it = numbers.find(curStudent);
        if (it != numbers.end()) {
            it->second++;
        }
        numbers.insert(pair<double, int> {curStudent, timesFound});

    }

    for (double num : `) {
        cout << num << " - " << numbers[num] << " times" << endl;
    }


}


int main() {

    averageStudentGrade();
    return 0;
}

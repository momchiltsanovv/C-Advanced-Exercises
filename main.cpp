#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <climits>


using std::vector;
using std::stack;
using std::queue;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

#pragma startup

vector<string> readIntput() {
    vector<string> words;
    string input;
    getline(cin, input);
    istringstream iss(input);

    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

void printReversed(const vector<string>& words) {
    stack<string> reversed;
    for (const string& word: words) {
        string reversedSingleWord;
        for (int i = word.length() - 1; i >= 0; --i) {
            reversedSingleWord += word[i];
        }
        reversed.push(reversedSingleWord);
    }


    while (!reversed.empty()) {
        cout << reversed.top() << " ";
        reversed.pop();
    }
    cout << endl;
}

void reverseStringExercise() {
    const vector<string> words = readIntput();
    printReversed(words);
}

#pragma endregion

#pragma startup

stack<int> arrayToRead() {
    stack<int> result;
    string numbers;
    getline(cin, numbers);
    istringstream iss(numbers);

    int curNum;
    while (iss >> curNum) {
        result.push(curNum);
    }
    return result;
}

void commands(stack<int>& givenArray) {
    string command;
    cin >> command;

    while (command != "end") {

        if (command == "add") {
            int num1, num2;
            cin >> num1 >> num2;
            givenArray.push(num1);
            givenArray.push(num2);
        } else if (command == "remove") {
            int num1;
            cin >> num1;
            if (num1 <= givenArray.size()) {
                for (int i = 0; i < num1; ++i) {
                    givenArray.pop();
                }
            }
        }

        cin >> command;
    }
}

int stackSum() {
    stack<int> input = arrayToRead();
    commands(input);
    int sum = 0;
    while (!input.empty()) {
        sum += input.top();
        input.pop();
    }
    return sum;
}

#pragma endregion

#pragma startup

stack<int> readInput() {
    stack<int> numbers;
    string input;
    getline(cin, input);
    istringstream iss(input);
    char operation = '+';
    int num;
    while (iss >> num) {
        if (operation == '+') {
            numbers.push(num);
        } else {
            numbers.push(-num);
        }
        iss >> operation;
    }
    return numbers;
}

int simpleCalculator() {
    stack<int> numbers = readInput();

    int result = 0;
    while (!numbers.empty()) {
        result += numbers.top();
        numbers.pop();
    }
    return result;
}

#pragma endregion

#pragma startup


void extractSubExpressions(const string& expression) {
    stack<int> brackets;

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(') {
            brackets.push(i);
        } else if (expression[i] == ')') {
            if (!brackets.empty()) {
                int start = brackets.top();
                brackets.pop();
                string subExpression = expression.substr(start, i - start + 1);
                cout << subExpression << endl;
            }
        }
    }
}

void output() {
    string input;
    getline(cin, input);
    extractSubExpressions(input);
}

#pragma startup

queue<int> inputQueue() {
    queue<int> result;
    string input;
    getline(cin, input);
    istringstream iss(input);

    int curNum;
    while (iss >> curNum) {
        result.push(curNum);
    }
    return result;
}

queue<int> fillEven(queue<int>& queue) {
    std::queue<int> result;
    while (!queue.empty()) {
        if (queue.front() % 2 == 0) {
            result.push(queue.front());
        }
        queue.pop();
    }
    return result;
}

void printQueue() {
    queue<int> input = inputQueue();
    input = fillEven(input);
    while (!input.empty()) {
        cout << input.front();
        input.pop();
        if (!input.empty()) {
            cout << ", ";
        }
    }
}

#pragma endregion

#pragma startup

void printPaidNamesAndRemaining() {
    queue<string> customerQueue;
    string input;

    while (true) {
        cin >> input;

        if (input == "End") {
            break;
        } else if (input == "Paid") {
            while (!customerQueue.empty()) {
                cout << customerQueue.front() << endl;
                customerQueue.pop();
            }
        } else {
            customerQueue.push(input);
        }
    }
    cout << customerQueue.size() << " people remaining." << endl;
}

#pragma endregion

#pragma startup

queue<string> inputNames() {
    string input;
    getline(cin, input);
    istringstream istr(input);

    queue<string> allPlayers;
    string curPlayer;
    while (istr >> curPlayer) {
        allPlayers.push(curPlayer);
    }

    return allPlayers;
}

void hotPotato(queue<string>& names) {

    int timesPassed;
    cin >> timesPassed;

    string nameToRemove;
    while (names.size() > 1) {
        for (int i = 1; i < timesPassed; ++i) {
            names.push(names.front());
            names.pop();
        }

        cout << "Removed " << names.front() << endl;
        names.pop();
    }

    cout << "Last is " << names.front() << endl;
}

void printNames() {
    queue<string> names = inputNames();
    hotPotato(names);
}

#pragma endregion

#pragma startup

int basicStackOperations() {

    int sizeOfStack, popNums, searchNum;
    cin >> sizeOfStack >> popNums >> searchNum;

    stack<int> numbers;

    for (int i = 0; i < sizeOfStack; ++i) {
        int curNum;
        cin >> curNum;
        numbers.push(curNum);
    }

    for (int i = 0; i < popNums; ++i) {
        numbers.pop();
    }
    if (numbers.empty()) {
        cout << "0";
        return 0;
    }

    int smallest = INT_MAX;

    while (!numbers.empty()) {

        int top = numbers.top();
        numbers.pop();

        if (searchNum == top) {
            cout << "true";
            return 0;
        }
        if (top < smallest) {
            smallest = top;
        }
    }

    cout << smallest << endl;
    return 0;
}

#pragma endregion

#pragma startup


int basicQueueOperations() {
    int sizeOfStack, popNums, searchNum;
    cin >> sizeOfStack >> popNums >> searchNum;

    queue<int> numbers;

    for (int i = 0; i < sizeOfStack; ++i) {
        int curNum;
        cin >> curNum;
        numbers.push(curNum);
    }

    for (int i = 0; i < popNums; ++i) {
        numbers.pop();
    }
    if (numbers.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int smallest = INT_MAX;
    while (!numbers.empty()) {
        int top = numbers.front();
        numbers.pop();

        if (top == searchNum) {
            cout << "true" << endl;
            return 0;
        }

        if (top < smallest) {
            smallest = top;
        }

    }

    cout << smallest;

    return 0;
}

int minimum(stack<int> elements) {

    int min = INT_MAX;
    for (int i = 0; i <= elements.size(); ++i) {
        int top = elements.top();
        if (top < min) {
            min = top;
        }
        elements.pop();
    }
    return min;
}

int maximum(stack<int> elements) {

    int max = INT_MIN;
    for (int i = 0; i <= elements.size(); ++i) {
        int top = elements.top();
        if (top > max) {
            max = top;
        }
        elements.pop();
    }
    return max;
}

int maxAndMinElement() {

    int inputLines;
    cin >> inputLines;
    stack<int> result;


    int command;
    while (inputLines--) {
        cin >> command;
        int element;

        switch (command) {
            case 1:
                cin >> element;
                result.push(element);
                break;
            case 2:
                if (!result.empty()) {
                    result.pop();
                }
                break;
            case 3:
                if (!result.empty()) {
                    cout << maximum(result) << endl;
                }
                break;
            case 4:
                if (!result.empty()) {
                    cout << minimum(result) << endl;
                }
                break;
        }
    }


    while (!result.empty()) {
        cout << result.top();
        result.pop();
        if (!result.empty()) {
            cout << ", ";
        }

    }
    return 0;
}

#pragma endregion

#pragma startup

int isComplete(queue<int>& orders, int& foodQuantity) {

    while (foodQuantity > orders.front() && !orders.empty()) {
        foodQuantity -= orders.front();
        orders.pop();
    }

    return foodQuantity;

}

int input() {
    int foodQuantity;
    cin >> foodQuantity;
    string ordersAsString;
    cin.ignore();
    getline(cin, ordersAsString);
    istringstream iss(ordersAsString);

    queue<int> orders;

    int curOrder;
    int max = INT_MIN;
    while (iss >> curOrder) {
        orders.push(curOrder);
        if (curOrder > max) {
            max = curOrder;
        }
    }
    cout << max << endl;

    isComplete(orders, foodQuantity);

    if (foodQuantity < orders.front()) {
        cout << "Orders left: ";
        while (!orders.empty()) {
            cout << orders.front() << " ";
            orders.pop();
        }
        return 0;
    }

    cout << "Orders complete";

    return 0;
}

#pragma endregion

#pragma startup

stack<int> readInputClothes() {
    stack<int> clothes;
    string input;
    getline(cin, input);
    istringstream iss(input);
    int curPiece;
    while (iss >> curPiece) {
        clothes.push(curPiece);
    }
    return clothes;
}

int rackUsed(stack<int>& clothes, int& capacityOfRack) {
    int sumOfClothes = 0;
    int racksUsed = 1;
    while (!clothes.empty()) {
        if (sumOfClothes + clothes.top() > capacityOfRack) { ;
            racksUsed++;
            sumOfClothes = 0;
        }
        sumOfClothes += clothes.top();
        clothes.pop();

    }

    return racksUsed;
}

void fashionBotique() {
    stack<int> clothes = readInputClothes();
    int capacityOfRack;
    cin >> capacityOfRack;

    cout << rackUsed(clothes, capacityOfRack);

}

#pragma endregion

#pragma startup

bool canFinishTour(queue<int> amounts, queue<int> distances) {

    int reservoir = 0;
    while (!amounts.empty()) {

        reservoir += amounts.front();
        int distanceToNext = distances.front();

        if (reservoir < distanceToNext) {
            return false;
        }
        reservoir -= distanceToNext;

        distances.pop();
        amounts.pop();
    }

    return true;
}

void truckTour() {
    int stationsCount;
    cin >> stationsCount;
    queue<int> amounts;
    queue<int> distances;

    for (int i = 0; i < stationsCount; ++i) {
        int buf;
        cin >> buf;
        amounts.push(buf);
        cin >> buf;
        distances.push(buf);
    }


    for (int curStation = 0; curStation < stationsCount; ++curStation) {
        if (canFinishTour(amounts, distances)) {
            cout << curStation << endl;
            break;
        }

        int curDistance = distances.front();
        int curAmount = amounts.front();
        distances.pop();
        amounts.pop();

        distances.push(curDistance);
        amounts.push(curAmount);
    }

}

#pragma endregion

#pragma startup


bool validExpression(const string & input){

    stack<char> brackets;

    for (int idx = 0; idx < input.length(); ++idx) {

        char curChar = input[idx];
        int opening = 0;
        switch (curChar) {
            case '(':
            case '[':
            case '{':
                brackets.push(curChar);
                break;

            case ')': opening = '('; break;
            case ']': opening = '['; break;
            case '}': opening = '{'; break;
        }

        if (opening) {
            if (brackets.empty()) {
                return false;
            }
            if (brackets.top() != opening) {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}
void balancedParentheses() {


    string input;
    cin >> input;
    cout <<(validExpression(input) ? "YES" : "NO");

}


int main() {
    balancedParentheses();
    return 0;
}

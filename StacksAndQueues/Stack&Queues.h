//
// Created by Momchil Tsanov on 8.06.24.
//

#ifndef ADVANCED_STACK_QUEUES_H
#define ADVANCED_STACK_QUEUES_H

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

vector<string> readIntput();

void printReversed(const vector<string>& words);

void reverseStringExercise();

stack<int> arrayToRead();

void commands(stack<int>& givenArray);

int stackSum();

stack<int> readInput();

int simpleCalculator();

void extractSubExpressions(const string& expression);

void output();

queue<int> inputQueue();

queue<int> fillEven(queue<int>& queue);

void printQueue();

void printPaidNamesAndRemaining();

queue<string> inputNames();

void hotPotato(queue<string>& names);

void printNames();

int basicStackOperations();

int basicQueueOperations();

int minimum(stack<int> elements);

int maximum(stack<int> elements);

int maxAndMinElement();

int isComplete(queue<int>& orders, int& foodQuantity);

int input();

stack<int> readInputClothes();

int rackUsed(stack<int>& clothes, int& capacityOfRack);

void fashionBotique();

bool canFinishTour(queue<int> amounts, queue<int> distances);

void truckTour();

bool validExpression(const string& input);

void balancedParentheses();


#endif //ADVANCED_STACK_QUEUES_H


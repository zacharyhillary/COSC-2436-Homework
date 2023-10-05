// lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include <fstream>

class Stack {
public: 
    char top;
    int stackArray[1000];
    Stack() {
        top = -1;
    }
    void push(int addValue) {
        if (top >= 999) {
            cout << "There is not enough room for adding new input! \n";
            return;
        }
        stackArray[++top] = addValue;
    }
    char peek() {
        if (top < 0) {
            cout << "There is no element in this stack!\n";
            return 0;
        }
        char topValue = stackArray[top];
        return topValue;
    }
    char pop() {
        if (top < 0) {
            cout << "There is no element in this stack!\n";
            return 0;
        }
        char topValue = stackArray[top--];
        return topValue;
    }
    bool isEmpty() {
        return (top < 0);
    }

    bool isBalanced(string testString) {
        for (int i = 0; i < testString.length(); i++) {
            char currentChar = testString.at(i);
            
            if ((currentChar == '(') || (currentChar == '{') || (currentChar == '['))push(currentChar);
            char currentTop = peek();
            if ((currentChar == ')' && (currentTop == '(')) || (currentChar == '}' && (currentTop == '{')) || (currentChar == ']' && (currentTop == '[')))pop();
            else if ((currentChar == ')')  || (currentChar == '}')  || (currentChar == ']' ))return false;
        }
        if (isEmpty())return true;
        else return false;
    }
};




int main(int argc, char* argv[])
{
    if (argc != 2)cout << "error invalid number of command line arguments!\n";
    else {
        ofstream outputfile;
        outputfile.open("output.txt");
        string test = argv[1];
        Stack myStack;
        if (myStack.isBalanced(test)) {
            cout << "True\n";
            outputfile << "True";
        }
        else {
            outputfile << "False";
            cout << "False\n";
            outputfile.close();
        }


    }

}
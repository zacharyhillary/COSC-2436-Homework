#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;
class StackChar {
public:
    int top;
    char stackArray[1000];
    StackChar() {
        top = -1;
    }
    void push(char addValue) {
        if (top >= 999) {
            cout << "There is not enough room for adding new input! \n";
            return;
        }
        //cout << "pushing: " << addValue<<endl;
        stackArray[++top] = addValue;
    }
    char peek() {
        if (top < 0) {
           // cout << "There is no element in this stack!\n";
            return 0;
        }
        char topValue = stackArray[top];
        return topValue;
    }
    char pop() {
        if (top < 0) {
            //cout << "There is no element in this stack!\n";
            return 0;
        }
        char topValue = stackArray[top--];
        return topValue;
    }
    bool isEmpty() {
        return (top < 0);
    }
   
};

class StackDouble {
public:
    int top;
    double stackArray[1000];
    StackDouble() {
        top = -1;
    }
    void push(double addValue) {
        if (top >= 999) {
            cout << "There is not enough room for adding new input! \n";
            return;
        }
        //cout << "pushing: " << addValue<<endl;
        stackArray[++top] = addValue;
    }
    double peek() {
        if (top < 0) {
            // cout << "There is no element in this stack!\n";
            return 0;
        }
        double topValue = stackArray[top];
        return topValue;
    }
    double pop() {
        if (top < 0) {
            //cout << "There is no element in this stack!\n";
            return 0;
        }
        double topValue = stackArray[top--];
        return topValue;
    }
    bool isEmpty() {
        return (top < 0);
    }

};

int getPrecedence(char ooperator) {
    switch (ooperator) {
    case '^':return 3;
    case '*':return 2;
    case '/':return 2;
    case '+':return 1;
    case '-':return 1;
    default:return -1;
    }
}
void InfixToPostFix(string expression, ofstream& outputFile) {
    StackChar stack;
    for (int i = 0;i < expression.size();i++) {
        if (expression[i] > 47 && expression[i] < 58)outputFile << expression[i]; //if operand
        else if (expression[i] == '^' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-') {//if operator
            if (stack.isEmpty() || getPrecedence(expression[i]) > getPrecedence(stack.peek()))stack.push(expression[i]);
            else {
                while (getPrecedence(expression[i]) <= getPrecedence(stack.peek()))outputFile << stack.pop();
                stack.push(expression[i]);
            }
        }
        else if (expression[i] == '(')stack.push(expression[i]);
        else if (expression[i] == ')') {
            while (stack.peek() != '(') outputFile << stack.pop();
            stack.pop();
        }
           
        
        else {
            cout << "NOT A VALID INPUT. ILLEGAL CHARACTER";
            break;
        }
        
    }
    for (int i = 0; i <= stack.top+1;i++)outputFile << stack.pop();
}
void EvaluatePostfix(string expression, ofstream& outputFile) {
    StackDouble stack;
    for (int i = 0; i < expression.size();i++) {
        if (expression[i] > 47 && expression[i] < 58)stack.push(expression[i]-'0'); //if operand push to stack
        else if ((expression[i] == '^' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' )&& stack.top>=1) {
            double operandA = stack.pop();
            double operandB = stack.pop();
           
            switch (expression[i]) {
                case '^':
                     stack.push(pow(operandB, operandA));
                        break;
                case '*': 
                    stack.push(operandB * operandA);
                    break;
                case '/': 
                    stack.push(operandB / operandA);
                    break;
               
                case '+': 
                    stack.push(operandB + operandA);
                    break;
                case '-': 
                    stack.push(operandB - operandA);
                    break;
                default: 
                    break;
             
            }
        }
        else {
           outputFile << "nv";
           return;
        }
    }
    outputFile << fixed << setprecision(1) << stack.peek();
    
}

int main(int argc, char* argv[])
{
    if (argc == 4) {
        string outputFileString = argv[3];
        string expression = argv[2];
        ofstream outputFile;
        outputFile.open(outputFileString);
        switch (argv[1][0]) {
            case '2':
                InfixToPostFix(expression,outputFile);
                break;
            case '3':
                EvaluatePostfix(expression, outputFile);
                break;
        }

        
        outputFile.close();
    }
    else cout << "WRONG NUMBER OF CMD LINE ARGUMENTS";
}
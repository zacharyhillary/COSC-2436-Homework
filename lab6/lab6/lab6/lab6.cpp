#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Node {
public:
    int content;
    Node* previous = nullptr;
    Node* next = nullptr;

};

class LL {
public:
    Node* head = nullptr;
public:

    void addNodeTail(int data) {

        Node* newNode = new Node();//create a new node
        newNode->content = data;//set nodes value
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }//find last node in linked list

        currentNode->next = newNode;
        newNode->previous = currentNode;

    }
    void readFromFile(string filename) {
        ifstream inputfile;
        inputfile.open(filename);
        if (inputfile.is_open())cout << "INPUT FILE IS OPEN" << endl;
        else cout << "INPUT FILE IS NOT OPEN" << endl;
        int number;
        while (inputfile >> number)this->addNodeTail(number);
    }

    void outputLL() {
        ofstream outputfile;
        outputfile.open("output.txt");

        Node* currentNode = head;


        while (currentNode->next != nullptr) {
            cout << currentNode->content << " ";
            currentNode = currentNode->next;
        }
        cout << currentNode->content;
    }
    
};



void recursiveRemoveElements(int number, Node* myNode) {
    if (myNode == nullptr)return; // TEST CASE TO END RECURSION
    if (myNode->content == number) { // IF CONTENT OF NODE IS THE NUMBER THAN REMOVE THE NODE FROM LL
        myNode->previous->next = myNode->next;
        if(myNode->next != nullptr)myNode->next->previous = myNode->previous;
    }
    recursiveRemoveElements(number, myNode->next);

}

void removeElements(int number, LL* myLL) {
    if (myLL->head->content == number) {// IF HEAD IS EQUAL TO THE NUMBER THAN WE NEED TO MAKE THE NEXT ELEMENT THE HEAD
        myLL->head = myLL->head->next;
        myLL->head->previous = nullptr;
    }

    recursiveRemoveElements(number, myLL->head->next);// CALL THE RECURSIVE FUNCTION
}

void main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "ERROR INCORRECT COMMANDD LINE ARGUMENTS" << endl;
            return;
    }
    string inputfilestring = argv[1];
    string numberstring = argv[2];

    stringstream ss(numberstring);
    int number;    // convert string to number
    ss >> number;
    
    
    LL A;
    A.readFromFile(inputfilestring);
    removeElements(5, &A);
    A.outputLL();
}
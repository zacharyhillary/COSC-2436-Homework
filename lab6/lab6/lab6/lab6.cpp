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
        inputfile.close();
    }

    void outputLL() {
        ofstream outputfile;
        outputfile.open("output.txt");

        Node* currentNode = head;
        if (currentNode == nullptr)return;

        while (currentNode->next != nullptr) {
            outputfile << currentNode->content << " ";
            currentNode = currentNode->next;
        }
        outputfile << currentNode->content;
        outputfile.close();
    }
    
};





void removeElements(int number, Node* &myNode) {
    
   
    if (myNode == nullptr)return; // BASE CASE. END OF LL
    if (myNode->content == number) {
        if (myNode->previous == nullptr)//if head && equal to value 
        {
            if (myNode->next == nullptr) {// if head and tail
                myNode = nullptr;
                return;
            }

            else {
                myNode = myNode->next;
                myNode->previous = nullptr;
                removeElements(number, myNode);// CALL THE RECURSIVE FUNCTION
            }
        }
        else {// not the head
            if (myNode->next != nullptr) {// not tail}
               
                myNode->next->previous = myNode->previous;
                myNode->previous->next = myNode->next;
                removeElements(number, myNode);// CALL THE RECURSIVE FUNCTION
            }
            else {// if tail
                myNode->previous->next = nullptr;
                
            }

        }
    }
        else removeElements(number, myNode->next);// CALL THE RECURSIVE FUNCTION
    
     
    
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "ERROR INCORRECT COMMANDD LINE ARGUMENTS" << endl;
            return 1;
    }
    string inputfilestring = argv[1];
    string numberstring = argv[2];

    stringstream ss(numberstring);
    int number;    // convert string to number
    ss >> number;
    
    
    LL A;
    A.readFromFile(inputfilestring);
    removeElements(number, A.head);
    
    A.outputLL();
    cout << "finished";
}
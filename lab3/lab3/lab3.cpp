// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
class Node {
public:
    int content;
    Node* next=nullptr;

};

class LL {
    Node* head=nullptr;
public:
    void addNodeHead(int data) {
        
        Node* newNode = new Node();//create a new node
        newNode->content = data;//set nodes value 
        if (head == nullptr)newNode->next = nullptr;
        else newNode->next = head;//set the next node to the current head
        head = newNode;//set the head to the new node
    }
    void removeNodeHead() {
        if (head == nullptr)return;
         head = head->next;
    }
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
        

    }

    void printLL() {
        Node* currentNode = head;
        
            
        while (currentNode->next != nullptr) {
            cout << currentNode->content << endl;
            currentNode = currentNode->next;
         }
        cout << currentNode->content << endl;
    }

    void reverseLL() {
        Node* current = head;
        Node* next = nullptr;
        Node* previous=nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            



        }
        head = previous;
    }
};

void ReadFromFile(LL &LinkedList , string inputFileString) {
    fstream inputfile;
    inputfile.open(inputFileString);
    int currentNumber;
    while (inputfile >> currentNumber)LinkedList.addNodeTail(currentNumber);
}

int main(int argc, char* argv[]) {
    LL LinkedList;
    string FileString = argv[1];
    ReadFromFile(LinkedList,FileString);
    LinkedList.printLL();
    LinkedList.reverseLL();
    cout << endl << endl << endl;
    LinkedList.printLL();
}

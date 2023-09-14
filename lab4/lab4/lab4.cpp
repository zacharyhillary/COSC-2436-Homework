#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Node {
public:
    int content;
    Node* right = nullptr;
    Node* down = nullptr;

};

class LL {
public:
    Node* head = nullptr;

    void PrintMatrix() {
        Node* nextRowHead=head->down;
        Node* currentNode = head;

        while (nextRowHead != nullptr) {
            nextRowHead = currentNode->down;
            while (currentNode != nullptr) {
                cout << currentNode->content << " ";
                currentNode = currentNode->right;
            }
            currentNode = nextRowHead;
            cout << endl;
        }
    }
    void ReadFromFile(string inputFileString) {
        string currentLineString;
        fstream inputfile;
        inputfile.open(inputFileString);
        Node* previousRowHead = nullptr;
        while (getline(inputfile, currentLineString)) {
            stringstream oss(currentLineString);
            int currentInt;
            Node* currentNode=nullptr;
            Node* previousNode = nullptr;
            Node* rowHead=nullptr;
            
            int i = 0;
            while (oss >> currentInt) {
                currentNode = new Node;
                if (head == nullptr)head = currentNode;
                if (rowHead == nullptr)rowHead = currentNode;
                currentNode->content = currentInt;
                if(previousNode!=nullptr)previousNode->right = currentNode;
                i++;
                previousNode = currentNode;
            }
            Node* temp1 = previousRowHead;
            Node* temp2 = rowHead;
            if (temp1 != nullptr)for (int k = 0;k < i; k++) {
                temp1->down = temp2;
                temp1 = temp1->right;
                temp2 = temp2->right;

            }
            previousRowHead = rowHead;
        }
    }
};

int main(int argc, char* argv[]) {
    if (2 == 2) {
        LL MatrixA;
        string filename=argv[1];
        MatrixA.ReadFromFile(filename);
        MatrixA.PrintMatrix();
        
    }
    else cout << "ERROR!! incorrect number of command line arguments!!!!";
}
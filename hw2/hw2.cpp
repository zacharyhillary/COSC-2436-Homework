// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
class Node {
public:
    double content;
    Node* next = nullptr;

};


class LineLL {
    
  
public:
    Node* lineHead = nullptr;
    LineLL* next = nullptr;
    
    void addNodeTail(int data) {

        Node* newNode = new Node();//create a new node
        newNode->content = data;//set nodes value
        newNode->next = nullptr;

        if (lineHead == nullptr) {
            lineHead = newNode;
            return;
        }

        Node* currentNode = lineHead;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }//find last node in linked list

        currentNode->next = newNode;


    }

    
    
};
class matrixLL {
   
public:
    LineLL* matrixHead = nullptr;
    void addNodeTail(Node* data) {

        LineLL* newLine = new LineLL();//create a new line
        newLine->lineHead = data;
        newLine->next = nullptr;

        if (matrixHead == nullptr) {
            matrixHead = newLine;
            return;
        }

        LineLL* currentLine = matrixHead;
        while (currentLine->next != nullptr) {
            currentLine = currentLine->next;
        }//find last node in linked list

        currentLine->next = newLine;


    }
    void readFromFile(string inputFileString) {
        string currentLineString;
        fstream inputfile;
        inputfile.open(inputFileString);
        while (getline(inputfile, currentLineString)) {
            stringstream oss(currentLineString);
            int currentInt;
            LineLL matrixCurrentLine;

                while (oss >> currentInt) {
                    matrixCurrentLine.addNodeTail(currentInt);
                }
                this->addNodeTail(matrixCurrentLine.lineHead);
        }
    }
    
    void print(ostream &stream) {

        LineLL* currentLine = matrixHead;
        while (currentLine != nullptr) {
            Node* currentNode = currentLine->lineHead;


            while (currentNode != nullptr) {
                stream <<fixed<<setprecision(1)<< currentNode->content << " ";
                currentNode = currentNode->next;
            }
            stream << endl;
            currentLine = currentLine->next;
        }
        stream << endl;
    }
    int numrows() {
        LineLL* currentLine = matrixHead;
        int numberOfRows=0;
        while (currentLine != nullptr) {
            numberOfRows++;
            currentLine = currentLine->next;
        }
        return numberOfRows;
    }
    int numcolumns(){
        LineLL* currentLine = matrixHead;
        int numberOfColumns=-69;
        while (currentLine != nullptr) {
            int numbcolumns = 0;
            Node* currentNode = currentLine->lineHead;


            while (currentNode != nullptr) {
                numbcolumns++;
                currentNode = currentNode->next;
            }
            currentLine = currentLine->next;
            if ((numberOfColumns != numbcolumns) && (numberOfColumns != -69))cout << "ERROR!!!!!! ERROR!!! NOT A MATRIX, INCORRECT NUMBER OF COLUMNS ON A ROW!!!!";
            numberOfColumns = numbcolumns;
        }
        return numberOfColumns;
    }
    int accesscell(int row, int column) {
        LineLL* currentLine = matrixHead;
        for (int i = 0; i < row; i++) currentLine = currentLine->next;
        Node* currentNode = currentLine->lineHead;
        for (int i = 0; i < column; i++)currentNode = currentNode->next;
        return currentNode->content;
        
    }
    void writecell(int row, int column, int data) {
        LineLL* currentLine = matrixHead;
        for (int i = 0; i < row; i++) currentLine = currentLine->next;
        Node* currentNode = currentLine->lineHead;
        for (int i = 0; i < column; i++)currentNode = currentNode->next;
        currentNode->content=data;
    }
    void addsub(matrixLL A, matrixLL B, string operation) {
        if ((A.numcolumns() == B.numcolumns()) && (A.numrows() == B.numrows())) {
           
            const int numberrows = A.numrows();
            const int numbercolumns = A.numcolumns();

            for (int i = 0; i < numberrows;i++) {
                LineLL currentLine;
                for (int j = 0; j < numbercolumns;j++) {
                    if(operation=="add")currentLine.addNodeTail(A.accesscell(i, j) + B.accesscell(i, j));
                    if (operation == "sub")currentLine.addNodeTail(A.accesscell(i, j) - B.accesscell(i, j));
                }
                this->addNodeTail(currentLine.lineHead);
            }
        }
        else cout << "unable to add/sub because matrix are not of same dimension!!!"<<endl;
    }
    void mult(matrixLL A, matrixLL B) {
        
        if (A.numcolumns() == B.numrows()) {
            int ANumColumns=A.numcolumns();
            int BNumColumns=B.numcolumns();
            int ANumRows = A.numrows();
            for (int i = 0; i < ANumRows; i++) {
                LineLL currentLine;
                for (int j = 0; j < BNumColumns; j++) {
                    int multsum = 0;
                    for (int k = 0; k < ANumColumns; k++)
                    {
                        multsum += (A.accesscell(i, k) * B.accesscell(k, j));
                    }
                    currentLine.addNodeTail(multsum);
                }
                this->addNodeTail(currentLine.lineHead);
            }
        }
        else cout << "ERROR!!!! MULTIPLICATION AxB NOT POSSIBLE BECAUSE OF DIMENSIONS!";

    }
    void tra(matrixLL A) {
        int ANumColumns = A.numcolumns();
        int ANumRows = A.numrows();

        for (int i = 0; i < ANumColumns;i++) {
            LineLL currentLine;
            for (int j = 0; j < ANumRows;j++)currentLine.addNodeTail(A.accesscell(j, i));
            this->addNodeTail(currentLine.lineHead);
        }
        
    }
    
};


matrixLL submatrix(matrixLL A, int col) {
    
    int n = A.numcolumns();
    matrixLL newMatrix;
   
    for (int i = 1; i < n; i++) {
        LineLL currentLine;
        for (int j = 0; j < n ; j++) {
            if (j == col);
            else currentLine.addNodeTail(A.accesscell(i, j));
               
            
        }
        newMatrix.addNodeTail(currentLine.lineHead);
    }
    return newMatrix;
}
double det(matrixLL A) {
    double determinant = 0;
    int n = A.numcolumns();
    if (n == 2)return (double)A.accesscell(0, 0)* (double)A.accesscell(1, 1) - (double)A.accesscell(0, 1)* (double)A.accesscell(1, 0);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) determinant += (double)(A.accesscell(0, i)) * (double)(det(submatrix(A, i)));
        else determinant -= (double)(A.accesscell(0, i)) * (double)(det(submatrix(A, i)));
    }
    return determinant;
}

int main(int argc, char* argv[]) {
    
   
    
    ofstream outputfile; 
    for (int i = 0; i < argc;i++)cout << argv[i] << endl;
    if ((argc != 4) && (argc != 5))cout << "ERROR INCORRECT COMMAND LINE ARGUMENTS!!!";
    else {
        string operation = argv[1];
        if (operation == "add" || operation == "sub") {

            if (argc == 5) {

                matrixLL A;
                matrixLL B;
                matrixLL outputMatrix;
                A.readFromFile(argv[2]);
                B.readFromFile(argv[3]);
                outputMatrix.addsub(A, B, operation);
                string filename = argv[4];
                //for (int i = 0; i < 4; i++)filename.pop_back();
               // string operation = argv[1];
                //filename += (operation + ".txt");
                outputfile.open(filename);
                outputMatrix.print(outputfile);
                outputMatrix.print(cout);
                outputfile.close();
            }
            else cout << "ERROR INCORRECT COMMAND LINE ARGUMENTS!!!";


        }

        else if (operation == "mul") {
            if (argc == 5) {

                matrixLL A;
                matrixLL B;
                matrixLL outputMatrix;
                A.readFromFile(argv[2]);
                B.readFromFile(argv[3]);
                outputMatrix.mult(A, B);
                string filename = argv[4];
                //for (int i = 0; i < 4; i++)filename.pop_back();
                //string operation = argv[1];
               // filename += (operation + ".txt");
                outputfile.open(filename);
                outputMatrix.print(outputfile);
                outputfile.close();
            }
            else cout << "ERROR INCORRECT COMMAND LINE ARGUMENTS!!!";
        }


        else if (operation == "tra") {
            if (argc == 4) {
                matrixLL A;
                A.readFromFile(argv[2]);
                matrixLL outputMatrix;
                outputMatrix.tra(A);
                string filename = argv[3];
               // for (int i = 0; i < 4; i++)filename.pop_back();
               // string operation = argv[1];
               // filename += (operation + ".txt");
                outputfile.open(filename);
                outputMatrix.print(outputfile);
                outputfile.close();
            }
            else cout << "ERROR INCORRECT COMMAND LINE ARGUMENTS!!!";

        }




        else if (operation == "det") {
            if (argc == 4) {
            matrixLL A;
            A.readFromFile(argv[2]);
          
            string filename = argv[3];
           // for (int i = 0; i < 4; i++)filename.pop_back();
          //  string operation = argv[1];
          //  filename += (operation + ".txt");
            outputfile.open(filename);
            outputfile << fixed << setprecision(1) << det(A);
            outputfile.close();
        }
        }
        else cout << "ERROR INCORRECT COMMAND LINE ARGUMENTS!!!";
    }
}



// hw4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void Hanoi3(int disk, ofstream& outputfile, char fromPin, char auxiliaryPin, char toPin){
    if (disk != 0) {

        Hanoi3(disk - 1, outputfile, fromPin, toPin, auxiliaryPin);
        outputfile << disk << " " << fromPin << " " << toPin << endl;
        Hanoi3(disk - 1,  outputfile, auxiliaryPin, fromPin, toPin);
    }
}
void Hanoi4(int disk, ofstream& outputfile, char fromPin, char auxiliaryPin1, char auxiliaryPin2, char toPin) {
    if(disk!= 0) {
        if(disk == 1) outputfile << disk << " " << fromPin << " " << toPin << endl;
        else {
            Hanoi4(disk - 2,  outputfile, fromPin, auxiliaryPin2, toPin, auxiliaryPin1);

            outputfile <<disk- 1 << " " << fromPin << " " << auxiliaryPin2<<endl;
            outputfile <<disk<< " " << fromPin << " " << toPin<<endl;
            outputfile <<disk- 1 << " " << auxiliaryPin2 << " " << toPin<<endl;

            Hanoi4(disk - 2,  outputfile, auxiliaryPin1, fromPin, auxiliaryPin2, toPin);
        }
       
    }
}

void Hanoi5(int disk, ofstream& outputfile, char fromPin, char auxiliaryPin1, char auxiliaryPin2, char auxiliaryPin3, char toPin) {
    if (disk != 0) {
        if (disk == 1)outputfile << disk << " " << fromPin << " " << toPin << endl;
        else if (disk == 2) {
            outputfile << disk-1 << " " << fromPin << " " << auxiliaryPin1 << endl;
            outputfile << disk << " " << fromPin << " " << toPin << endl;
            outputfile << disk-1 << " " << auxiliaryPin1 << " " << toPin << endl;
        }
        else {
            Hanoi5(disk - 3,  outputfile, fromPin, auxiliaryPin2, auxiliaryPin3, toPin, auxiliaryPin1);

            outputfile << disk - 2 << " " << fromPin << " " << auxiliaryPin3 << endl;
            outputfile << disk - 1 << " " << fromPin << " " << auxiliaryPin2 << endl;
            outputfile << disk << " " << fromPin << " " << toPin << endl;
            outputfile << disk - 1 << " " << auxiliaryPin2 << " " << toPin << endl;
            outputfile << disk - 2 << " " << auxiliaryPin3 << " " << toPin << endl;

            Hanoi5(disk - 3, outputfile, auxiliaryPin1, fromPin, auxiliaryPin2, auxiliaryPin3, toPin);
        }

    }
}


int main(int argc, char** argv)
{
    if (argc != 4)cout << "ERROR: INCORRECT NUMBER OF CCOMMAND LINE ARGUEMENTS\n";
    else {
        ofstream outputfile;
        int numPins = strtol(argv[1], NULL, 10);
        int numDisks = strtol(argv[2], NULL, 10);
        string filename = argv[3];
        outputfile.open(filename);
        switch (numPins) {
        case 3:
            Hanoi3(numDisks,  outputfile, 'A', 'B', 'C');
            break;
        case 4:
            Hanoi4(numDisks,  outputfile, 'A', 'B', 'C', 'D');
            break;
        case 5:
            Hanoi5(numDisks,  outputfile, 'A', 'B', 'C','D','E');
            break;
        }
        outputfile.close();
    }
}
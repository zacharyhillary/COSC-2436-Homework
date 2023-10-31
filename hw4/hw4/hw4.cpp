// hw4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Hanoi3(int disk, char fromPin, char auxiliaryPin, char toPin){
    if (disk != 0) {

        Hanoi3(disk - 1, fromPin, toPin, auxiliaryPin);
        cout << disk << " " << fromPin << " " << toPin << endl;
        Hanoi3(disk - 1, auxiliaryPin, fromPin, toPin);
    }
}
void Hanoi4(int disk, char fromPin, char auxiliaryPin1, char auxiliaryPin2, char toPin) {
    if(disk!= 0) {
        if(disk == 1) cout << disk << " " << fromPin << " " << toPin << endl;
        else {
            Hanoi4(disk - 2, fromPin, auxiliaryPin2, toPin, auxiliaryPin1);

            cout <<disk- 1 << " " << fromPin << " " << auxiliaryPin2<<endl;
            cout <<disk<< " " << fromPin << " " << toPin<<endl;
            cout <<disk- 1 << " " << auxiliaryPin2 << " " << toPin<<endl;

            Hanoi4(disk - 2, auxiliaryPin1, fromPin, auxiliaryPin2, toPin);
        }
       
    }
}

void Hanoi5(int disk, char fromPin, char auxiliaryPin1, char auxiliaryPin2, char auxiliaryPin3, char toPin) {
    if (disk != 0) {
        if (disk == 1)cout << disk << " " << fromPin << " " << toPin << endl;
        else if (disk == 2) {
            cout << disk-1 << " " << fromPin << " " << auxiliaryPin1 << endl;
            cout << disk << " " << fromPin << " " << toPin << endl;
            cout << disk-1 << " " << auxiliaryPin1 << " " << toPin << endl;
        }
        else {
            Hanoi5(disk - 3, fromPin, auxiliaryPin2, auxiliaryPin3, toPin, auxiliaryPin1);

            cout << disk - 2 << " " << fromPin << " " << auxiliaryPin3 << endl;
            cout << disk - 1 << " " << fromPin << " " << auxiliaryPin2 << endl;
            cout << disk << " " << fromPin << " " << toPin << endl;
            cout << disk - 1 << " " << auxiliaryPin2 << " " << toPin << endl;
            cout << disk - 2 << " " << auxiliaryPin3 << " " << toPin << endl;

            Hanoi5(disk - 3, auxiliaryPin1, fromPin, auxiliaryPin2, auxiliaryPin3, toPin);
        }

    }
}

int main()
{
    int numPins;
    int numDisks;
   // Hanoi3(3, 'A', 'B', 'C');
    Hanoi5(5,'A', 'B', 'C', 'D','E');
}
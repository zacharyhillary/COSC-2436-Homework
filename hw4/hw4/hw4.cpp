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
void Hanoi4(int n, char fromPin, char auxiliaryPin1, char auxiliaryPin2, char toPin) {
    if (n != 0) {
        if (n != 1)
        {
            Hanoi4(n - 2, fromPin, auxiliaryPin2, toPin, auxiliaryPin1);

            cout << n - 1 << " " << fromPin << " " << auxiliaryPin2<<endl;
            cout << n << " " << fromPin << " " << toPin<<endl;
            cout << n - 1 << " " << auxiliaryPin2 << " " << toPin<<endl;

            Hanoi4(n - 2, auxiliaryPin1, fromPin, auxiliaryPin2, toPin);
        }
        else cout << n << " " << fromPin << " " << toPin<<endl;
    }
}


int main()
{
    int numPins;
    int numDisks;
   // Hanoi3(3, 'A', 'B', 'C');
    Hanoi4(3,'A', 'B', 'C', 'D');
}
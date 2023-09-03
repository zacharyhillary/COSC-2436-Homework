// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



void ReadAndProcessFile(vector<string>& OutputText) {
    fstream inputfile;
    inputfile.open("numtext.txt");

    int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
    string text[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    string currentline;
    string newLine;
    string currentWord;
    
    while (getline(inputfile, currentline)) {
        stringstream currentLineStream(currentline);
        newLine = "";
        int count = 0;
        while (currentLineStream >> currentWord) {
           
            if ((currentWord[0] >= '0') && (currentWord[0] <= '9')) currentWord = text[currentWord[0]-48];
            if(count!=0)newLine += " ";
            newLine+= currentWord;
            count++;
        }
        OutputText.push_back(newLine);
        
    }
    inputfile.close();

}

void WriteFile(vector<string>& OutputText) {
    ofstream outputfile;
    outputfile.open("numtext.txt");
    for (int i = 0; i < OutputText.size(); i++) {
        outputfile << OutputText[i];
        outputfile << endl;
    }
}


int main()
{
    vector <string> OutputText;
    ReadAndProcessFile(OutputText);
    WriteFile(OutputText);
}
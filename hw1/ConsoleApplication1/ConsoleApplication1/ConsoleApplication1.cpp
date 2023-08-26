#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string StringToLower(string inputstring) {
    for (int i = 0;i < inputstring.size();i++) {
        if (inputstring[i] >= 'A' && inputstring[i] <= 'Z')
            inputstring[i] = inputstring[i] - 'A' + 'a';

    }
    return inputstring;
}

void ReadFromFile(vector <string> &wordVector) {
    fstream inputfile;
    inputfile.open("tiny1.txt");
    string currentString;
    while (inputfile >> currentString) { //while not end of file read one word into currentString
        currentString = StringToLower(currentString);//make all lower case
        if (currentString.back() == ',')currentString.pop_back();//delete commas
        wordVector.push_back(currentString);
    }

    inputfile.close();
}



int main() {
    fstream inputfile;
    inputfile.open("tiny1.txt");
    cout << inputfile.is_open();
    vector<string> wordVector;
    ReadFromFile(wordVector);
    for(int i=0;i<wordVector.size();i++)if ((wordVector[i].back() == '.')||(wordVector[i].back() == '!')||(wordVector[i].back() == '?'))wordVector[i].pop_back();//delete commas
    cout << "finished!";





   
        

   
    



}
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
void ReadFromFile2(vector <vector<string>> & sentenceVector, vector<string > & wordVector) {//vector <vector<string>> sentenceVector2D) {
    fstream inputfile;
    vector<string> sentenceVector1D;
    inputfile.open("tiny1.txt");
    
    string currentLine;

    while (getline(inputfile, currentLine)) {
        ofstream tempoutfile;
        ifstream tempinfile;
        tempoutfile.open("temp.txt");
        currentLine = StringToLower(currentLine);
        tempoutfile << currentLine;
        tempoutfile.close();
        tempinfile.open("temp.txt");
        vector<string> currentSentence;
        string currentWord = "";
        while (tempinfile >> currentWord) {
            if (currentWord.back() == ',')currentWord.pop_back();//delete commas
            if (currentWord.back() == '.' || currentWord.back() == '!' || currentWord.back() == '?') {
                currentWord.pop_back();
                currentSentence.push_back(currentWord);
                sentenceVector.push_back(currentSentence);
                currentSentence.clear();
            }
            else  currentSentence.push_back(currentWord);

        }
        tempinfile.close();
        if (currentSentence.size()!=0)sentenceVector.push_back(currentSentence);
        }
    inputfile.close();

    for (int i = 0; i < sentenceVector.size(); i++)for (int j = 0; j < sentenceVector[i].size(); j++)wordVector.push_back(sentenceVector[i][j]);
        
}





void RankWordFrequency(vector <string> wordVector, vector<int> &wordFrequencyVector) {
    int count = 0;
    for (int count = 0; count < wordVector.size(); count++) {
        for (int i = count; i < wordVector.size(); i++)if (wordVector[count] == wordVector[i])wordFrequencyVector[count]++;
        for (int i = 0; i < count; i++)if (wordVector[i] == wordVector[count])wordFrequencyVector[count] = -1;
    }
}

void Question1(vector<int> wordFrequencyVector, vector<string>wordVector,string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_1.txt";
    outputfile.open(outputFilePrefix);
    vector<int> temp=wordFrequencyVector;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < wordFrequencyVector.size(); i++) if (wordFrequencyVector[i] == temp[temp.size()-1])outputfile << wordVector[i] << ":" << wordFrequencyVector[i] << endl;
    outputfile.close();
    }
        
void Question2(vector<int> wordFrequencyVector, vector<string>wordVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_2.txt";
    outputfile.open(outputFilePrefix);
    vector<int> temp = wordFrequencyVector;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < wordFrequencyVector.size(); i++) if (wordFrequencyVector[i] == temp[temp.size() - 3])outputfile << wordVector[i] << ":" << wordFrequencyVector[i] << endl;
    outputfile.close();
}
void Question3(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_3.txt";
    outputfile.open(outputFilePrefix);
    vector<vector<int>> rankingVector;
    for (int sentenceNumber = 0; sentenceNumber < sentenceVector.size();sentenceNumber++) {//for every sentence
        vector<int> wordRankingVector(sentenceVector[sentenceNumber].size());
        RankWordFrequency(sentenceVector[sentenceNumber], wordRankingVector);
        rankingVector.push_back(wordRankingVector);
}
    int highestFrequency = 0;
    for (int i = 0; i < sentenceVector.size(); i++)for (int j = 0; j < sentenceVector[i].size(); j++)if (rankingVector[i][j] > highestFrequency)highestFrequency = rankingVector[i][j];
    cout << highestFrequency<<endl;
    for (int i = 0; i < sentenceVector.size(); i++)for (int j = 0; j < sentenceVector[i].size(); j++)if (rankingVector[i][j] == highestFrequency) {
        outputfile << sentenceVector[i][j] << ":"<<highestFrequency<<":";
        for (int k = 0; k < sentenceVector[i].size(); k++)outputfile << sentenceVector[i][k]<<" ";
        outputfile << endl;
    }
    outputfile.close();
}
void Question4(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_4.txt";
    outputfile.open(outputFilePrefix);
    vector<int> wordRanking;
    for (int i = 0; i < sentenceVector.size(); i++) {
        int wordcount = 0;
        for (int j = 0; j < sentenceVector[i].size(); j++) if (sentenceVector[i][j] == "the")wordcount++;
        wordRanking.push_back(wordcount);
    }
    int highestFrequency = 0;
    for (int i = 0; i < wordRanking.size(); i++)if (wordRanking[i] > highestFrequency)highestFrequency = wordRanking[i];
    
    for (int i = 0; i < sentenceVector.size(); i++)if (wordRanking[i] == highestFrequency) {
        outputfile << "the" << ":" << highestFrequency << ":";
        for (int k = 0; k < sentenceVector[i].size(); k++)outputfile << sentenceVector[i][k] << " ";
        outputfile << endl;
    }
    outputfile.close();
}


void Question5(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_5.txt";
    outputfile.open(outputFilePrefix);
    vector<int> wordRanking;
    for (int i = 0; i < sentenceVector.size(); i++) {
        int wordcount = 0;
        for (int j = 0; j < sentenceVector[i].size(); j++) if (sentenceVector[i][j] == "of")wordcount++;
        wordRanking.push_back(wordcount);
    }
    int highestFrequency = 0;
    for (int i = 0; i < wordRanking.size(); i++)if (wordRanking[i] > highestFrequency)highestFrequency = wordRanking[i];
    
    for (int i = 0; i < sentenceVector.size(); i++)if (wordRanking[i] == highestFrequency)
    {
        outputfile << "of" << ":" << highestFrequency << ":";
        for (int k = 0; k < sentenceVector[i].size(); k++)outputfile << sentenceVector[i][k] << " ";
        outputfile << endl;
    }
    outputfile.close();

}
void Question6(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_6.txt";
    outputfile.open(outputFilePrefix);
    vector<int> wordRanking;
    for (int i = 0; i < sentenceVector.size(); i++) {
        int wordcount = 0;
        for (int j = 0; j < sentenceVector[i].size(); j++) if (sentenceVector[i][j] == "was")wordcount++;
        wordRanking.push_back(wordcount);
    }
    int highestFrequency = 0;
    for (int i = 0; i < wordRanking.size(); i++)if (wordRanking[i] > highestFrequency)highestFrequency = wordRanking[i];
    
    for (int i = 0; i < sentenceVector.size(); i++)if (wordRanking[i] == highestFrequency){
        outputfile << "was" << ":" << highestFrequency << ":";
        for (int k = 0; k < sentenceVector[i].size(); k++) 
            outputfile << sentenceVector[i][k] << " ";
            outputfile << endl;
        }
    outputfile.close();
}
void Question7(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_7.txt";
    outputfile.open(outputFilePrefix);
    vector<int> wordRanking;
    for (int i = 0; i < sentenceVector.size(); i++) {
        int wordcount = 0;
        for (int j = 0; j < sentenceVector[i].size()-1; j++) if ((sentenceVector[i][j].length() >= 3) && (sentenceVector[i][j + 1].length() >= 3))if ((sentenceVector[i][j].at(sentenceVector[i][j].length() - 3) == 'b') && (sentenceVector[i][j].at(sentenceVector[i][j].length() - 2) == 'u') && (sentenceVector[i][j].at(sentenceVector[i][j].length() - 1) == 't') && (sentenceVector[i][j + 1].at(0) == 't') && (sentenceVector[i][j + 1].at(1) == 'h') && (sentenceVector[i][j + 1].at(2) == 'e'))wordcount++;
        wordRanking.push_back(wordcount);
    }
    int highestFrequency = 0;
    for (int i = 0; i < wordRanking.size(); i++)if (wordRanking[i] > highestFrequency)highestFrequency = wordRanking[i];
   
    for (int i = 0; i < sentenceVector.size(); i++)if (wordRanking[i] == highestFrequency) {
        outputfile << "but the" << ":" << highestFrequency << ":";
        for (int k = 0; k < sentenceVector[i].size(); k++)outputfile << sentenceVector[i][k] << " ";
        outputfile << endl;
    }
    
    outputfile.close();
}
void Question8(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_8.txt";
    outputfile.open(outputFilePrefix);
    vector<int> wordRanking;
    for (int i = 0; i < sentenceVector.size(); i++) {
        int wordcount = 0;
        for (int j = 0; j < sentenceVector[i].size() - 1; j++) if ((sentenceVector[i][j].length() >= 2) && (sentenceVector[i][j + 1].length() >= 3))if ( (sentenceVector[i][j].at(sentenceVector[i][j].length() - 2) == 'i') && (sentenceVector[i][j].at(sentenceVector[i][j].length() - 1) == 't') && (sentenceVector[i][j + 1].at(0) == 'w') && (sentenceVector[i][j + 1].at(1) == 'a') && (sentenceVector[i][j + 1].at(2) == 's'))wordcount++;
        wordRanking.push_back(wordcount);
    }
    int highestFrequency = 0;
    for (int i = 0; i < wordRanking.size(); i++)if (wordRanking[i] > highestFrequency)highestFrequency = wordRanking[i];

    for (int i = 0; i < sentenceVector.size(); i++)if (wordRanking[i] == highestFrequency) {
        outputfile << "it was" << ":" << highestFrequency << ":";
        for (int k = 0; k < sentenceVector[i].size(); k++)outputfile << sentenceVector[i][k] << " ";
        outputfile << endl;
    }

    outputfile.close();
}
void Question9(vector<vector<string>> sentenceVector, string outputFilePrefix) {
    ofstream outputfile;
    outputFilePrefix += "_9.txt";
    outputfile.open(outputFilePrefix);
    vector<int> wordRanking;
    for (int i = 0; i < sentenceVector.size(); i++) {
        int wordcount = 0;
        for (int j = 0; j < sentenceVector[i].size() - 1; j++) if ((sentenceVector[i][j].length() >= 2) && (sentenceVector[i][j + 1].length() >= 2))if ((sentenceVector[i][j].at(sentenceVector[i][j].length() - 2) == 'i') && (sentenceVector[i][j].at(sentenceVector[i][j].length() - 1) == 'n') && (sentenceVector[i][j + 1].at(0) == 'm') && (sentenceVector[i][j + 1].at(1) == 'y') )wordcount++;
        wordRanking.push_back(wordcount);
    }
    int highestFrequency = 0;
    for (int i = 0; i < wordRanking.size(); i++)if (wordRanking[i] > highestFrequency)highestFrequency = wordRanking[i];

    for (int i = 0; i < sentenceVector.size(); i++)if (wordRanking[i] == highestFrequency) {
        outputfile << "in my" << ":" << highestFrequency << ":";
        for (int k = 0; k < sentenceVector[i].size(); k++)outputfile << sentenceVector[i][k] << " ";
        outputfile << endl;
    }

    outputfile.close();
}


int main(int argc, char* argv[]) {
    string inputfilename = argv[1];
    string outputFilePrefix = argv[2];
    fstream inputfile;
    inputfile.open(inputfilename);
    //cout << inputfile.is_open();
    vector<string> wordVector;
    vector<vector<string>> sentenceVector;
    ReadFromFile2(sentenceVector,wordVector);
    //CreateSentencesVector(wordVector,sentenceVector);
    
   // for(int i=0;i<wordVector.size();i++)if ((wordVector[i].back() == '.')||(wordVector[i].back() == '!')||(wordVector[i].back() == '?'))wordVector[i].pop_back();//delete punctuation
    
    vector<int> wordFrequencyVector(wordVector.size());
    RankWordFrequency(wordVector, wordFrequencyVector);
    Question1(wordFrequencyVector,wordVector, outputFilePrefix);
    Question2(wordFrequencyVector, wordVector, outputFilePrefix);

    Question3(sentenceVector, outputFilePrefix);

    Question4(sentenceVector, outputFilePrefix);
    Question5(sentenceVector, outputFilePrefix);
    Question6(sentenceVector, outputFilePrefix);
    Question7(sentenceVector, outputFilePrefix);
    Question8(sentenceVector, outputFilePrefix);
    Question9(sentenceVector, outputFilePrefix);
    

   
    



}
#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;


// x: input array
// n: length of array
double* prefixAverage1(double* x, int len) {
	double* a = new double[len];
	for (int j = 0; j < len; j++) {
		double total = 0;
		for (int i = 0; i <= j; i++) {
			total += x[i];
		}
		a[j] = total / (j + 1);
	}
	return a;
}


// x: input array
// n: length of array
double* prefixAverage2(double* x, int len) {
	double* a = new double[len];
	double total = 0;
	for (int j = 0; j < len; j++) {
		total += x[j];
		a[j] = total / (j + 1);
	}
	return a;
}


// x: input array
// n: length of array
int example1(int* x, int len) {
	int total = 0;
	for (int i = 0; i < len; i++) {
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example2(int* x, int len) {
	int total = 0;
	for (int i = 0; i < len; i += 2) {
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example3(int* x, int len) {
	int total = 0;
	for (int i = 0; i < len; i++) {
		for (int k = 0; k <= i; k++) {
			total += x[i];
		}
	}
	return total;
}


// x: input array
// n: length of array
int example4(int* x, int len) {
	int prefix = 0;
	int total = 0;
	for (int i = 0; i < len; i++) {
		prefix += x[i];
		total += prefix;
	}
	return total;
}


// x: input array
// n: length of array
int example5(int* first, int* second, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		int total = 0;
		for (int j = 0; j < len; j++) {
			for (int k = 0; k <= j; k++) {
				total += first[k];
			}
		}
		if (second[i] == total) {
			count++;
		}
	}
	return count;
}



int main(int argc, char** argv) {
	// depending on argv call one of these functions:
	// p1 for prefixAverage1, p2 for prefixAverage2, e1 for example1
	// e2 for example2, e3 for example3, e4 for example4, e5 for example5
	int inputSize = argv[3][0]-48;
	string algorithm = argv[1];
	string outputFileString = argv[2];
	
	clock_t clockStart;
	ofstream outputfile;
	outputfile.open(outputFileString);
	for (int i = 1; i <= inputSize; i++) {
		double length = pow(10, i);
		
		if (algorithm == "p1") {
			double* a = new double[(int)length];
			clockStart = clock();
			prefixAverage1(a, length);
		}
		else if (algorithm == "p2") {
			double* a = new double[(int)length];
			clockStart = clock();
			prefixAverage2(a, length);
		}
		else if (algorithm == "e1") {
			int* a = new int[(int)length];
			clockStart = clock();
			example1(a, length);
		}
		else if (algorithm == "e2") {
			int* a = new int[(int)length];
			clockStart = clock();
			example2(a, length);
		}
		else if (algorithm == "e3") {
			int* a = new int[(int)length];
			clockStart = clock();
			example3(a, length);
		}
		else if (algorithm == "e4") {
			int* a = new int[(int)length];
			clockStart = clock();
			example4(a, length);
		}
		else if (algorithm == "e5") {
			int* a = new int[(int)length];
			int* b = new int[(int)length];
			clockStart = clock();
			example5(a,b, length);
		}
		else {
			std::cout << "incorrect function name!";
			return -1;
		}
		
		clock_t clockEnd = clock();
		double logtime = log10((double)(clockEnd - clockStart) );
		std::cout <<fixed << setprecision(8)<< logtime<<endl;
		outputfile << fixed << setprecision(8) << logtime << endl;
		
	}
	outputfile.close();
	return 0;
}
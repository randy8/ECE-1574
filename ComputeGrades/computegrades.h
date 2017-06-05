#ifndef STUDENT_H 
#define STUDENT_H
#include <string>	
using namespace std;

struct Student {
	// int * myArray = new int[size];
	string first;
	string last;
	int attendCount;
	int labCount;
	int projCount;
	int sizeAttend;
	int sizeLab;
	int sizeProj;
	
	// Sums
	double attendSum;
	double labSum;
	double projSum;
	
	// Raw
	double mid;
	double fin;
	double attendEarn;
	double labEarn;
	double projEarn;
	
	// Possible
	int midPoss;
	int finPoss;
	
	// Calculated grades
	double attendAvg;
	double labAvg;
	double projAvg;
	double midAvg;
	double finAvg;
	double overall;
	string letter;
	
	// Arrays
	double *proj;
	double *lab;
	double *attend;
};

void computeGrades(string input, string output);
void growLab(Student &st);
void growAttend(Student &st);
void growProj(Student &st);
void sortAttend(Student &st);
void sortLab(Student &st);
void sortProj(Student &st);
void display(string input,string output, Student & st);
void gradeCalc(Student &st);
#endif

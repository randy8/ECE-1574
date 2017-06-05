 /* 
*  Purpose of the program:
*  We will be reading in data related to a fictitious student and their grades 
*  based on given percentage weightings for each type of assignment. 
*
*  Programmer: Randy Liang <randy8>
*  Date: April 20 2016
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "computegrades.h" 
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>	
#include <iomanip>
using namespace std;

/*
*  Function: growAttend
*  Purpose: This function doubles the size of the array when it has reached
*  its maximum size.
*  st - the struct that is being used.
*  tag - strcmp the type of assignment
*/
void growAttend(Student &st) {
	if (st.sizeAttend == st.attendCount) {
		double *temp = st.attend;
		st.attend = new double[st.sizeAttend*2];
		for (int i = 0; i < st.sizeAttend; i++) {
			st.attend[i] = temp[i];
		}
		delete [] temp;
	}
}

/*
*  Function: growLab
*  Purpose: This function doubles the size of the array when it has reached
*  its maximum size.
*  st - the struct that is being used.
*  tag - strcmp the type of assignment
*/
void growLab(Student &st) {
	if (st.sizeLab == st.labCount) {
		double *temp = st.lab;
		st.lab = new double[st.sizeLab*2];
		for (int i = 0; i < st.sizeLab; i++ ) {
			st.lab[i] = temp[i];
		}
		delete [] temp;
	}
}


/*
*  Function: growProj
*  Purpose: This function doubles the size of the array when it has reached
*  its maximum size.
*  st - the struct that is being used.
*  tag - strcmp the type of assignment
*/
void growProj(Student &st) {
	if (st.sizeProj == st.projCount) {
		double *temp = st.proj;
		st.proj = new double[st.sizeProj*2];
		for (int i = 0; i < st.sizeProj; i++) {
			st.proj[i] = temp[i];
		}
		delete [] temp;
	}
}

/*
*  Function: gradeCalc
*  Purpose: Calculates the averages of earned over sum and matches to
*  corresponding letter grade based on the overall grade.
*  st - the struct Student
*/
void gradeCalc(Student &st) {
	st.labAvg = (st.labEarn/ st.labSum) * (15);
	st.projAvg = (st.projEarn / st.projSum) * (40);
	st.attendAvg = (st.attendEarn / st.attendSum) * (5);
	st.midAvg = (st.mid / st.midPoss) * (20);
	st.finAvg = (st.fin / st.finPoss) * (20);
	
	st.overall = (st.labAvg + st.projAvg + st.attendAvg + st. midAvg + st.finAvg);
	
	if (st.overall > 93) {
		st.letter = "A";
	}
	else if (st.overall > 90) {
		st.letter = "A-";
	}
	else if (st.overall > 87) {
		st.letter = "B+";
	}
	else if (st.overall > 83) {
		st.letter = "B";
	}
	else if (st.overall > 80) {
		st.letter = "B-";
	}
	else if (st.overall > 77) {
		st.letter = "C+";
	}
	else if (st.overall > 73) {
		st.letter = "C";
	}
	else if (st.overall > 70) {
		st.letter = "C-";
	}
	else if (st.overall > 67) {
		st.letter = "D+";
	}
	else if (st.overall > 63) {
		st.letter = "D";
	}
	else if (st.overall > 60) {
		st.letter = "D-";
	}
	else {
		st.letter = "F";
	}
}

/*
*  Function: computeGrades
*  Purpose: This function will be the primary function 
*  for reading in the grades, and finding
*  and displaying the necessary information.
*  input - input grades
*  output - output grades
*/
void computeGrades(string input, string output) {
	ifstream in(input);
	ofstream out(output);
	Student st; // struct 
	st.first;
	st.last;
	// st.letter;
	// st.overall;
	 
	// Initialize the number of assignments by category
	st.sizeLab = 5;
    st.sizeAttend = 10;
	st.sizeProj = 5;
	
	// Counters
	st.projCount = 0;
	st.labCount = 0;
	st.attendCount = 0;
	 
	// Sum of points earned
	st.projSum;
	st.labSum;
	st.attendSum;
	 
	// Average score
	st.attendAvg;
	st.labAvg;
	st.projAvg;
	st.midAvg;
	st.finAvg;
	// st.overallAvg;
	 
	// Earned points
	st.labEarn;
	st.projEarn;
	st.attendEarn;
	
	// Intializes arrays
	st.proj = new double[st.sizeProj];
	st.lab = new double[st.sizeLab];
	st.attend = new double[st.sizeAttend];
	
	// Input vars
	string tag;
	int num; 
	int total;
	string name;
	
	in >> tag; // Reads in tag string and matches inputs
	while (!in.fail()) {
		if (tag == "First:") {
			in >> st.first;
		}
		else if (tag == "Last:") {
			in >> st.last;
		}
		else if (tag == "Attendance:") {
			if (st.sizeAttend == st.attendCount) {
				growAttend(st);
			}
			in >> num;
			in >> total;
			st.attendEarn += num;
			st.attendSum += total;
			st.attend[st.attendCount] = num;
			st.attendCount++;
		}
		else if (tag == "Lab:") {
			if (st.sizeLab == st.labCount) {
				growLab(st);
			}
			in >> num;
			in >> total;
			st.labEarn += num;
			st.labSum += total;
			st.lab[st.labCount] = num;
			st.labCount++;
		}
		else if (tag == "Project:") {
			if (st.sizeProj == st.projCount) {
				growProj(st);
			}
			in >> num;
			in >> total;
			st.projEarn += num;
			st.projSum += total;
			st.proj[st.projCount] = num;
			st.projCount++;
		}
		else if (tag == "Midterm:") {
			in >> st.mid;
			in >> st.midPoss;
		}
		else {
			in >> st.fin;
			in >> st.finPoss;
		}
		in >> tag;
	} // Ends reading input (i.e. fails)
	gradeCalc(st);
	display(input,output,st); 
	delete [] st.proj;
	delete [] st.lab;
	delete [] st.attend;
}

/*
*  Function: display
*  Purpose: This function displays all data in the output file of 
*  all the assignments upon averaging them.
*  input - input text file data 
*  output - output text file data
*  st - references struct Student
*/
void display(string input, string output, Student & st) {
	ifstream in(input);
	ofstream out(output);
	
	// Sort helper call
	sortAttend(st);
	sortLab(st);
	sortProj(st);
	 
	// Output 
	out << "First: " << st.first << endl;
	out << "Last: " << st.last << endl;
	out << "Attendances: ";
	for (int i = 0; i < st.attendCount; i++) {
		out << st.attend[i] << " ";
	}
	out << endl;
	out << "Attendance Grade: " << st.attendAvg << endl;
	out << "Labs: "; 
	for (int i = 0; i < st.labCount; i++) {
		out << st.lab[i] << " ";
	}
	out << endl;
	out << "Lab Grade: " << st.labAvg << endl;
	out << "Projects: "; 
	for (int i = 0; i < st.projCount; i++) {
		out << st.proj[i] << " ";
	}
	out << endl;
	out << "Project Grade: " << st.projAvg << endl;
	out << "Midterm: " << st.mid << endl;
	out << "Midterm Grade: " << st.midAvg << endl;
	out << "Final: " << st.fin << endl;
	out << "Final Grade: " << st.finAvg << endl;
	out << "Overall Average: " << st.overall << endl;
	out << "Letter Grade: " << st.letter << endl;
}

/*
*  Function: sortProj
*  Purpose: Sorts the arrays from least to greatest.
*  st - the struct Student
*/
void sortProj(Student &st) {
    int smallest;
    for (int i = 0; i < st.projCount-1; i++) {
        smallest = i;
        for (int j = i+1; j < st.projCount; j++) {
            if (st.proj[j] < st.proj[smallest]) {
                smallest = j;
			}
        }
        int temp = st.proj[smallest];
        st.proj[smallest] = st.proj[i];
        st.proj[i] = temp;
    }
}

/*
*  Function: sortLab
*  Purpose: Sorts the arrays from least to greatest.
*  st - the struct Student
*/
void sortLab(Student &st) {
    int smallest;
    for (int i = 0; i < st.labCount-1; i++) {
        smallest = i;
        for (int j = i+1; j < st.labCount; j++) {
            if (st.lab[j] < st.lab[smallest]) {
                smallest = j;
			}
        }
        int temp = st.lab[smallest];
        st.lab[smallest] = st.lab[i];
        st.lab[i] = temp;
    }
}

/*
*  Function: sortAttend
*  Purpose: Sorts the arrays from least to greatest.
*  st - the struct Student
*/
void sortAttend(Student &st) {
    int smallest;
    for (int i = 0; i < st.attendCount-1; i++) {
        smallest = i;
        for (int j = i+1; j < st.attendCount; j++) {
            if (st.attend[j] < st.attend[smallest]) {
                smallest = j;
			}
        }
        int temp = st.attend[smallest];
        st.attend[smallest] = st.attend[i];
        st.attend[i] = temp;
    }
}

int main() {
	computeGrades("input.txt", "output.txt");
	return 0;
}

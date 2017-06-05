#include <iostream> 
#include <string> 
#include <fstream>
using std::ifstream; 
using std::ofstream; 
using std::string; 
using std::istream; 
using std::ostream; 
using std::endl;


void minesweeper(string commands, string output);
void load(ifstream& in2, int array[8][8]);
void display(ostream& out, int array[8][8], int touched[8][8]);
void touch(ostream& out, int& x, int& y, char array[8][8], int& spacesTouched);
int numBombs(int touched[8][8],int array[8][8], int x, int y);
void finalBoard(ostream &out, int array[8][8], int touched[8][8]);

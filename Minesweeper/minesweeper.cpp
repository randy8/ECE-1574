#include "minesweeper.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * Given a series of commands in an input file, this program
 * acts accordingly, relying on int arrays to track bombs.
 */
void minesweeper(string commands, string output) {
    ifstream in(commands);
    ofstream out(output);
    int array[8][8];
    int touched[8][8] = {0};
    int spacesTouched = 0;
    int x, y;
    string command;
    bool gameOver = false;
    in >> command;

    while (!in.fail() && !gameOver && spacesTouched < 54) {
        out << "Command: " << command << " ";
        if (command == "load") {
            string file;
            in >> file;
            out << " " << file << endl;
            ifstream in2(file);
            load(in2, array);
        }
        else if (command == "display") {
            out << endl;
            display(out, array, touched);
        }
        else if (command == "touch") {
            in >> x >> y;
            out << x << " " << y << endl;

            int res = numBombs(touched, array, x - 1, y - 1);
            if (res == -1) {
                gameOver = true;
                spacesTouched++;
            }
            else {
                spacesTouched += res;
            }
        }
        in >> command;
    }
    out << "Game Over\n" << "~~~~~~~~~\n" << "Final Board" << endl;
    finalBoard(out, array, touched);
    out << "Spaces touched: " << spacesTouched << "\n";
}

void load(ifstream &in2, int array[8][8]) {
    for (int x = 0; x < 8; x++) {
        string checkBombs = "";
        getline(in2, checkBombs);
        for (int y = 0; y < 8; y++) {
            if (checkBombs[y] == '*') {
                array[x][y] = -1;
            }
            else {
                array[x][y] = 0;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (array[i][j] == -1) {
                for (int k = i - 1; k < i + 2; k++) {
                    if (k > -1 && k < 8) {
                        for (int l = j - 1; l < j + 2; l++) {
                            if (l > -1 && l < 8) {
                                if (array[k][l] != -1) {
                                    array[k][l]++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void display(ostream &out, int array[8][8], int touched[8][8]) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (touched[x][y] == 0) {
                out << '.';
            }
            else {
                if (array[x][y] == -1) {
                    out << '*';
                }
                else {
                    out << array[x][y];
                }
            }
        }
        out << endl;
    }
}

int numBombs(int touched[8][8], int array[8][8], int x, int y) {
    touched[x][y]++;
    if (array[x][y] == -1) {
        return -1;
    }
    if (touched[x][y] == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void finalBoard(ostream &out, int array[8][8], int touched[8][8]) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (touched[x][y] != 0) {
                if (array[x][y] == -1) {
                    out << '*';
                }
                else {
                    out << array[x][y];
                }
            }
            else {
                if (array[x][y] == -1) {
                    out << '@';
                }
                else {
                    out << '.';
                }
            }
        }
        out << endl;
    }
}

int main() {
    minesweeper("testcommands.txt", "output.txt");
    return 0;
}

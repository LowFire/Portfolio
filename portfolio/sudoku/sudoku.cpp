#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

string promptFile();
bool readFile(string filename, string board[]);
void interact(string board[]);
void edit(string board[]);
void displayInstructions();
void displayBoard(string board[]);
void showPossibleValues(string board[]);
int promptValue();
string promptCoordinates();
bool isValid(int value, string coordinates, string board[]);
string computeValues(string coordinates, string board[]);
void saveFile(string board[]);
string promptSaveLocation();

int main(int argc, char ** argv) {
    string board[9];
    string filename = promptFile();
    if (readFile(filename, board))
        interact(board);
    saveFile(board);
}

/*
promptFile
prompts the user for the filename of the sudoku board
*/
string promptFile() {
    string file;
    cout << "Where is your board located?: ";
    cin >> file;
    return file;
}

/*
readFile
reads the sudoku board from a file
*/
bool readFile(string filename, string board[]) {
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Failed to open file " << filename << endl;
        return false;
    }

    for (int i = 0; i < 9; i++) 
        getline(fin, board[i]);
    
    fin.close();
    return true;
}

/*
interact
begins the game loop and gets input from the user.
*/
void interact(string board[]) {
    displayBoard(board);
    displayInstructions();
    bool run = true; //controls game loop
    while(run) {
        char command;
        cout << "> ";
        cin >> command;
        cin.ignore(256, '\n');
        switch (command) {
            case '?':
                displayInstructions();
                break;
            case 'D':
            case 'd':
                displayBoard(board);
                break;
            case 'E':
            case 'e':
                edit(board);
                break;
            case 'S':
            case 's':
                showPossibleValues(board);
                break;
            case 'Q':
            case 'q':
                run = false;
                break;
            default:
                cout << "That is not a valid command. Type \'?\' for a list of" << 
                " possible commands." << endl;
                break;
        }
    }
}

/*
edit
allows the user to edit a square in the game board
*/
void edit(string board[]) {
    string coordinates = promptCoordinates();
    int value = promptValue();
    int col = coordinates[0] - 65;
    int row = coordinates[1] - 49;
    if (isValid(value, coordinates, board)){
        board[row][col] = value + 48;
        cout << endl;
    } else
        cout << "That number cannot be placed there." << endl;
}

/*
displayInstructions
Puts the games options on the console
*/
void displayInstructions() {
    cout << "Options: " << endl;
    cout << "\t?  Display these instructions" << endl;
    cout << "\tD  Display board" << endl;
    cout << "\tE  Edit one square" << endl;
    cout << "\tS  Show possible values for a square" << endl;
    cout << "\tQ  Save and quit" << endl;
}

/*
displayBoard
Puts the sudoku board on the console
*/
void displayBoard(string board[]) {
    cout << "   A B C D E F G H I\n\n";
    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0 && row > 0)
            cout << "   -----+-----+-----\n";
        cout << row + 1 <<  ' ';
        for (int col = 0; col < 9; col++) {
            if (col % 3 == 0 && col > 0)
                cout << '|' << (board[row][col] == '0' ? ' ' : board[row][col]);
            else
                cout << ' ' << (board[row][col] == '0' ? ' ' : board[row][col]);
            if (col == 8)
                cout << endl;
        }
    }
    cout << endl;
}

/*
showPossibleValues
Displays the possible values of a square on the console
*/
void showPossibleValues(string board[]) {
    //Prompt for coordinates
    string coordinates = promptCoordinates();
    string possibleValues = computeValues(coordinates, board);
    cout << "Possible values for " << coordinates << " are: ";
    for (int i = 0; i < possibleValues.length(); i++) {
        cout << possibleValues.at(i);
        if (i + 1 < possibleValues.length())
            cout << ", ";
    }
    cout << endl;
}

/*
promptValue
Prompts the user for a value between 1 and 9
*/
int promptValue() {
    int value = 0;
    while (value <= 0 || value > 9) {
        cout << "Enter a value: ";
        cin >> value;
        if (value <= 0 || value > 9)
            cout << "Value must be between 1 and 9" << endl;
    }
    cin.ignore();
    return value;
}

/*
promptCoordinates
Prompts the user for a row and colomn coordinate
*/
string promptCoordinates() {
    string coordinates;
    bool valid = false;
    while (!valid) {
        cout << "Enter coordinates of square: ";
        cin >> coordinates;
        valid = true;
        coordinates.at(0) = toupper(coordinates.at(0)); //Change to uppercase.
        if (coordinates.at(0) < 'A' || coordinates.at(0) > 'I' ||
        (coordinates.at(1) - 48) < 1 || (coordinates.at(1) - 48) > 9) {
            cout << "Those are not valid coordinates. First coordinate must be a letter"
            << " A - Z and second coordinate a number between 1 and 9."  << endl;
            valid = false;
        }
    }
    cout << endl;
    return coordinates;
}

/*
isValid
checks if a given value can be placed at the coordinates on the sudoku board
*/
bool isValid(int value, string coordinates, string board[]) {
    string possibleNumbers = computeValues(coordinates, board);
    bool valid = false;
    for (int i = 0; i < possibleNumbers.length(); i++)
        if (value == possibleNumbers.at(i) - 48) {
            valid = true;
            break;
        }
    return valid;
}

/*
computeValues
Finds all the possible values at a given coordinate on the sudoku board
*/
string computeValues(string coordinates, string board[]) {
    bool hasNumbers[9] = {
    //  1     2     3     4     5     6     7     8     9
        true, true, true, true, true, true, true, true, true
    };
    //convert coordinates into integer indexes
    int colCoord = coordinates[0] - 65;
    int rowCoord = coordinates[1] - 49;
    //Compare numbers in the current row of the coordinates
    for (int i = 0; i < 9; i++) {
        if (board[rowCoord][i] > '0') {
            int number = board[rowCoord][i] - 49;
            hasNumbers[number] = false;
        }
    }
    //Compare numbers in the current column of the coordinates
    for (int i = 0; i < 9; i++) {
        if (board[i][colCoord] > '0') {
            int number = board[i][colCoord] - 49;
            hasNumbers[number] = false;
        }
    }
    //Compare numbers in the current square of the coordinates
    int rowRangeStart = (rowCoord / 3) * 3;
    int rowRangeEnd = rowRangeStart + 3;
    int colRangeStart = (colCoord / 3) * 3;
    int colRangeEnd = colRangeStart + 3;
    for (int row = rowRangeStart; row < rowRangeEnd; row++) {
        for (int col = colRangeStart; col < colRangeEnd; col++){
            if (board[row][col] > '0'){
                int number = board[row][col] - 49;
                hasNumbers[number] = false;
            }
        }
    }
    //Find what numbers are left over
    string numbers;
    for (int i = 0; i < 9; i++) {
        if (hasNumbers[i] == true) {
            char numberChar = i + 49;
            numbers.push_back(numberChar);
        }
    }
    return numbers;
}

/*
saveFile
saves the sudoku board. Prompts the user for a save location
*/
void saveFile(string board[]) {
    string saveLocation = promptSaveLocation();
    ofstream fout;
    fout.open(saveLocation.c_str());
    if (fout.fail()){
        cout << "Failed to save file!" << endl;
        return;
    }

    for (int i = 0; i < 9; i++) {
        fout << board[i];
        fout << '\n';
    }
    cout << "Save successful" << endl;
    fout.close();
}

/*
promptSaveLocation
Prompts the user for a save location
*/
string promptSaveLocation() {
    string saveLocation;
    cout << "Where do you want to save your board?: ";
    cin >> saveLocation;
    return saveLocation;
}
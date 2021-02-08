#include <iostream>
#include <fstream>
#include <string>

#include "UnsortedList.cpp"
#include "Student.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

void testIntegerList();
void testStudentList();

int main() {
    int datatype;
    // Prompt user to enter type of elements 
    cout << "Enter Elements Type\n1 for integer\n2 for Student\n";
    cin >> datatype;
    switch (datatype) {
        case 1:
            testIntegerList();
            break;
        case 2:
            testStudentList();
            break;
    } // switch
    //….append any needed code here
    return EXIT_SUCCESS;
} // main


void testIntegerList() {
    ifstream inFile;
    inFile.open("intcommands.txt");
    ofstream outFile;
    outFile.open("outFile.txt");

    UnsortedList<int> list(5);
    int number;
    string command;
    while (command != "Quit") {
        inFile >> command;
        try {
            if (command == "MakeEmpty") {
                list.makeEmpty();
            } else if (command == "IsEmpty") {
                if (list.isEmpty()) {
                    outFile << "list is empty" << endl;
                } else {
                    outFile << "list is not empty" << endl;
                } // if
            } else if (command == "IsFull") {
                if (list.isFull()) {
                    outFile << "List is full" << endl;
                } else {
                    outFile << "List is not full" << endl;
                } // if
            } else if (command == "PutItem") {
                inFile >> number;
                list.putItem(number);
            } else if (command == "DeleteItem") {
                inFile >> number;
                list.deleteItem(number);
            } else if (command == "GetLength") {
                outFile << list.getLength() << endl;
            } else if (command == "PrintList") {
                outFile << "List Items: ";
                for (int index = 0; index < list.getLength(); index++) {
                    int value = list.getAt(index);
                    outFile << value << " ";
                } // for
                outFile << endl;
            } else if (command == "GetAt") {
                int index;
                inFile >> index;
                outFile << "Item at index " << index << " is: " << list.getAt(index) << endl;
            } else {
                outFile << "Unrecognized command" << endl;
            } // if
        } catch (FullList) {
            outFile << "List is full, Insertion failed" << endl;
        } catch (EmptyList) {
            outFile << "List is empty" << endl;
        } catch (DuplicateItem) {
            outFile << "Duplicate Item, Insertion failed" << endl;
        } catch (OutofBound) {
            outFile << "Index is out of range" << endl;
        } catch (ItemNotFound) {
            outFile << "Item is not in the list" << endl;
        } // try
    } // while

    inFile.close();
    outFile.close();
} // testIntegerList

void testStudentList() {
    // Add code to test the Student list, similar to testIntegerList
    ifstream inFile;
    inFile.open("studcommands.txt");
    ofstream outFile;
    outFile.open("outFile.txt");

    UnsortedList<Student> students{5};
    string command;
    while (command != "Quit") {
        inFile >> command;
        try {

        } catch (FullList) {
            outFile << "List is full, Insertion failed" << endl;
        } catch (EmptyList) {
            outFile << "List is empty" << endl;
        } catch (DuplicateItem) {
            outFile << "Duplicate Item, Insertion failed" << endl;
        } catch (OutofBound) {
            outFile << "Index is out of range" << endl;
        } catch (ItemNotFound) {
            outFile << "Item is not in the list" << endl;
        } // try
    } // while

    inFile.close();
    outFile.close();
} // testStudentList


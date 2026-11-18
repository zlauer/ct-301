#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "element.h"
using namespace std;

double rightDouble;
double leftDouble;
int rightInt;
int leftInt;
string op;
Element newElement;

void toElement(string newVal){
    newElement = Element(newVal);
}

void toElement(int newVal){
    newElement = Element(newVal);
}

void toElement(double newVal){
    newElement = Element(newVal);
}


// conversion - meant to only convert the left number into an int or a double
void conversion(string operand){
    try
    {
        if(newElement.type_ == ElementType::DOUBLE){
            leftDouble = stod(operand);
            std::cout << leftDouble;
        }
        else
        {
            leftInt = stoi(operand);
            std::cout << leftInt;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: cannot convert to numeric value." << '\n';
        exit(2);
    }
    
}

// citation found on HW3/doc.md for AI usage under argumentChecker(string) 
void argumentChecker(string line){
    string right;
    string left;
    string ope;

    std::stringstream ss(line);
    std::string word;
    
    std::vector<std::string> lineSeperated;

    while (ss >> word) {
        lineSeperated.push_back(word);
    }
    
    right = lineSeperated[0];
    ope = lineSeperated[1];
    left = lineSeperated[2];

    toElement(right);
    op = ope;
    conversion(left);

}

// citation found on HW3/doc.md under function's name openFile.
void openFile(string fileName){
    ifstream inFS;
    string fileLine;

    inFS.open(fileName);

    if(!inFS.is_open()){
        cerr << "Error: could not open file " << fileName << "." << endl;
    }

    while (getline(inFS, fileLine))
    {
        // overload of argumentChecker()
        argumentChecker(fileLine);

    }
    if(!inFS.eof()){
        cerr << "uhhh end of file error uhhh" << endl;
    }

    //remembering to close the file
    inFS.close();


}


void argumentChecker(int count, char* arguments[]){
    string right;
    string left;
    string ope;
    string fileName;

    if(count == 2){
        fileName = arguments[1];
        openFile(fileName);
    } else {
        right = arguments[1];
        ope = arguments[2];
        left = arguments[3];
        // instead -- taking the two elements and passing them into elements from Here
        // toElement(left); -- only seems to be really meant to affect one of the elements in the overall problem instead of both
        toElement(right);
        op = ope;
        conversion(left);
        
    }
    
}


void outputMessage(){
 
    std::cout << newElement.Value() << " ";
    std::cout << op << " ";
    std::cout << endl;    
}


int main(int argc, char* argv[]){
    // main(haha) goal for this is to check if there's anything other
    // than the calculator executable in order to pass it further on

    if(argc < 2){
        // end program
        std::cerr << "Error: Not enough arguments entered." << endl;
        exit(1);
    }
    else if (argc > 4)
    {
        std::cerr << "Error: Too many arguments entered." << endl;
        exit(2);
    }
    
    argumentChecker(argc, argv);

    outputMessage();
    
    return 0;
}

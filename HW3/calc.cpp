#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "element.h"
using namespace std;

bool isDouble = false;
double rightDouble;
double leftDouble;
int rightInt;
int leftInt;
string op;
Element rightElement;
Element leftElement;
Element result;

void toElementRight(string newVal){
    rightElement = Element(newVal);
}

void toElementRight(int newVal){
    rightElement = Element(newVal);
}

void toElementRight(double newVal){
    rightElement = Element(newVal);
}

void toElementLeft(string newVal){
    leftElement = Element(newVal);
}

void toElementLeft(int newVal){
    leftElement = Element(newVal);
}

void toElementLeft(double newVal){
    leftElement = Element(newVal);
}


// conversion - meant to only convert the left number into an int or a double
void conversion(string operand){
    try
    {
        if(rightElement.type_ == ElementType::DOUBLE){
            leftDouble = stod(operand);
            isDouble = true;
        }
        else
        {
            leftInt = stoi(operand);
            isDouble = false;
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

    toElementRight(right);
    op = ope;
    toElementLeft(left);

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
        toElementRight(right);
        op = ope;
        toElementLeft(left);
        
    }
    
}


 void evaluateExpression(string op){
    Element solution;
    switch (op.at(0))
    {
    case '+':
        solution = leftElement + rightElement;
        break;
    
    case '-':
        solution = leftElement - rightElement;
        break;
    
    case '*':
        solution = leftElement * rightElement;
        break;
    
    case '/':
        if(leftElement.Value() == 0){
            std::cerr << "Error: cannot divide by zero." << endl;
            exit(4);
        }
        solution = leftElement / rightElement;
        break;
    
    case '%':
        solution = leftElement % rightElement;
        break; 
    default:
        break;
    }
    
    cout << solution.Value() << endl;
    
    //return 0;
}

void outputMessage(){
 
    std::cout << rightElement.Value() << " ";
    std::cout << op << " ";
    std::cout << leftElement.Value() << " ";
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

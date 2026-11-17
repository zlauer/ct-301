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
Element* left = new Element();
Element* right = new Element();

/* HELPER FUNCTIONS */

//purpose is to take the arguments from the command-line input
// from here > determine if there is a file or numbers
void argumentChecker(int count, char* arguments[]){
    string right;
    string left;
    string op;
    string fileName;

    if(count == 2){
        fileName = arguments[1];
        openFile(fileName);
    } else {
        right = arguments[1];
        op = arguments[2];
        left = arguments[3];
        //conversion(right, left, op);

        // instead -- taking the two elements and passing them into elements from Here
        toElement(left, right);
        
    }
    
}

void toElement(string left, string right){
    Element leftObj(left);
    Element rightObj(right);
}

/*      I ENDED UP ASKING GOOGLE AI FOR HELP ON THIS :(
search query: 
i have a string that i want loaded into an array of strings seperated by the space character

code:

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string text = "C++ split string by space example";
    
    // Use a stringstream to read words separated by whitespace
    std::stringstream ss(text);
    std::string word;
    
    // A vector dynamically handles the array size for you
    std::vector<std::string> words;

    // Extract words one by one
    while (ss >> word) {
        words.push_back(word);
    }

    // Print the results
    std::cout << "Words in the array:\n";
    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << i << ": " << words[i] << "\n";
    }

    return 0;
}

*/
void argumentChecker(string line){
    string right;
    string left;
    string op;

    std::stringstream ss(line);
    std::string word;
    
    std::vector<std::string> lineSeperated;

    while (ss >> word) {
        lineSeperated.push_back(word);
    }
    
    right = lineSeperated[0];
    op = lineSeperated[1];
    left = lineSeperated[2];

    conversion(right, left, op);

}

bool isDouble(string num){
    for (size_t i = 0; i < num.length()-1; i++)
    {
        if(num.at(i) == '.'){
            return true;
        }
    }
    return false; 
}



/* I USED SOME HELP ON THIS FROM GOOGLE AI:

search query:
how to check if string can be converted to number c++

code:
#include <iostream>
#include <string>
#include <stdexcept>

bool isNumeric(const std::string& str) {
    if (str.empty()) return false;
    
    try {
        size_t pos;
        std::stoi(str, &pos); // Or std::stod(str, &pos) for floating point
        
        // Check if the entire string was processed
        return pos == str.size();
    } catch (const std::invalid_argument& e) {  <-- THIS IS THE LINE I USED
        return false; // Not a number
    } catch (const std::out_of_range& e) {
        return false; // Number is too large or small for an int
    }
}


*/
void conversion(string rightOperand, string leftOperand, string op){
    try
    {
        if(isDouble(rightOperand) == true || isDouble(leftOperand) == true){
            rightDouble = stod(rightOperand);
            leftDouble = stod(leftOperand);
            isDouble(rightDouble, leftDouble, op);
        }
        else
        {
            rightInt = stoi(rightOperand);
            leftInt = stoi(leftOperand);
            isInt(rightInt, leftInt, op);
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: cannot convert to numeric value." << '\n';
        exit(2);
    }
    
}


// LOOKED UP HELP FROM GEEKSFORGEEKS:
// https://www.geeksforgeeks.org/cpp/read-input-until-eof-in-cpp/
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

/*      CALCULATION FUNCTIONS       */

double isDouble(double rightOperand, double leftOperand, string op){
    double solution;
    switch (op.at(0))
    {
    case '+':
        solution = rightOperand + leftOperand;
        break;
    
    case '-':
        solution = rightOperand - leftOperand;
        break;
    
    case '*':
        solution = rightOperand * leftOperand;
        break;
    
    case '/':
        if(leftOperand == 0){
            std::cerr << "Error: cannot divide by zero." << endl;
            exit(4);
        }
        solution = rightOperand / leftOperand;
        break;
    
    case '%':
        std::cerr << "Error: cannot perform this action with the specified numbers." << endl;
        exit(4);
        break; 
    default:
        break;
    }

    cout << solution << endl;

    return 0;
}

int isInt(int rightOperand, int leftOperand, string op){
    double solution;
    switch (op.at(0))
    {
    case '+':
        solution = rightOperand + leftOperand;
        break;
    
    case '-':
        solution = rightOperand - leftOperand;
        break;
    
    case '*':
        solution = rightOperand * leftOperand;
        break;
    
    case '/':
        if(leftOperand == 0){
            std::cerr << "Error: cannot divide by zero." << endl;
            exit(4);
        }
        solution = rightOperand / leftOperand;
        break;
    
    case '%':
        solution = rightOperand % leftOperand;
        break; 
    default:
        break;
    }
    
    cout << solution << endl;
    
    return 0;
}

void outputMessage(){
    
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
    
    return 0;
}


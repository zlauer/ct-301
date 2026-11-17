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

/*    OVERLOADED OPERATORS     */


/*  ADDITION    */

// asked ai for help w this logic:
/* ai code:
        Element operator+(const Element& lhs, double rhs) {
    if (lhs.type_ == ElementType::INT) {
        return Element(static_cast<double>(lhs.intValue) + rhs); // Int + Double = Double
    }
    return Element(lhs.doubleValue + rhs); // Double + Double = Double
}

Element operator+(double lhs, const Element& rhs) {
    return rhs + lhs; // Reuses Element + double logic
}
*/
    // element + double (both r doubles)
    Element operator+(const Element& lhs, const double& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(static_cast<double>(lhs.intValue + rhs));
        }
        return Element(lhs.doubleValue + rhs);
    }
    
    // element + int (both r ints)
    Element operator+(const Element& lhs, const int& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(lhs.intValue) + rhs;
        }
        return lhs.intValue + rhs;
    }
    
    // double + element
    Element operator+(const double& lhs, const Element& rhs){
        return rhs + lhs;
    }
   
    // int + element
    Element operator+(const int& lhs, const Element& rhs){
        return rhs + lhs;
    }


/*  SUBTRACTION    */
    // element - double (both r doubles)
    Element operator-(const Element& lhs, const double& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(static_cast<double>(lhs.intValue - rhs));
        }
        return Element(lhs.doubleValue) - rhs;
    }
    
    // element - int (both r ints)
    Element operator-(const Element& lhs, const int& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(lhs.intValue) - rhs;
        }
        return lhs.intValue - rhs;
    }
    
    // double - element
    Element operator-(const double& lhs, const Element& rhs){
        return lhs - rhs;
    }
   
    // int - element
    Element operator-(const int& lhs, const Element& rhs){
        return lhs - rhs;
    }


/*  MULTIPLY    */
    // element * double (both r doubles)
    Element operator*(const Element& lhs, const double& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(static_cast<double>(lhs.intValue * rhs));
        }
        return Element(lhs.doubleValue) * rhs;
    }
    
    // element * int (both r ints)
    Element operator*(const Element& lhs, const int& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(lhs.intValue) * rhs;
        }
        return lhs.intValue * rhs;
    }

    // double * element
    Element operator*(const double& lhs, const Element& rhs){
        return lhs * rhs;
    }

    // int * element
    Element operator*(const int& lhs, const Element& rhs){
        return lhs * rhs;
    }

/*  DIVISION    */
    // element / double (both r doubles)
    Element operator/(const Element& lhs, const double& rhs){
        if(rhs != 0.0){
            if(lhs.type_ == ElementType::INT){
            return Element(static_cast<double>(lhs.intValue / rhs));
        }
            return Element(lhs.doubleValue) / rhs;
        }
        exit(2);

    }

    // element / int (both r ints)
    Element operator/(const Element& lhs, const int& rhs){
        if(rhs != 0){
            if(lhs.type_ == ElementType::INT){
                return Element(lhs.intValue) / rhs;
            }
        }
        exit(2);

    }

    // double / element
    Element operator/(const double& lhs, const Element& rhs){
        if(rhs.doubleValue != 0){
            return lhs / rhs;
        }
        exit(2);
    }

    // int / element
    Element operator/(const int& lhs, const Element& rhs){
        if(rhs.doubleValue != 0){
            return lhs / rhs;
        }
        exit(2);
    }

/*  MODULO  */
// element % double (both r doubles)
  /*  Element operator%(const Element& lhs, const double& rhs){
        std::cerr << "error: cannot compute modulo with presented numbers:" << endl;
        exit(2);

    } */

    // element % int (both r ints)
    Element operator%(const Element& lhs, const int& rhs){
        if(rhs != 0){
            if(lhs.type_ == ElementType::INT){
                return Element(lhs.intValue) % rhs;
            }
        }
        exit(2);

    }

    // double % element
   /* Element operator%(const double& lhs, const Element& rhs){
        std::cerr << "error: cannot compute modulo with presented numbers: " << endl;
        exit(2);
    }*/

    // int % element
    Element operator%(const int& lhs, const Element& rhs){
        return lhs % rhs;
    }

    //Element &operator<<(const Element& lhs, const Element& rhs){    }



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
        //conversion(right, left, op);

        // instead -- taking the two elements and passing them into elements from Here
        // toElement(left); -- only seems to be really meant to affect one of the elements in the overall problem instead of both
        toElement(right);
        op = ope;
        conversion(left);
        
    }
    
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


void outputMessage(){
 
    std::cout << newElement.Value() << op << endl;    
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

/* HELPER FUNCTIONS */

//purpose is to take the arguments from the command-line input
// from here > determine if there is a file or numbers

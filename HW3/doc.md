This is a document meant to show where and how I received help pertaining to certain functions and functionality in HW3.  I will include previous homeworks' contributions here, as well, and will indicate whether or not they are still actively being used.

# calc.cpp

### Previous homework help(HW2):
**argumentChekcer(string line)**  this is a function designed to take in a line from a file and break it into seperate elements to manipulate.  AI help recieved:
```
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
```
**void conversion(string rightOperand, string leftOperand, string op)**  this is a function designed to take the individual components of an equation and convert them into the appropriate type (of type int or of type double).  AI help recieved:
```
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
```
**void openFile(string fileName)**  is a function designed to open a file from the command line.  I found help on [GeeksforGeeks](https://www.geeksforgeeks.org/cpp/read-input-until-eof-in-cpp/).

# element.cpp
**operator+ (Element + int, int + int logic)**  took my previous iteration of an operator overload for addition and helped me understand where infinite recursion would occur.
```
```// Element + int
Element operator+(const Element& lhs, const int& rhs) {
    if (lhs.type_ == ElementType::INT) {
        return Element(lhs.IntValue() + rhs);
    }
    else if (lhs.type_ == ElementType::DOUBLE) {
        return Element(lhs.DoubleValue() + rhs);
    }
    else {
        throw std::invalid_argument("Invalid Element addition");
    }
}
 
# operation.cpp
 --

# operation.h
 --

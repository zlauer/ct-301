This is a webpage detailing places where I got help and other citations that may be of note.  I wanted them noted in code and also in another form of documentation.

# calc.cpp
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

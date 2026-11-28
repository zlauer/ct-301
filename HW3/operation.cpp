#include <iostream>
#include <cstdlib>
#include "element.h"

Element* leftElem;
Element* rightElem;
char op;
// might need to be pointers instead of straight up Element types


/*
    Operation(const string& element) - Parses a 3-token equation string (e.g. "4.6 - 99")
        Throws InvalidElement if fewer than 3 tokens are present, or if the string has excess trailing variables
        Throws InvalidOperator if the operator is invalid
        Note: ensure that there are no memory leaks if the Element creation fails midway
        to do: 
        -break into tokens by delimeter(a space) (toToken(string&)?)
            --> toElement?
        -convert into correct types(of type Element and char)(Operation(Element&, char, Element&))
            (i think this would work? thereby loads the correct type )
        -load into 
*/
Operation::Operation(const std::string& element){

}

Operation::Operation(const Element& leftElem, char op, const Element& rightElem){
    this->leftElem = leftElem;
    this->op = op;
    this->rightElem = rightElem;

}

Operation::Operation(const Operation& other){

}

Operation& operator=(Operation){

}

// the idea here seems to be to call the appropriate evaluation function depending on type
double Operation::Value() const{
    if(IsDouble == true){
        return DoubleValue();
    }
    return IntValue()

}

/* CALCULATION FUNCTIONS */
//  integer arithmetic
int Operation::IntValue() const{}


//  double arithmetic
double Operation::DoubleValue() const{
    
}

bool Operation::IsDouble() const{
    if(leftElem.type == Element::INT && rightElem.type_ == ElementType::INT){
        return false;
    }
    return true;
}
/*
    i think it would make sense for this implementation to be different than Element's
    bc we're working with Element's to begin with
*/

Element* Operation::Clone() cont{}

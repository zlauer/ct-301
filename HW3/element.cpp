#include <iostream>
#include <cstdlib>
#include "element.h"


/*    OVERLOADED OPERATORS     */


/*  ADDITION    */

    // Element + double
    Element operator+(const Element& lhs, const double& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(lhs.intValue + rhs);
        }
        else if(lhs.type_ == ElementType::DOUBLE){
            return Element(lhs.DoubleValue() + rhs);
        }
        else {
            throw std::invalid_argument("Invalid Element Addition.");
        }
    }
    
    // Element + int -- ASKED FOR HELP W THIS. citation found on HW3/doc.md
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
    
    // double + element
    Element operator+(const double& lhs, const Element& rhs){
        return rhs + lhs;
    }
   
    // int + element
    Element operator+(const int& lhs, const Element& rhs){
        return rhs + lhs;
    }


/*  SUBTRACTION    */
    // Element - double
    Element operator-(const Element& lhs, const double& rhs){
         if(lhs.type_ == ElementType::INT){
            return Element(lhs.intValue - rhs);
        }
        else if(lhs.type_ == ElementType::DOUBLE){
            return Element(lhs.DoubleValue() - rhs);
        }
        else {
            throw std::invalid_argument("Invalid Element Subtraction.");
        }
    }
    
    // Element - int
    Element operator-(const Element& lhs, const int& rhs){
        if (lhs.type_ == ElementType::INT) {
            return Element(lhs.IntValue() - rhs);
        }
        else if (lhs.type_ == ElementType::DOUBLE) {
            return Element(lhs.DoubleValue() - rhs);
        }
        else {
            throw std::invalid_argument("Invalid Element - int subtraction");
        }
    }
    
    // double - element
    Element operator-(const double& lhs, const Element& rhs){
        if(rhs.type_ == ElementType::DOUBLE){
            return Element(lhs - rhs.DoubleValue());
        }
        else if(rhs.type_ == ElementType::INT){
            return Element(lhs - rhs.IntValue());
        } else {
            throw std::invalid_argument("Invalid Element subtraction");
        }
    }
   
    // int - element
    Element operator-(const int& lhs, const Element& rhs){
        if(rhs.type_ == ElementType::INT){
            return Element(lhs - rhs.IntValue());
        }
        else if(rhs.type_ == ElementType::INT){
            return Element(lhs - rhs.DoubleValue());
        } else {
            throw std::invalid_argument("Invalid Element subtraction");
        }
    }


/*  MULTIPLY    */
    // Element * double
    Element operator*(const Element& lhs, const double& rhs){
    if(lhs.type_ == ElementType::INT){
        return Element(lhs.IntValue() * rhs);
    }
    else if(lhs.type_ == ElementType::DOUBLE){
        return Element(lhs.DoubleValue() * rhs);
    }
    else {
        throw std::invalid_argument("Invalid Element Multiplication.");
    }
}

    // Element * int
    Element operator*(const Element& lhs, const int& rhs){
    if(lhs.type_ == ElementType::DOUBLE){
        return Element(lhs.DoubleValue() * rhs);
    }
    else if(lhs.type_ == ElementType::INT){
        return Element(lhs.IntValue() * rhs);
    }
    else {
        throw std::invalid_argument("Invalid Element Multiplication.");
    }
}

    // double * element
    Element operator*(const double& lhs, const Element& rhs){
        return rhs * lhs;
    }

    // int * element
    Element operator*(const int& lhs, const Element& rhs){
        return rhs * lhs;
    }

/*  DIVISION  : i recieved help in this section. documentation can be found in HW3/doc.md  */

// Element / double
Element operator/(const Element& lhs, const double& rhs){
    if(rhs == 0.0){
        exit(2);
    }

    if(lhs.type_ == ElementType::INT){
        return Element(lhs.IntValue() / rhs);
    }
    else if(lhs.type_ == ElementType::DOUBLE){
        return Element(lhs.DoubleValue() / rhs);
    }
    else {
        throw std::invalid_argument("Invalid Element Division.");
    }
}

// Element / int
Element operator/(const Element& lhs, const int& rhs){
    if(rhs == 0){
        exit(2);
    }

    if(lhs.type_ == ElementType::INT){
        return Element(lhs.IntValue() / rhs);
    }
    else if(lhs.type_ == ElementType::DOUBLE){
        return Element(lhs.DoubleValue() / rhs);
    }
    else {
        throw std::invalid_argument("Invalid Element Division.");
    }
}

// double / Element
Element operator/(const double& lhs, const Element& rhs){
    if(rhs.type_ == ElementType::INT){
        if(rhs.IntValue() == 0){
            exit(2);
        }
        return Element(lhs / rhs.IntValue());
    }
    else if(rhs.type_ == ElementType::DOUBLE){
        if(rhs.DoubleValue() == 0.0){
            exit(2);
        }
        return Element(lhs / rhs.DoubleValue());
    }
    else {
        throw std::invalid_argument("Invalid Element Division.");
    }
}

// int / Element
Element operator/(const int& lhs, const Element& rhs){
    if(rhs.type_ == ElementType::INT){
        if(rhs.IntValue() == 0){
            exit(2);
        }
        return Element(lhs / rhs.IntValue());
    }
    else if(rhs.type_ == ElementType::DOUBLE){
        if(rhs.DoubleValue() == 0.0){
            exit(2);
        }
        return Element(static_cast<double>(lhs) / rhs.DoubleValue());
    }
    else {
        throw std::invalid_argument("Invalid Element Division.");
    }
}

/*  MODULO    */

// Element % double
Element operator%(const Element& lhs, const double& rhs){
    if(lhs.IntValue() == 0){
        exit(2);
    }
    if(rhs == 0){
        exit(2);
    }
    exit(2);
}

// Element % int
Element operator%(const Element& lhs, const int& rhs){
    if(rhs == 0){
        exit(2);
    }

    if(lhs.type_ == ElementType::INT){
        return Element(lhs.IntValue() % rhs);
    }
    else {
        exit(2);
    }
}

// double % Element
Element operator%(const double& lhs, const Element& rhs){
    if(lhs == 0){
        exit(2);
    }
    if(rhs.IntValue() == 0){
        exit(2);
    }
    exit(2);
}

// int % Element
Element operator%(const int& lhs, const Element& rhs){
    if(rhs.type_ == ElementType::INT){
        if(rhs.IntValue() == 0){
            exit(2);
        }
        return Element(lhs % rhs.IntValue());
    }
    else {
        exit(2);
    }
}


Element::Element(int newInt){
    this->intValue = newInt;
    this->type_ = ElementType::INT;
}

Element::Element(double newDouble){
    this->doubleValue = newDouble;
    this->type_ = ElementType::DOUBLE;

}

Element::Element(const std::string& newVal){
    /*  Parses and validates the string input, setting the Element to store either 
    a double or an integer depending on the formatted input. Throws a std::invalid_argument 
    exception if the string argument cannot be parsed as a valid number. */
    this->strVal = newVal;
    try{
        //goal is to parse it into an integer or a double -- basically conversion()
        if(isDouble() == true){
            this->doubleValue = std::stod(newVal);
            this->type_ = ElementType::DOUBLE;
            std::cout << "doubleValue: " << doubleValue << std::endl;
            //changeType();
        } else {
            this->intValue = std::stoi(newVal);
            this->type_ = ElementType::INT;
            std::cout << "intValue: " << intValue << std::endl;
        }

        

    }catch(const std::invalid_argument& e){
        std::invalid_argument("Invalid argument.");
        exit(0);
    }

}

double Element::Value() const{
    if(this->type_ == ElementType::DOUBLE){
    std::cout << "IntValue reached in Value" << std::endl;
        return DoubleValue();
    }
    return IntValue();
}

double Element::DoubleValue() const{
    return this->doubleValue;
}

int Element::IntValue() const{
    return this->intValue;
}

bool Element::isDouble() const{
    //this implementation is geared toward the Element(string)
    // i reached for help with this -- I used AI for the contents of the if statement
    if(strVal.find('.') == std::string::npos){
        /* considering i asked for help on this portion i figure it would be helpful
            to kind of demonstrate understanding -- std::string::npos is no position */
        return false;
    }
    return true;
}

void Element::Value(double newVal){
    if(this->type_ == ElementType::DOUBLE){
        this->doubleValue = newVal;

    } else if(this->type_ == ElementType::INT){
        this->intValue = static_cast<int>(newVal);
    }
}

void Element::changeType(){
    if(type_ == ElementType::DOUBLE){
        type_ = ElementType::INT;     

    }
    else {
        type_ = ElementType::DOUBLE; 
    }

}

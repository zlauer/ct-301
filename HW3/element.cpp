#include <iostream>
#include "element.h"


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

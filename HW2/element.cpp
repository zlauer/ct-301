#include <iostream>
#include "element.h"


Element::Element(int newInt){
    this->intValue = newInt;
}

Element::Element(double newDouble){
    this->doubleValue = newDouble;

}

Element::Element(const std::string& newVal){
    this->strVal = newVal;
    try{
        //goal is to parse it into an integer or a double -- basically conversion()
        if(isDouble() == true){
            this->doubleValue = std::stod(newVal);
        }
            this->intValue = std::stoi(newVal);
        

    }catch(const std::invalid_argument& e){
        std::invalid_argument("Invalid argument.");
    }

}

double Element::Value() const{
    return 0.0;
}

double Element::DoubleValue() const{
    return Element::doubleValue;
}

int Element::IntValue() const{
    return this->intValue;
}

bool Element::isDouble(){
    if(doubleValue.has_value()){
        return true;
    }
    // trying to write java boo boo boo
    return false;
}

void Value(double newVal){
    std::cout << newVal << std::endl;
}

void changeType(){

}

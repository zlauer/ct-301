#include <iostream>
#include "element.h"


/*    OVERLOADED OPERATORS     */


/*  ADDITION    */

// asked ai for help w this logic:

    // element + double (both r doubles)
    Element operator+(const Element& lhs, const double& rhs){
        if(lhs.type_ == ElementType::INT){
            return Element(static_cast<double>(lhs.intValue + rhs));
        }
        return Element(lhs.doubleValue + rhs);
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

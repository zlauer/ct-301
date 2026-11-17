#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <iostream>

enum class ElementType { NONE, INT, DOUBLE, STRING };

class Element {
    public:
     ElementType type_ = ElementType::NONE; 
    double doubleValue = 0.0;
    int intValue = 0.0;
    // nullpointer, no null in c++
    // std::optional<wtv type(like double)> variableName = std::nullopt;
    std::string strVal;
    Element* val;

    Element() = default;
    Element(int newInt);
    Element(double newDouble);
    Element(const std::string& newVal);

    double Value() const;
    double DoubleValue() const;
    int IntValue() const;
    bool isDouble() const;
    void Value(double newVal);
    void changeType();

    // element + double (both r doubles)
    friend Element operator+(const Element& lhs, const double& rhs);
    // element + int (both r ints)
    friend Element operator+(const Element& lhs, const int& rhs);
    // double + element
    friend Element operator+(const double& lhs, const Element& rhs);
    // int + element
    friend Element operator+(const int& lhs, const Element& rhs);


    // element - double (both r doubles)
    friend Element operator-(const Element& lhs, const double& rhs);
    // element - int (both r ints)
    friend Element operator-(const Element& lhs, const int& rhs);
    // double - element
    friend Element operator-(const double& lhs, const Element& rhs);
    // int - element
    friend Element operator-(const int& lhs, const Element& rhs);

    // element * double (both r doubles)
    friend Element operator*(const Element& lhs, const double& rhs);
    // element * int (both r ints)
    friend Element operator*(const Element& lhs, const int& rhs);
    // double * element
    friend Element operator*(const double& lhs, const Element& rhs);
    // int * element
    friend Element operator*(const int& lhs, const Element& rhs);

    // element / double (both r doubles)
    friend Element operator/(const Element& lhs, const double& rhs);
    // element / int (both r ints)
    friend Element operator/(const Element& lhs, const int& rhs);
    // double / element
    friend Element operator/(const double& lhs, const Element& rhs);
    // int / element
    friend Element operator/(const int& lhs, const Element& rhs);

    // element % double (both r doubles)
   // friend Element operator%(const Element& lhs, const double& rhs);
    // element % int (both r ints)
    friend Element operator%(const Element& lhs, const int& rhs);
    // double % element
  //  friend Element operator%(const double& lhs, const Element& rhs);
    // int % element
    friend Element operator%(const int& lhs, const Element& rhs);

    
    //friend Element &operator<<(const Element& lhs, const Element& rhs);
};


#endif

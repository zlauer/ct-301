#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <iostream>

class Element {
    public:
    double doubleValue = 0.0;
    int intValue = 0;
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
    bool isDouble();
    void Value(double newVal);
    void changeType();
};


#endif

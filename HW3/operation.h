#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

class Operation : public Element{
    private:
    Element* leftElem;
    char op;
    Element* rightElem;

    public:
    /*
    Operation(const string& element) - Parses a 3-token equation string (e.g. "4.6 - 99")
        Throws InvalidElement if fewer than 3 tokens are present, or if the string has excess trailing variables
        Throws InvalidOperator if the operator is invalid
        Note: ensure that there are no memory leaks if the Element creation fails midway
    Operation(const Element& leftElem, char op, const Element& rightElem) - Constructs an Operation object from existing Element objects using polymorphic cloning (Clone()).
        Checks that the operator "op" is valid and throws InvalidOperator if not.
    Operation(const Operation& other) - Copy constructor, performs a deep copy of the left and right equation objects using .Clone()
    Operation& operator= (Operation other) - Assignment operator
        Note: Our implementation utilizes the std::swap function, but is not required
        virtual ~Operator() - Destructor, should ensure that the left and right Element members are properly freed. 
        Note: If your base class Element does not already contain a virtual destructor, you should add one 
    */
    Operation() = default;
    Operation(const std::string& element);
    Operation(const Element& leftElem, char op, const Element& rightElem);
    Operation(const Operation& other);
    Operation& operator=(Operation);
    ~Operator();

    /*
    virtual double Value() const override - Evaluates the left and right elements and performs integer or floating-point math depending on 
        types of the elements and returns the result as a double. Proper exception throwing should still be performed 
    virtual int IntValue() const override - Evaluates the left and right operands as integers (utilizing IntValue()), performs integer math, 
        and returns the resulting truncated integer
    virtual double DoubleValue() const override - Evaluates the left and right operands as doubles (utilizing DoubleValue()), performs 
        floating-point arithmetic, and returns the result as a double 
    virtual bool IsDouble() const override - Returns true if floating-point math must be performed depending on the type of left and right 
        Element members 
    virtual Element* Clone() const override - Returns a new heap-allocated copy of the current Operation object. 
    A similar Clone() method should be added to your Element class that returns a new heap-allocated copy of the current Element object
    */

    double Value() const : public virtual Element{};
    int IntValue() const : public virtual Element{};
    double DoubleValue() const : public virtual Element{};
    bool IsDouble() const : public virtual Element{};
    Element* Clone() const : public virtual Element{};
}

#include "element.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Keep track of test results.
int passed = 0;
int failed = 0;

// Check whether the result matches the expected value and type.
void check(const string& testName, const Element& result,
           double expected, ElementType expectedType) {

    bool valueCorrect = (result.Value() == expected);
    bool typeCorrect = (result.type_ == expectedType);

    if (valueCorrect && typeCorrect) {
        cout << "[PASS] " << testName << endl;
        passed++;
    } else {
        cout << "[FAIL] " << testName
             << " | Expected: " << expected
             << " | Got: " << result.Value()
             << " | Expected type: " << static_cast<int>(expectedType)
             << " | Got type: " << static_cast<int>(result.type_)
             << endl;
        failed++;
    }
}

// Catch exceptions so one failed test does not stop the suite.
template <typename Func>
void checkThrows(const string& testName, Func operation) {
    try {
        operation();
        cout << "[FAIL] " << testName << " | Expected an exception"
             << endl;
        failed++;
    } catch (const exception&) {
        cout << "[PASS] " << testName << endl;
        passed++;
    }
}

int main() {

        cout << "TEST PROGRAM STARTED!" << endl;


    Element i1(10);
    Element i2(3);
    Element d1(10.5);
    Element d2(2.5);
    Element str;
    str.type_ = ElementType::STRING;
    str.strVal = "hello";
    Element empty;

    cout << "\n========== ADDITION ==========\n";

    check("Element + Element (INT + INT)", i1 + i2, 13, ElementType::INT);
    check("Element + Element (INT + DOUBLE)", i1 + d2, 12.5, ElementType::DOUBLE);
    check("Element + Element (DOUBLE + INT)", d1 + i2, 13.5, ElementType::DOUBLE);
    check("Element + Element (DOUBLE + DOUBLE)", d1 + d2, 13.0, ElementType::DOUBLE);

    check("Element + int", i1 + 5, 15, ElementType::INT);
    check("Element + double", i1 + 2.5, 12.5, ElementType::DOUBLE);
    check("int + Element", 5 + i1, 15, ElementType::INT);
    check("double + Element", 2.5 + i1, 12.5, ElementType::DOUBLE);

    cout << "\n========== SUBTRACTION ==========\n";

    check("Element - Element (INT - INT)", i1 - i2, 7, ElementType::INT);
    check("Element - Element (INT - DOUBLE)", i1 - d2, 7.5, ElementType::DOUBLE);
    check("Element - Element (DOUBLE - INT)", d1 - i2, 7.5, ElementType::DOUBLE);
    check("Element - Element (DOUBLE - DOUBLE)", d1 - d2, 8.0, ElementType::DOUBLE);

    check("Element - int", i1 - 3, 7, ElementType::INT);
    check("Element - double", i1 - 2.5, 7.5, ElementType::DOUBLE);
    check("int - Element", 15 - i1, 5, ElementType::INT);
    check("double - Element", 15.5 - i1, 5.5, ElementType::DOUBLE);

    cout << "\n========== MULTIPLICATION ==========\n";

    check("Element * Element (INT * INT)", i1 * i2, 30, ElementType::INT);
    check("Element * Element (INT * DOUBLE)", i1 * d2, 25.0, ElementType::DOUBLE);
    check("Element * Element (DOUBLE * INT)", d1 * i2, 31.5, ElementType::DOUBLE);
    check("Element * Element (DOUBLE * DOUBLE)", d1 * d2, 26.25, ElementType::DOUBLE);

    check("Element * int", i1 * 3, 30, ElementType::INT);
    check("Element * double", i1 * 2.5, 25.0, ElementType::DOUBLE);
    check("int * Element", 3 * i1, 30, ElementType::INT);
    check("double * Element", 2.5 * i1, 25.0, ElementType::DOUBLE);

    cout << "\n========== DIVISION ==========\n";

    check("Element / Element (INT / INT)", i1 / i2, 3, ElementType::INT);
    check("Element / Element (INT / DOUBLE)", i1 / d2, 4.0, ElementType::DOUBLE);
    check("Element / Element (DOUBLE / INT)", d1 / i2, 3.5, ElementType::DOUBLE);
    check("Element / Element (DOUBLE / DOUBLE)", d1 / d2, 4.2, ElementType::DOUBLE);

    check("Element / int", i1 / 2, 5, ElementType::INT);
    check("Element / double", i1 / 2.5, 4.0, ElementType::DOUBLE);
    check("int / Element", 30 / i1, 3, ElementType::INT);
    check("double / Element", 30.0 / i1, 3.0, ElementType::DOUBLE);

    cout << "\n========== MODULO ==========\n";

    check("Element % int", i1 % 3, 1, ElementType::INT);
    check("int % Element", 23 % i1, 3, ElementType::INT);
    check("Element % Element (INT % INT)", i1 % i2, 1, ElementType::INT);

    cout << "\n========== INVALID OPERATIONS ==========\n";

    /*
    checkThrows("STRING + Element", [&]() { auto result = str + i1; });
    checkThrows("Element + STRING", [&]() { auto result = i1 + str; });
    checkThrows("NONE + Element", [&]() { auto result = empty + i1; });
    checkThrows("Element + NONE", [&]() { auto result = i1 + empty; });
    */

    cout << "\n========== TEST SUMMARY ==========\n";
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;
    cout << "Total:  " << passed + failed << endl;

    return failed == 0 ? 0 : 1;
}

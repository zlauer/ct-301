
#include <iostream>
#include <stdexcept>
#include "element.h"

using namespace std;

int main() {

    cout << "===== ELEMENT OPERATOR TESTS =====" << endl;

    try {

        // TEST 1: INT + INT
        cout << "\nTEST 1: INT + INT" << endl;

        Element a(5);
        Element b(5);

        Element result1 = a + b;

        cout << "Expected: 10" << endl;
        cout << "Result: " << result1.IntValue() << endl;


        // TEST 2: DOUBLE + DOUBLE
        cout << "\nTEST 2: DOUBLE + DOUBLE" << endl;

        Element c(5.5);
        Element d(2.5);

        Element result2 = c + d;

        cout << "Expected: 8.0" << endl;
        cout << "Result: " << result2.DoubleValue() << endl;


        // TEST 3: INT + DOUBLE
        cout << "\nTEST 3: INT + DOUBLE" << endl;

        Element e(5);
        Element f(2.5);

        Element result3 = e + f;

        cout << "Expected: 7.5" << endl;
        cout << "Result: " << result3.DoubleValue() << endl;


        // TEST 4: DOUBLE + INT
        cout << "\nTEST 4: DOUBLE + INT" << endl;

        Element g(5.5);
        Element h(2);

        Element result4 = g + h;

        cout << "Expected: 7.5" << endl;
        cout << "Result: " << result4.DoubleValue() << endl;


        // TEST 5: ELEMENT + INT
        cout << "\nTEST 5: ELEMENT + INT" << endl;

        Element i(10);

        Element result5 = i + 5;

        cout << "Expected: 15" << endl;
        cout << "Result: " << result5.IntValue() << endl;


        // TEST 6: ELEMENT + DOUBLE
        cout << "\nTEST 6: ELEMENT + DOUBLE" << endl;

        Element j(10);

        Element result6 = j + 5.5;

        cout << "Expected: 15.5" << endl;
        cout << "Result: " << result6.DoubleValue() << endl;


        cout << "\n===== ALL TESTS COMPLETED =====" << endl;

    }
    catch (const exception& e) {
        cerr << "TEST FAILED: " << e.what() << endl;
        return 1;
    }

    return 0;
}

/******************************************************************************
 * LAB: Pointers and Pass-by-Reference   [TEACHER SOLUTION]
 * COURSE: CMP1001 - Introduction to Programming (C++)
 * DURATION: 60 minutes
 *
 * DESCRIPTION:
 *   In this lab you will learn how memory addresses work, how to use pointers
 *   to read and modify variables indirectly, and how pass-by-reference lets a
 *   function change the caller's variables. You will also see why pointers and
 *   references matter for real programs (e.g. swapping, in-place updates).
 *
 * INSTRUCTIONS:
 *   - Everything stays in THIS single file (MainProgram.cpp).
 *   - Do NOT add header files or split into multiple files.
 *   - Read each section's comments, then complete every // TODO: marker.
 *   - The file already compiles. Keep it compiling as you work.
 *   - Test as you go: compile and run after finishing each section.
 *
 * COMPILE & RUN:
 *   g++ MainProgram.cpp -o lab
 *   ./lab
 ******************************************************************************/

#include <iostream>
#include <cmath>      // for round() in the challenge
using namespace std;

/* ===========================================================================
 * FUNCTION PROTOTYPES
 * ======================================================================== */
void swapByPointer(int* a, int* b);
void swapByReference(int& a, int& b);
void incrementByReference(int& n);
int  sumAndCount(const int arr[], int size, int& outCount);
void normalizeTemperature(double& celsius);
void clampToRange(int& value, int low, int high);

/* ===========================================================================
 * MAIN
 * ======================================================================== */
int main() {
    cout << "=== Pointers and Pass-by-Reference Lab ===\n\n";

    /* ---------------- SECTION 1 - WARM-UP ---------------- */
    cout << "--- Section 1: Warm-up ---\n";

    // 1a
    int score = 75;
    cout << "Score: " << score << "\n";

    // 1b
    int x = 8, y = 3;
    cout << "Sum: "  << (x + y) << "\n";
    cout << "Diff: " << (x - y) << "\n";

    cout << "\n";

    /* ---------------- SECTION 2 - CORE CONCEPTS ---------------- */
    cout << "--- Section 2: Core Concepts ---\n";

    int value = 42;
    int* ptr = &value;
    cout << "value      = " << value  << "\n";
    cout << "*ptr       = " << *ptr   << "\n";
    *ptr = 100;
    cout << "value now  = " << value  << "\n";

    // 2a - modify through the pointer only
    int apples = 10;
    int* pApples = &apples;
    *pApples += 5;
    cout << "apples = " << apples << "\n";   // 15

    // 2b - reference is an alias
    int gold = 50;
    int& alias = gold;
    alias = 99;
    cout << "gold = " << gold << "\n";       // 99

    cout << "\n";

    /* ---------------- SECTION 3 - GUIDED EXERCISES ---------------- */
    cout << "--- Section 3: Guided Exercises ---\n";

    int p = 1, q = 2;
    swapByPointer(&p, &q);
    cout << "After swapByPointer:   p=" << p << " q=" << q << "\n";

    int r = 7, s = 9;
    swapByReference(r, s);
    cout << "After swapByReference: r=" << r << " s=" << s << "\n";

    int counter = 4;
    incrementByReference(counter);
    incrementByReference(counter);
    cout << "Counter after 2 increments: " << counter << "\n";

    int data[] = {10, 20, 30, 40};
    int howMany = 0;
    int total = sumAndCount(data, 4, howMany);
    cout << "Sum=" << total << " Count=" << howMany << "\n";

    cout << "\n";

    /* ---------------- SECTION 4 - CHALLENGE ---------------- */
    cout << "--- Section 4: Challenge ---\n";

    double t1 = -0.03, t2 = 36.66;
    normalizeTemperature(t1);
    normalizeTemperature(t2);
    cout << "Normalized: t1=" << t1 << " t2=" << t2 << "\n";

    int vol = 130;
    clampToRange(vol, 0, 100);
    cout << "Clamped volume: " << vol << "\n";

    int bright = -20;
    clampToRange(bright, 0, 255);
    cout << "Clamped brightness: " << bright << "\n";

    cout << "\n=== End of Lab ===\n";
    return 0;
}

/* ===========================================================================
 * FUNCTION DEFINITIONS  [SOLUTIONS]
 * ======================================================================== */

// Exercise 3.1 - swap via dereferencing
void swapByPointer(int* a, int* b) {
    int temp = *a;   // read value pointed to by a
    *a = *b;         // write b's value into a's location
    *b = temp;       // write saved value into b's location
}

// Exercise 3.2 - swap via references (a, b are aliases of caller's vars)
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Exercise 3.3 - modify caller's variable directly
void incrementByReference(int& n) {
    n = n + 1;
}

// Exercise 3.4 - return sum, and report count through an out-parameter
int sumAndCount(const int arr[], int size, int& outCount) {
    outCount = size;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Challenge 4.1 - in-place normalization
void normalizeTemperature(double& celsius) {
    celsius = round(celsius * 10.0) / 10.0;   // round to 1 decimal
    if (celsius < 0.05 && celsius > -0.05) {
        celsius = 0.0;                        // kill noise near zero
    }
}

// Challenge 4.2 - in-place clamp into [low, high]
void clampToRange(int& value, int low, int high) {
    if (value < low)  value = low;
    if (value > high) value = high;
}

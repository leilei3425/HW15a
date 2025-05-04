// HW15a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//May 03 2025

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Custom exception classes
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: invalidCharacterException";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: invalidRangeException";
    }
};

// Function prototype  
char character(char start, int offset);


int main(){

    try {
        cout << character('a', 1) << endl;
        cout << character('b', -1) << endl;
        cout << character('Z', -1) << endl;
        cout << character('?', 5) << endl;
        cout << character('A', 32) << endl;
    }
    catch (const invalidCharacterException& e) {
        cout << "  Exception: " << e.what() << "\n";
    }
    catch (const invalidRangeException& e) {
        cout << "  Exception: " << e.what() << "\n";
    }
    

    return 0;
}

// Function that calculates a character based on a starting character and an offset
char character(char start, int offset) {
    // Check if start is a letter
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }
    
    bool isUpperCase = (start >= 'A' && start <= 'Z');

    // Convert to 0-25 range (A=0, B=1, ..., Z=25 or a=0, b=1, ..., z=25)
    int startValue = isUpperCase ? (start - 'A') : (start - 'a');

    // Calculate the target value without using modulo yet
    int targetValue = startValue + offset;

    // Check if target value is outside of the valid range (0-25)
    // This prevents wrapping and ensures we throw an exception for out-of-range values
    if (targetValue < 0 || targetValue > 25) {
        throw invalidRangeException();
    }

    // Convert back to ASCII
    char result = isUpperCase ? ('A' + targetValue) : ('a' + targetValue);

    return result;
}


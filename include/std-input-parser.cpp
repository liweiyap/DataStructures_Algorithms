/**
 * list of functions for parsing/properly interpreting inputs from standard input
 */

// uncomment this block if wishing to debug
/*
#ifndef DEBUG_HEX
#define DEBUG_HEX
#endif
 */

#ifndef STD_INPUT_PARSER_H
#include "std-input-parser.hpp"
#endif


/**
 * retrieves a line from standard input, streams it to a string stream, and converts value in line to integer
 *
 * @return single integer value parsed from standard input
 * @throws InvalidInput() exception thrown if some of the characters are not digits
 * @throws Overflow() exception thrown if integer is greater than INT_MAX
 * @throws Underflow() exception thrown if integer is smaller than INT_MIN
 */
int dsa::parseDigits(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    long value;
    if ( !(iss >> value) || !(iss.eof()) ) throw InvalidInput();
    if ( value > std::numeric_limits<int>::max() ) throw Overflow();
    if ( value < std::numeric_limits<int>::min() ) throw Underflow();
    return static_cast<int>(value);
}  // end of funtion


/**
 * retrieves a line from standard input, streams it to a string stream, and converts value in line to unsigned integer
 *
 * @return single unsigned integer value parsed from standard input
 * @throws InvalidInput() exception thrown if some of the characters are not digits
 * @throws Overflow() exception thrown if integer is greater than INT_MAX
 * @throws Underflow() exception thrown if integer is smaller than 0
 */
unsigned int dsa::parseDigitsUnsigned(){
    int value;
    value = parseDigits();
    if (value < 0) throw Underflow();
    return static_cast<unsigned int>(value);
}  // end of function

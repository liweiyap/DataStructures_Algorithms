/**
 * list of functions for parsing/properly interpreting inputs from standard input
 */

#ifndef STD_INPUT_PARSER_H
#define STD_INPUT_PARSER_H
#pragma once

#ifndef EXCEPTIONS_H
#include "exceptions.hpp"
#endif

#include <iostream>
#include <limits>    // numeric_limits
#include <string>    // getline
#include <sstream>


namespace dsa{

    /**
     * retrieves a line from standard input, streams it to a string stream, and converts value in line to integer
     *
     * @return single integer value parsed from standard input
     * @throws InvalidInput() exception thrown if some of the characters are not digits
     * @throws Overflow() exception thrown if integer is greater than INT_MAX
     * @throws Underflow() exception thrown if integer is smaller than INT_MIN
     */
    int parseDigits();
    
    /**
     * retrieves a line from standard input, streams it to a string stream, and converts value in line to unsigned integer
     *
     * @return single unsigned integer value parsed from standard input
     * @throws InvalidInput() exception thrown if some of the characters are not digits
     * @throws Overflow() exception thrown if integer is greater than INT_MAX
     * @throws Underflow() exception thrown if integer is smaller than 0
     */
    unsigned int parseDigitsUnsigned();

}  // end of namespace dsa


#endif

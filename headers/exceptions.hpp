/**
 * list of exceptions that can be thrown in case of run-time errors
 */

#ifndef EXCEPTIONS
#define EXCEPTIONS
#pragma once

class MyException{};
class InvalidInput: public MyException{};
class Overflow: public MyException{};
class Underflow: public MyException{};
class OutOfRange: public MyException{};

#endif

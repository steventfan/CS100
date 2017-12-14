#ifndef __DECORATOR_H_
#define __DECORATOR_H_

#include "component.h"
#include <iostream>
#include <cmath>

class Ceiling: public Operator
{
    public:
        Ceiling() : Operator() {};
        Ceiling(Base *left) : Operator(left, 0) {};
        double evaluate()
        {
            return std::ceil(this->left->evaluate() );
        };
};

class Floor: public Operator
{
    public:
        Floor() : Operator() {};
        Floor(Base *left) : Operator(left, 0) {};
        double evaluate()
        {
            return std::floor(this->left->evaluate() );
        };
};

class Absolute: public Operator
{
    public:
        Absolute() : Operator() {};
        Absolute(Base *left) : Operator(left, 0) {};
        double evaluate()
        {
            return std::abs(this->left->evaluate() );
        };
};

#endif
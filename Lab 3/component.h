#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Base
{
    public:
        /* Constructors */
        Base() {};

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};

class Op: public Base
{
    private:
        double value;
    
    public:
        Op() : Base(), value(0) {};
        Op(double val) : Base(), value(val) {};
        double evaluate() 
        {
            return this->value;
        };
};

class Operator: public Base
{
    protected: 
        Base *left, *right;
    public: 
        Operator() : Base() {};
        Operator(Base *l, Base *r) : left(l), right(r) {};
        Base *get_left()
        {
            return left;
        };
        Base *get_right()
        {
            return right;
        };
        
        virtual double evaluate() = 0; 
};

class Add: public Operator
{
    public: 
        Add() : Operator() {};
        Add(Base *left, Base *right) : Operator(left, right) {};
        double evaluate()
        {
            return this->left->evaluate() + this->right->evaluate();
        };
};

class Sub: public Operator
{
    public:
        Sub() : Operator() {};
        Sub(Base *left, Base *right) : Operator(left, right) {};
        double evaluate()
        {
            return this->left->evaluate() - this->right->evaluate();
        };
};

class Mult: public Operator
{
    public: 
        Mult() : Operator() {};
        Mult(Base *left, Base *right) : Operator(left, right) {};
        double evaluate()
        {
            return this->left->evaluate() * this->right->evaluate();
        };
};

class Div: public Operator
{
    public: 
        Div() : Operator() {};
        Div(Base *left, Base *right) : Operator(left, right) {};
        double evaluate()
        {
            return this->left->evaluate() / this->right->evaluate();
        };
};

class Sqr: public Operator
{
    public:
        Sqr() : Operator() {};
        Sqr(Base *left) : Operator(left, 0) {};
        double evaluate()
        {
            return this->left->evaluate() * this->left->evaluate();
        };
};

#endif // __COMPONENT_H__
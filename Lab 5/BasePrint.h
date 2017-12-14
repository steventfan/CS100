#ifndef __BASEPRINT_H__
#define __BASEPRINT_H__

#include <iostream>
#include <bitset>

class BasePrint
{
	protected:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		BasePrint() {};
		BasePrint(double value) : value(value) {};
		
		/* Pure Virtual Print Function */
		virtual void print() = 0;
};

class DoublePrint : public BasePrint
{
    public:
        DoublePrint() : BasePrint() {};
        DoublePrint(double value) : BasePrint(value) {};
        void print();
};

class HexPrint : public BasePrint
{
    public:
    	HexPrint() : BasePrint() {};
    	HexPrint(double value) : BasePrint(value) {};
        void print();
};

class BinaryPrint : public BasePrint
{
    public:
    	BinaryPrint() : BasePrint() {};
    	BinaryPrint(double value) : BasePrint(value) {};
        void print();
};

#endif
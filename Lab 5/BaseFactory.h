#ifndef __BASEFACTORY_H__
#define __BASEFACTORY_H__

#include "BasePrint.h"

class BaseFactory
{
	public:
		/* Constructor */
		BaseFactory() {};

		/* Pure Virtual Generate Function */
		virtual BasePrint * generatePrint(double value) = 0;
};

class DoubleFactory : public BaseFactory
{
    public:
        DoubleFactory() : BaseFactory() {};
        BasePrint * generatePrint(double);
};

class HexFactory : public BaseFactory
{
    public: 
        HexFactory() : BaseFactory() {};
        BasePrint * generatePrint(double);
};

class BinaryFactory : public BaseFactory
{
    public:
        BinaryFactory() : BaseFactory() {};
        BasePrint * generatePrint(double);
};

#endif
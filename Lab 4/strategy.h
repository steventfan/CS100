#ifndef __STRATEGY_H__
#define __STRATEGY_H__
#include "container.h"

class Sort
{
    public: 
        /* Constructors */
        Sort() {};

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

class SelectionSort: public Sort
{
    public:
        void sort(Container* container)
        {
            for(int i = 0; i < container->size() - 1; i++)
            {
                for(int j = i + 1; j < container->size(); j++)
                {
                    if( (container->at(i) )->evaluate() < (container->at(j) )->evaluate() )
                    {
                        container->swap(i, j);
                    }
                }
            }
        }
};

class BubbleSort: public Sort
{
    public:
        void sort(Container* container)
        {
            int i, j, flag = 1;    // set flag to 1 to start first pass
            int numLength = container->size();
            for(i = 1; (i <= numLength) && flag; i++)
            {
                flag = 0;
                for (j = 0; j < numLength - 1; j++)
                {
                    if (container->at(j + 1)->evaluate() > container->at(j)->evaluate() )
                    {      // ascending order simply changes to < 
                        container->swap(j + 1, j);
                        flag = 1;               // indicates that a swap occurred.
                    }
                }
            }
            return;   //arrays are passed to functions by address; nothing is returned
        }
};

#endif // __STRATEGY_H__
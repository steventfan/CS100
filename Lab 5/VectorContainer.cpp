#include "container.h"
#include "strategy.h"

/* Pure Virtual Functions */
// insert the top pointer of the tree into the container
void VectorContainer::add_element(Base* element)
{
    vectorContainer.push_back(element);
}

// iterate through the trees and output values
void VectorContainer::print()
{
    BasePrint *print;
    
    for(unsigned i = 0; i < vectorContainer.size(); i++)
    {
        print = factoryPointer->generatePrint(vectorContainer.at(i)->evaluate() );
        print->print();
        std::cout << std::endl;
    }
}

// calls on the previously set sorting-algorithm. 
// Check if sort_function is not null, throw exception if is null
void VectorContainer::sort()
{                                                       
    try {
        if(sort_function == NULL)
        {
            throw std::runtime_error("Sorting algorithm has not been chosen");
        }
        sort_function->sort(this);
    }
    catch (std::runtime_error& except)
    {
        std::cout << except.what() << std::endl;
    }
    //implement
}

/* Essentially the only functions needed to sort */
// switch tree locations
void VectorContainer::swap(int i,int j)
{
    Base* temp = vectorContainer.at(i);
    vectorContainer.at(i) = vectorContainer.at(j);
    vectorContainer.at(j) = temp;
}

// get top pointer of tree at index i
Base* VectorContainer::at(int i)
{
    return vectorContainer.at(i);
}

// return container size;
int VectorContainer::size()
{
    return vectorContainer.size();
}

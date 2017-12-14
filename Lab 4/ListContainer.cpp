#include "container.h"
#include "strategy.h"

void ListContainer::add_element(Base* element)
{
    listContainer.push_back(element);
}

// iterate through the trees and output value
void ListContainer::print()
{
    it = listContainer.begin();
    while(it != listContainer.end() )
    {
        std::cout << (*it)->evaluate() << std::endl;
        it++;
    }
}

// calls on the previously set sorting-algorithm. 
// Check if sort_function is not null, throw exception if is null
void ListContainer::sort()                                                                             //NEED TO IMPLEMENT
{
    try
    {
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
void ListContainer::swap(int i,int j)
{
    std::list<Base *>::iterator ti = listContainer.begin();
    for(int k = 0; k < i; k++)
    {
        ti++;
    }
    Base *temp = *ti;
    it = listContainer.begin();
    for(int k = 0; k < j; k++)
    {
        it++;
    }
    *ti = *it;
    *it = temp;
}

// get top pointer of tree at index i
Base* ListContainer::at(int i)
{
    it = listContainer.begin();
    for(int j = 0; j < i; j++)
    {
        it++;
    }
    return *it;
    
}

// return container size;
int ListContainer::size()
{
    return listContainer.size();
}
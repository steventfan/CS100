#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include "component.h"
#include "BasePrint.h"
#include "BaseFactory.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

class Sort; //forward declaration

class Container
{
    protected: 
        Sort *sort_function;
        BaseFactory *factoryPointer;

    public: 
        /* Cosntructors */
        Container() : sort_function(NULL), factoryPointer(NULL) {};
        Container(BaseFactory* pointer) : factoryPointer(pointer) {}; 
        
        /* Non Virtual Functions */
        // Set the type of sorting algorithm
        void set_sort_function(Sort* sort_function);

        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container
        virtual void add_element(Base* element) = 0;
        // iterate through the trees and output values
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. 
        // Check if sort_function is not null, throw exception if is null
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        // switch tree locations
        virtual void swap(int i,int j) = 0;
        // get top pointer of tree at index i
        virtual Base* at(int i) = 0;
        // return container size;
        virtual int size() = 0;
};

class VectorContainer: public Container
{
    public:
        std::vector<Base *> vectorContainer; //should be private? 
        
        VectorContainer() {};
        VectorContainer(BaseFactory *pointer) : Container(pointer) {};
        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container
        void add_element(Base* element);
        // iterate through the trees and output values
        void print();
        // calls on the previously set sorting-algorithm. 
        // Check if sort_function is not null, throw exception if is null
        void sort();
        /* Essentially the only functions needed to sort */
        // switch tree locations
        void swap(int i,int j);
        // get top pointer of tree at index i
        Base* at(int i);
        // return container size;
        int size();
};

class ListContainer: public Container
{
    public:
        std::list<Base *> listContainer;
        std::list<Base *>::iterator it;
        
        ListContainer() {};
        ListContainer(BaseFactory *pointer) : Container(pointer) {};
        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container        
        void add_element(Base* element);
        // iterate through the trees and output value
        void print();
        // calls on the previously set sorting-algorithm. 
        // Check if sort_function is not null, throw exception if is null
        void sort();
        /* Essentially the only functions needed to sort */
        // switch tree locations
        void swap(int i,int j);
        // get top pointer of tree at index i
        Base* at(int i);
        // return container size;
        int size();
};

#endif // __CONTAINER_H__
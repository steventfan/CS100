#include <iostream>
#include "component.h"
#include "decorator.h"
#include "container.h"
#include "strategy.h"
#include "BasePrint.h"
#include "BaseFactory.h"
#include <iostream>

// class Test
// {
//     public:
//         double number;
//         BaseFactory *pointer;
//         BasePrint *print;
        
//         Test() {};
//         Test(double value) : number(value) {};
// };

int main(int argc, char *argv[])
{
    //DoublePrint *object = new DoublePrint(2.19); //doublePrint test
    //HexPrint *object = new HexPrint(2.01);
    // double number = 5.03;
    
    // DoubleFactory *factoryObject = new DoubleFactory();
    // BasePrint *printObject = factoryObject->generatePrint(number);
    
    
    
    // Test *object = new Test(5.03);
    
    // //object->pointer = new DoubleFactory();
    // //object->pointer = new HexFactory();
    // object->pointer = new BinaryFactory();
    
    
    // object->print = object->pointer->generatePrint(object->number);
    // object->print->print();
    
   // object->print();
    //std::cout << std::endl;
    
    
    
    Op* op7 = new Op(7.1);
    Op* op4 = new Op(4.2);
    //Op* op4 = new Op(-1000.2);
    Op* op3 = new Op(3.3);
    Op* op2 = new Op(2.4);
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, A);
    Sub* C = new Sub(B, op2);
    // --- Sqr* D = new Sqr(C);
    Add* D = new Add(C, op3);
    Ceiling* E = new Ceiling(D);
    //Floor* E = new Floor(D);
    //Absolute* E = new Absolute(D);
    
    BaseFactory *pointer;
    
    if(*argv[1] == 'h')
    {
        pointer = new HexFactory();
    }
    else if(*argv[1] == 'b')
    {
        pointer = new BinaryFactory();
    }
    else
    {
        pointer = new DoubleFactory();
    }
    
    
    //VectorContainer* container = new VectorContainer(pointer);
    ListContainer* container = new ListContainer(pointer);
    container->add_element(A);
    container->add_element(A);
    container->add_element(B);
    container->add_element(B);
    container->add_element(C);
    container->add_element(C);
    container->add_element(D);
    container->add_element(D);
    container->add_element(E);
    container->add_element(E);
    
    std::cout << "Container Before Sort: " << std::endl;
    container->print();

    std::cout << std::endl << "Container After Sort: " << std::endl;
    container->set_sort_function(new SelectionSort());
    //container->set_sort_function(new BubbleSort());
    container->sort();
    container->print();
    
    return 0;
}
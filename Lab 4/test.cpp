#include <iostream>
#include "component.h"
#include "decorator.h"
#include "container.h"
#include "strategy.h"
// #include necessary classes

using namespace std;

int main() {
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

    VectorContainer* container = new VectorContainer();
    //ListContainer* container = new ListContainer();
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
    
    cout << "Container Before Sort: " << endl;
    container->print();

    cout << "Container After Sort: " << endl;
    container->set_sort_function(new SelectionSort());
    //container->set_sort_function(new BubbleSort());
    container->sort();
    container->print();
};
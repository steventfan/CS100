#include "visitor.h"

void PrintVisitor::rootNode() {
    return;
}

void PrintVisitor::sqrNode() {
    output.append("Squared ");
}

void PrintVisitor::multNode() {
    output.append("Multiply ");
}

void PrintVisitor::subNode() {
    output.append("Subtract ");
}

void PrintVisitor::addNode() {
    output.append("Add ");
}

void PrintVisitor::opNode(Op* op) {
    std::stringstream s;
    s << op->evaluate();
    output.append(s.str() );
    output.append(" ");
}

void PrintVisitor::execute() {
    std::cout << output << std::endl;
}
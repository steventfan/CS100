#include "iterator.h"

void OperatorIterator::first() {
    current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
    /*if(!is_done() && current_ptr == self_ptr->get_left() ) {
    current_ptr = self_ptr->get_right();
    }
    else {
        current_ptr = NULL;
    }*/
    if(current_ptr == self_ptr) {
        current_ptr = self_ptr->get_left();
    }
    else if(current_ptr == self_ptr->get_left()) {
        current_ptr = self_ptr->get_right();
    }
    else {
        current_ptr = NULL;
    }
}

bool OperatorIterator::is_done() {
    if(current_ptr == NULL) {
        return true;
    }
    
    return false;
}

Base* OperatorIterator::current() {
    return current_ptr;
}

void UnaryIterator::first() {
    current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
    //if(!is_done() ) {
        current_ptr = NULL;
    //}
}

bool UnaryIterator::is_done() {
    if(current_ptr == NULL) {
        return true;
    }
    
    return false;
}

Base* UnaryIterator::current() {
    return current_ptr;
}

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    while(iterators.size() > 0)
    {
        iterators.pop();
    }
    iterators.push(self_ptr -> create_iterator());
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
    Iterator *iter = iterators.top()->current()->create_iterator();
    iter->first();
    iterators.push(iter);
    while(!iterators.empty() && iterators.top()->is_done() ) {
        iterators.pop();
        if (!iterators.empty()) {
            iterators.top()->next();
        }
    }
}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
    if(iterators.empty() ) {
        return true;
    }
    
    return false;
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
    if(!iterators.empty() ) {
        return iterators.top()->current();
    }
    else {
        return NULL;
    }
}
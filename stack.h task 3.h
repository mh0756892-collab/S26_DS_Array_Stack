#pragma once
#ifndef stack_h
#define stack_h

#include "abstractarray.h"
#include <iostream>

using namespace std;

class stack : public abstract_array 

{
public:
    stack(int size) : abstract_array(size) {}

    void add(int v) override
    {
        if (!is_full()) 
        {
            values[++current_index] = v;
        }
        else 
        {
            cout << "stack overflow" << endl;
        }
    }

    bool get(int index, int& v) override 
    {
        if (!is_empty()) 
        {
            v = values[current_index--];
            return true;
        }
        return false;
    }
};

#endif

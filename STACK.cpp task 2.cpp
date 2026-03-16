#include <iostream>
#include "abstractarray.h"
#include "STACK.H"

using namespace std;

void push_data(abstract_array* s, int n)
{
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value to push: ";
        cin >> val;
        s->add(val);
    }
}

void pop_and_display(abstract_array* s)
{
    int val;
    cout << "popping from stack: ";
    while (s->get(0, val))
    {
        cout << val << " ";
    }
    cout << endl;
}

int main() 
{
    abstract_array* s = new stack(10);

    int n;
    cout << "how many values to push: ";
    cin >> n;

    push_data(s, n);
    pop_and_display(s);

    delete s;
    return 0;
}
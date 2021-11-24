#include <iostream>
#include <set>
#include "avl_tree.h"

int main()
{
    avl_tree<int> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.print();
    return 0;
}
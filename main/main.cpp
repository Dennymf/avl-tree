#include <iostream>
#include "avl_tree.h"

int main()
{
    avl_tree<int> t;
    std::cout << t.isEmpty() << '\n';
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.print();
    t.erase(4);
    t.print();
    t.erase(1);
    t.print();
    std::cout << t.isEmpty() << '\n';
    return 0;
}
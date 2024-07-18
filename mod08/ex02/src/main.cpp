#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "\n=== Testing MutantStack ===\n" << std::endl;

    MutantStack<int> mstack;
    std::cout << "Pushing 5 and 17 to the stack" << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    std::cout << "Popping top element" << std::endl;
    mstack.pop();

    std::cout << "Current size: " << mstack.size() << std::endl;

    std::cout << "Pushing 3, 5, 737, and 0 to the stack" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nIterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nCreating a standard stack from MutantStack" << std::endl;
    std::stack<int> s(mstack);

    std::cout << "\n=== Comparing with std::list ===\n" << std::endl;

    std::list<int> lst;
    std::cout << "Pushing same elements to std::list" << std::endl;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating through std::list:" << std::endl;
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++lst_it;
    --lst_it;
    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }

    std::cout << "\n=== Test Complete ===\n" << std::endl;

    return 0;
}

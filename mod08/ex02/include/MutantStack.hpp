#pragma once 

#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {

  public:
    // Constructors and Destructors
    MutantStack(): std::stack<T>() {};
    ~MutantStack() {};
    MutantStack(const MutantStack& other): std::stack<T>(other) {};
    MutantStack<T>& operator=(MutantStack<T>& other) {
      if (this != &other)
        std::stack<T>::operator=(other);
    };

    // Type definition for iterators
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // iterator accessors
    iterator begin() {return this->c.begin();};
    iterator end() {return this->c.end();};
    const_iterator cbegin() const {return this->begin();};
    const_iterator cend() const {return this->end();};
 
    reverse_iterator rbegin() {return this->rbegin();};
    reverse_iterator rend() {return this->rend();};
    const_reverse_iterator crbegin() const {return this->crbegin();};
    const_reverse_iterator crend() const {return this->crend();};
};

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
  public:
    // canonical
    FragTrap(void);
    ~FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(FragTrap& other);
    FragTrap& operator=(FragTrap& other);

    // other functions
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif

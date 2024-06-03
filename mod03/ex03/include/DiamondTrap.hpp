#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
  public:
    // canonical
    DiamondTrap(void);
    ~DiamondTrap(void);
    DiamondTrap(const std::string& name);
    DiamondTrap(DiamondTrap& other);
    DiamondTrap& operator=(DiamondTrap& other);

    // getters & setters

    // other functions
    void attack(const std::string& target);
    void whoAmI(void);

  private:
    std::string _name;
    
};

#endif

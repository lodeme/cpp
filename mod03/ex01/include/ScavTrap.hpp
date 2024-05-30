#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
  public:
    // canonical
    ScavTrap(void);
    ~ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(ScavTrap& other);
    ScavTrap& operator=(ScavTrap& other);

    // getters & setters
    bool          getGkMode(void);

    // other functions
    void attack(const std::string& target);
    void guardGate(void);

  private:
    std::string   _name;
    unsigned int  _hp;
    unsigned int  _energy;
    unsigned int  _attack;
    bool          _gkMode;
};

#endif

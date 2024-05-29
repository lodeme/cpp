#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
  public:
    // canonical
    ClapTrap(void);
    ~ClapTrap(void);
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);

    // other functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  private:
    std::string   _name;
    unsigned int  _hp;
    unsigned int  _energy;
    unsigned int  _attack;
};

#endif

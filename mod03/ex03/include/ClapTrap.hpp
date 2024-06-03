#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
  public:
    // canonical
    ClapTrap(void);
    ~ClapTrap(void);
    ClapTrap(const std::string& name);
    ClapTrap(ClapTrap& other);
    ClapTrap& operator=(ClapTrap& other);

    // getters & setters
    std::string& getName(void);
    unsigned int getHp(void);
    unsigned int getEnergy(void);
    unsigned int getAttack(void);
    void setEnergy(int);

    // other functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  protected:
    std::string   _name;
    unsigned int  _hp;
    unsigned int  _energy;
    unsigned int  _attack;
};

#endif

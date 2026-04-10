#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap( void );
	~ScavTrap( void );
	ScavTrap( const ScavTrap& other );
	ScavTrap& operator=( const ScavTrap& other );

	ScavTrap ( std::string name );
	void attack(const std::string& target);
	void guardGate();
};

#endif
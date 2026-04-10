#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string _name;

public:
	DiamondTrap( void );
	~DiamondTrap( void );
	DiamondTrap( const DiamondTrap& other );
	DiamondTrap& operator=( const DiamondTrap& other );

	DiamondTrap ( std::string name );
	void attack(const std::string& target);
	void whoAmI();
};

#endif
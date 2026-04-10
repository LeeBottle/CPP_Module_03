#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "----- 1. Constructor & Stats Test -----" << std::endl;
	{
		FragTrap frag("Fraggy");

		frag.attack("Dummy"); //30

		// ClapTrap에게 상속받은 기능 테스트
		frag.takeDamage(20); 
		frag.beRepaired(10);

		std::cout << "\n[Destroy]"<< std::endl;
	} 


	// 2. 고유 기능 (High Fives) 테스트
	std::cout << "\n----- 2. High Fives Request Test -----" << std::endl;
	{
		FragTrap happyBot("Happy");
		happyBot.highFivesGuys();

		std::cout << "\n[Destroy]"<< std::endl;
	}


	// 3.  FcagTrap의 ClapTrap, ScavTrap과 공존 테스트
	// 부모 클래스와 자식 클래스가 서로 다른 메시지와 스펙을 가지는지 비교
	std::cout << "\n----- 3. ClapTrap vs ScavTrap vs FragTrap-----" << std::endl;
	{
		std::cout << "[ClapTrap Object]" << std::endl;
		ClapTrap clap("Original_Clap");
		clap.attack("Target_A"); // 데미지 0, ClapTrap 메시지

		std::cout << "[ScavTrap Object]" << std::endl;
		ScavTrap scav("New_Scav");
		scav.attack("Target_B"); // 데미지 20, ScavTrap 메시지

		std::cout << "[FragTrap Object]" << std::endl;
		FragTrap frag("New_Frag");
		frag.attack("Target_C"); // 데미지 30, ClapTrap 메시지

		std::cout << "\n[Destroy]"<< std::endl;
	}


	// 4. Orthodox Canonical Form 테스트 (복사/대입)
	std::cout << "\n----- 4. Copy & Assignment Test -----" << std::endl;
	{
		FragTrap original("Original");
		original.takeDamage(50); // 100 -> 50

		std::cout << "\n[Copy Constructor]" << std::endl;
		FragTrap copy(original); 
		std::cout << "[Copy Assignment]" << std::endl;
		FragTrap assign("Assign");
		assign = original;

		std::cout << "-->Test: Original" << std::endl;
		original.beRepaired(5);
		std::cout << "-->Test: Copy" << std::endl;
		copy.beRepaired(5);
		std::cout << "-->Test: Assign" << std::endl;
		assign.beRepaired(5);

		std::cout << "\n[Destroy]"<< std::endl;
	} // 객체 3개 소멸

	return 0;
}
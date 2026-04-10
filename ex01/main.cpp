#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	// 스탯 확인: HP 100, Energy 50, Damage 20
	std::cout << "----- 1. Constructor Chaining & Stats Test -----" << std::endl;
	{
		ScavTrap scav("GateKeeper");

		// ScavTrap의 공격 데미지는 20
		scav.attack("Intruder"); 
		
		// ClapTrap에게 상속받은 기능 테스트
		scav.takeDamage(10); 
		scav.beRepaired(5);

		std::cout << "\n[Destroy]"<< std::endl;
	} 


	// 2. 고유 기능(guardGate) 테스트
	std::cout << "\n----- 2. Guard Gate Mode Test -----" << std::endl;
	{
		ScavTrap guard("Serena");
		guard.guardGate();
		guard.guardGate();
		guard.attack("SomeTarget");

		std::cout << "\n[Destroy]"<< std::endl;
	}


	// 3. ScavTrapdml ClapTrap과 공존 테스트
	// 부모 클래스와 자식 클래스가 서로 다른 메시지와 스펙을 가지는지 비교
	std::cout << "\n----- 3. ClapTrap vs ScavTrap -----" << std::endl;
	{
		std::cout << "[ClapTrap Object]" << std::endl;
		ClapTrap clap("Original_Clap");
		clap.attack("Target_A"); // 데미지 0, ClapTrap 메시지

		std::cout << "[ScavTrap Object]" << std::endl;
		ScavTrap scav("New_Scav");
		scav.attack("Target_B"); // 데미지 20, ScavTrap 메시지

		std::cout << "\n[Destroy]"<< std::endl;
	}


	// 4. Orthodox Canonical Form 테스트 (복사/대입)
	// 자식 클래스 복사 시 부모 클래스 부분도 잘 복사되는지 확인
	std::cout << "\n----- 4. Copy & Assignment Test -----" << std::endl;
	{
		ScavTrap original("Original");
		original.takeDamage(50); // 100 -> 50

		std::cout << "\n[Copy Constructor]" << std::endl;
		ScavTrap copy(original); 
		std::cout << "[Copy Assignment]" << std::endl;
		ScavTrap assign("Assign");
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
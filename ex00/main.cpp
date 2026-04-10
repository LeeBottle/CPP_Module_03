#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	// 1. 기본 생성 및 동작 테스트
	std::cout << "----- 1. Basic Actions Test -----" << std::endl;
	{
		ClapTrap a("ClapTrap");

		a.attack("Dummy");
		a.takeDamage(3);
		a.beRepaired(2);
		a.takeDamage(1);
	}

	// 2. 에너지 고갈 테스트
	std::cout << "----- 2. Energy Depletion Test -----" << std::endl;
	{
		ClapTrap b("Robot_B");
		for (int i = 0; i < 10; i++) {
			b.attack("Dummy"); 
		}
		// 에너지가 0일 때 공격 시도 (실패 메시지 출력 예상)
		b.attack("Dummy");
		
		// 에너지가 0일 때 수리 시도 (실패 메시지 출력 예상)
		b.beRepaired(5);
	}

	// 3. 체력 고갈(사망) 테스트
	std::cout << "----- 3. HP Depletion Test -----" << std::endl;
	{
		ClapTrap c("Robot_C");

		// 체력을 초과하는 데미지를 입힘 (HP: 10 -> 0)
		c.takeDamage(15);

		// 체력이 0일 때 공격 시도 (실패 메시지)
		c.attack("Enemy");
		
		// 체력이 0일 때 수리 시도 (실패 메시지)
		c.beRepaired(5);
	}

	//4. Orthodox Canonical Form 테스트
	std::cout << "\n----- 4. Copy & Assignment Test -----" << std::endl;
	{
		ClapTrap original("Original");
		original.takeDamage(5); //10 -> 5

		std::cout << "\n[Copy Constructor]" << std::endl;
		ClapTrap copy(original); 
		std::cout << "[Copy Assignment]" << std::endl;
		ClapTrap assign("Assign");
		assign = original;

		std::cout << "-->Test: Original" << std::endl;
		original.beRepaired(5);
		std::cout << "-->Test: Copy" << std::endl;
		copy.beRepaired(5);
		std::cout << "-->Test: Assign" << std::endl;
		assign.beRepaired(5);

	} // 여기서 3개의 객체가 소멸

	return 0;
}
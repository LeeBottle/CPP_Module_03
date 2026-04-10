#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    // 1. 생성자 호출 순서 확인 (가상 상속 테스트)
    std::cout << "----- 1. Constructor Chain Test (The Diamond) -----" << std::endl;
    {
        DiamondTrap dia("Monster");

        // ClapTrap에게 상속받은 기능 테스트
        dia.takeDamage(10); 
        dia.beRepaired(5);

		std::cout << "\n[Destroy]"<< std::endl;
    }


    // 2. 기능 및 정체성 테스트 (whoAmI, attack)
    std::cout << "\n----- 2. Functionality & Identity Test -----" << std::endl;
    {
        DiamondTrap dia("DiaBot");

        std::cout << "\n[Inherence Abilities]" << std::endl;
        dia.whoAmI();

        std::cout << "\n[Special Abilities]" << std::endl;
        dia.guardGate();      // ScavTrap의 능력
        dia.highFivesGuys();  // FragTrap의 능력

		std::cout << "\n[Destroy]"<< std::endl;
    }

	// 3.DiamonTrap의 ClapTrap, ScavTrap, FcagTrap과 공존 테스트
    // 부모 클래스와 자식 클래스가 서로 다른 메시지와 스펙을 가지는지 비교
    std::cout << "\n----- 3. ClapTrap vs ScavTrap -----" << std::endl;
    {
        std::cout << "[ClapTrap Object]" << std::endl;
        ClapTrap clap("Original_Clap");
        clap.attack("Target_A"); // 데미지 0, ClapTrap 메시지

        std::cout << "\n[ScavTrap Object]" << std::endl;
        ScavTrap scav("New_Scav");
        scav.attack("Target_B"); // 데미지 20, ScavTrap 메시지

        std::cout << "\n[FragTrap Object]" << std::endl;
        FragTrap frag("New_Frag");
        frag.attack("Target_C"); // 데미지 30, ClapTrap 메시지

        std::cout << "\n[DiamonTrap Object]" << std::endl;
        DiamondTrap dia("New_Dia"); // name (parameter of the constructor + "_clap_name" suffix)
        dia.attack("Target_D"); // FragTrao 데미지 30, ScavTrap 메시지

		std::cout << "\n[Destroy]"<< std::endl;
    }


	// 4. Orthodox Canonical Form 테스트 (복사/대입)
    std::cout << "\n----- 4. Copy & Assignment Test -----" << std::endl;
    {
		DiamondTrap original("Original");
        original.takeDamage(50); // 100 -> 50

		std::cout << "\n[Copy Constructor]" << std::endl;
        DiamondTrap copy(original); 
        std::cout << "[Copy Assignment]" << std::endl;
        DiamondTrap assign("Assign");
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
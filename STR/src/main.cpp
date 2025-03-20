#include <iostream>
#include "entity.hpp"

int main() {
    int refValue = 10;
    entity obj(5, refValue);
    std::cout << "x = " << obj.x << std::endl; 
    std::cout << "refaddress = " << &obj.ref << std::endl; 
    
    
    
    
    
    // 等待用户按下回车后退出
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}

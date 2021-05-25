#pragma once

#include "T01排列小球.h"

void T01Test()
{
    std::cout << ">> 输入 2 1 1 预期 6" << std::endl;
    std::cout << "<< 输出 ";
    T01Main::Test(2, 1, 1);

    std::cout << std::endl;

    std::cout << ">> 输入 3 2 1 预期 10" << std::endl;
    std::cout << "<< 输出 ";
    T01Main::Test(3, 2, 1);

    std::cout << std::endl;

    std::cout << ">> 输入 7 8 9 预期 1718068" << std::endl;
    std::cout << "<< 输出 ";
    T01Main::Test(7, 8, 9);

    std::cout << std::endl;

    std::cout << ">> 输入 10 8 9 预期 12748518" << std::endl;
    std::cout << "<< 输出 ";
    T01Main::Test(10, 8, 9);
}
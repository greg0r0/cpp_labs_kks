#include <iostream>
#include "../includes/substring.hpp"
#include <string>
int main()
{
    std::string a = "aaaaaaaaaa";
    std::string p = "#a";
    auto i = lab6::alg_KMP(a,p);
    for (auto c : i)
    {
        std::cout << c << std::endl;
    }
    return 0;
}
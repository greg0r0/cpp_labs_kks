#include <iostream>
#include "../includes/substring.hpp"
#include <string>
int main()
{
    std::cout << "test" << std::endl;
    std::string a = "i'm, simple little text";
    std::string p = "simple";
    auto i = lab6::alg_rabin_karp(a,p);
    for (auto c : i)
    {
        std::cout << c << std::endl;
    }
    return 0;
}
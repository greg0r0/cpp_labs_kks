#include <iostream>
#include "../includes/substring.hpp"
#include <string>
#include <algorithm>


int main()
{
    // std::string a = "abbcabaabbcaba";
    // std::string p = "abbcaba";
    std::string a = "i'm simple string";
    std::string p = "simple";
    auto i = lab6::alg_finite_machine(a,p);
    for (auto c : i)
    {
        std::cout << c << std::endl;
    }


    return 0;
}
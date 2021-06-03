#ifndef __SUBSTR_LAB6__
#define __SUBSTR_LAB6__

#include <vector>
#include <string>
namespace lab6
{

    std::vector<int>      alg_boyer_mur(std::string orig, std::string _template);
    std::vector<int>     alg_rabin_karp(std::string orig, std::string _template); // ><>
    std::vector<int>            alg_KMP(std::string orig, std::string _template); //Кнута-Морриса-Пратта
    std::vector<int> alg_finite_machine(std::string orig, std::string _template);

}


#endif
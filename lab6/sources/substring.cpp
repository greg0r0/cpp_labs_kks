#include "../includes/substring.hpp"
#include <vector>
#include <map>
#include <set>
#include <array>
#include <string>
#include <algorithm>
#include <memory>


#ifdef DEBUG
    #include <iostream>
#endif

std::vector<int> lab6::alg_boyer_mur(std::string orig, std::string _template)
{
    std::vector<int> result;
    if (_template.size() > orig.size())
    {
        return result;
    }

    //stage 1: craft stop table
    int st[256]; 
    std::fill(st, st+256, -1);
    for (int i = 0; i < _template.size()-1; i++)
    {
        st[ (unsigned char)(_template[i]) ] = i; 
    }

    #ifdef DEBUG
    std::cout << "[!] DEBUG::alg_boyer_mur::st = [ "; 
    for (auto i : st) { std::cout << i << ", "; }
    std::cout << "];" << std::endl;
    #endif

    //stage 2: craft suffix table
    //std::vector<std::string> suffixes;
    std::vector< std::pair<std::string, int> > suffixes;
    for (auto it = _template.rbegin(); it != _template.rend(); it++)
    {
        std::string suf;
        std::reverse_copy(_template.rbegin(), it, std::back_inserter(suf));
        
        int shift = 0;
        std::string tc = _template;
        
        for (;;)
        {
            if (std::string(tc.end() - suf.size()-1, tc.end()-1) == suf)
            {
                shift++; //because we reverse-scan from -1 index
                break;
            }
            if (shift >= _template.size())
            {
                shift = _template.size();
                break;
            }
            std::shift_right(tc.begin(), tc.end(), 1);
            shift++;
        }

        suffixes.emplace_back(  std::pair<std::string, int>(suf, shift));

    }
    suffixes.emplace_back(  std::pair<std::string, int>(_template, _template.size()));
    #ifdef DEBUG
    std::cout << "[!] DEBUG::alg_boyer_mur::suffixes = [ "; 
    for (auto [key, value] : suffixes) { std::cout << "(" << key << ", " << value << " ), "; }
    std::cout << "];" << std::endl;
    #endif
    //stage 3 core
    for (int i = 0; i < orig.size() - _template.size() + 1;)
    {
        int j = _template.size() - 1;
        while (j >= 0 && _template[j]==orig[i+j])
        {
            #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_boyer_mur::_template[j]=" << _template[j] << " DEBUG::alg_boyer_mur::orig[i+j]=" << orig[i+j] << " j=" << j-1 /*because we in while already*/ <<  std::endl;
            #endif
            j--;
        }
        int delta_stop, delta_suff;
        if (j==-1)
        {
            result.push_back(i);
            delta_stop = 1;
            delta_suff = 0;
            #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_boyer_mur::FOUND AT " << i << std::endl;
            #endif
        } 
        else 
        {
            delta_stop = j - st[ orig[i+j] ];
            delta_suff = suffixes[_template.size() - j - 1].second;
        }

        #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_boyer_mur::stop=" <<delta_stop << " DEBUG::alg_boyer_mur::suffix=" << delta_suff << std::endl;
                std::cout << "[!] DEBUG::alg_boyer_mur::INDEX_WAS_AT " << i <<' ' <<std::string(orig.begin()+i, orig.end()) << std::endl;
        #endif
        i+=std::max(delta_stop, delta_suff);
        #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_boyer_mur::INDEX_NOW_AT " << i <<' ' <<std::string(orig.begin()+i, orig.end()) << std::endl;
        #endif
    }
    return result;
}

std::vector<int> lab6::alg_rabin_karp(std::string orig, std::string _template) // ><>
{
    int standart_pime_modulo = 0x5c6f; //23663 
    std::vector<int> result;

    if (orig.size() < _template.size())
    {
        return result;
    }

    int seed = 1;
    int alph_size = 256; // for ASCII
    for (int i=0; i < _template.size()-1; i++)
        seed = (seed*alph_size) % standart_pime_modulo;
    #ifdef DEBUG
        std::cout << "[!] DEBUG::alg_rabin_karp::standart_pime_modulo=" << std::hex << standart_pime_modulo << std::endl;
        std::cout << "[!] DEBUG::alg_rabin_karp::seed=" << std::hex << seed << std::endl;
    #endif
    // auto hash = [seed](std::string str, unsigned int _modulo, bool forOldHash, unsigned int oldHash) -> unsigned int 
    // {
    //     if (!forOldHash)
    //     {
    //         //new computation
    //     }
    //     else
    //     {
    //         //for old computation
    //     }
    //     return seed+123;
    // };  
    //compute base hashes
    int hash = 0;
    int hashn = 0; // hash new

    for (int i = 0; i < _template.size(); i++)
    {
        hash  = (alph_size*hash  + _template[i]) % standart_pime_modulo;
        hashn = (alph_size*hashn + orig[i]) % standart_pime_modulo;
    }

    #ifdef DEBUG
        std::cout << "[!] DEBUG::alg_rabin_karp::hash="  << std::hex << hash << std::endl;
        std::cout << "[!] DEBUG::alg_rabin_karp::hashn=" << std::hex << hashn << std::endl;
    #endif

    for (int s = 0; s < orig.size() - _template.size() + 1; s++)
    {
        #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_rabin_karp::rehash_str="  << std::string(orig.begin()+s, orig.begin()+s+_template.size()) << std::endl;
                std::cout << "[!] DEBUG::alg_rabin_karp::pattern___="  << _template << std::endl;
                std::cout << "[!] DEBUG::alg_rabin_karp::rehash="  << std::hex << hashn << std::endl;
        #endif
        if (hash == hashn)
        {
            #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_rabin_karp::FOUND_HASHES" << std::endl;
            #endif
            if ( _template == std::string(orig.begin()+s, orig.begin()+s+_template.size()) )
            {
                #ifdef DEBUG
                    std::cout << "[!] DEBUG::alg_rabin_karp::FOUND_AT=" << s << std::endl;
                #endif
                result.push_back(s);
            }
        }
        if ( s < orig.size() - _template.size() + 1)
        {
            #ifdef DEBUG
                std::cout << "\n[!] DEBUG::alg_rabin_karp::Rehashing..." << std::endl;
                std::cout << "[!] DEBUG::alg_rabin_karp::orig[s]=" << orig[s] << std::endl;
                std::cout << "[!] DEBUG::alg_rabin_karp::orig[s+_template.size()]=" << orig[s+_template.size()] << std::endl;
            #endif
            //rehash
            hashn = (alph_size * ( hashn - seed*orig[s]) + orig[s+_template.size()]) % standart_pime_modulo;
            if (hashn < 0) { hashn += standart_pime_modulo; }
        }
    }
    return result;
}
std::vector<int> lab6::alg_KMP(std::string orig, std::string _template) //Кнута-Морриса-Пратта
{
    std::vector<int> result;
    int prefix_table[_template.size()]{0};
    //generate prefix table
    int k = 0;
    for (int i = 1; i < _template.size(); i++)
    {
        while (k > 0 && _template[k] != _template[i])
        {
            k = prefix_table[k-1];
        }

        if (_template[k] == _template[i])
            k++;
        
        prefix_table[i] = k;
    }

    #ifdef DEBUG
        std::cout << "[!] DEBUG::alg_boyer_mur::prefix_table = [ "; 
        for (auto i : prefix_table) { std::cout << i << ", "; }
        std::cout << "];" << std::endl;
    #endif
    //core
    k = 0;
    for (int i = 0; i < orig.size(); i++)
    {
        while ((k > 0) && (_template[k] != orig[i]))
            k = prefix_table[k-1];
        if (_template[k] == orig[i])
            k++;

        if (k == _template.size())
        {
            #ifdef DEBUG
                std::cout << "[!] DEBUG::alg_rabin_karp::FOUND_AT=" << i - _template.size() + 1 << std::endl;
            #endif
            result.push_back(i - _template.size() + 1);
            k = prefix_table[k-1];
        }
    }

    return result;
}

int get_suffix_data(std::string p, std::string pc)
{
    #ifdef DEBUG
        std::cout << "      [!] DEBUG::finite_machine::p=" << p << std::endl;
        std::cout << "      [!] DEBUG::finite_machine::pc=" << pc << std::endl;
    #endif

    int max_result = 0;

    for (int i = 1; i <= pc.size(); i++)
    {
        int result = 0;
        std::string suf;
        std::reverse_copy(pc.begin(), pc.begin()+i, std::back_inserter(suf));

        std::string p_copy;
        std::reverse_copy(p.begin(), p.end(), std::back_inserter(p_copy));

        for (int j = 0; j < suf.size(); j++)
        {
            if (suf[j] == p_copy[j])
            {
                result++;
            } 
            else
            {
                result = 0;
                break;
            }
        }

        if (result > max_result)
            max_result = result;
    }

    return max_result;
}

std::vector<int> lab6::alg_finite_machine(std::string orig, std::string _template)
{
    std::vector<int> result;
    std::set<char> chrs;
    std::map< char, std::vector<int> > FSM;

    for (auto i : orig) { chrs.insert(i); }
    for (auto i : _template) { chrs.insert(i); }

    for (auto sym : chrs)
    {
        FSM[sym] = std::vector<int>(_template.size()+1, 0);
       
    }

    #ifdef DEBUG
        std::cout << "[!] DEBUG::finite_machine::charset_template= [";
        for (auto a: chrs)
        std::cout << a << ", ";
        std::cout << "]" << std::endl;
    #endif

    // stage 1 : generate finite machine table
    int index = 0;
    for ( auto it = _template.begin()+1; it <= _template.end()+1; it++)
    {
        std::string pref(_template.begin(), it);
        std::string sub_pref(_template.begin(), it-1);
        
        #ifdef DEBUG
                std::cout << "[!] DEBUG::finite_machine::pref="<<pref << std::endl;
        #endif

        for (auto i:chrs)
        {
            auto get_data = get_suffix_data(sub_pref+i, pref);

            #ifdef DEBUG
                std::cout << "   [!] DEBUG::finite_machine::sub_pref="<< (sub_pref+i) << " data="<<get_data << std::endl;
            #endif

            FSM[i][index] = get_data;
        }

        index++;

    }
    #ifdef DEBUG
    std::cout << "[!] DEBUG::finite_machine::FSM"<<std::endl;
    for (auto [key, value] : FSM)
    {
        std::cout << key << " "<< std::endl;
        for (int i = 0; i <= _template.size(); i++)
            std::cout << value[i] << " ";
        std::cout << std::endl;
    }
    #endif

    //core

    int state = 0;

    for (int i = 0; i < orig.size(); i++)
    {
        state = FSM[ orig[i] ][state];
        #ifdef DEBUG
            std::cout << "[!] DEBUG::finite_machine::NEXT_STATE "<< state << std::endl;
        #endif
        if (state == _template.size())
        {
            #ifdef DEBUG
                std::cout << "[!] DEBUG::finite_machine::FOUND_AT "<< (i - _template.size() + 1) << std::endl;
            #endif
            result.push_back(i - _template.size() + 1);
        }
    }

    // for (auto c : chrs)
    // {
    //     #ifdef DEBUG
    //         std::cout << "[!] DEBUG::finite_machine::delete at "<<  FSM[c] << std::endl;
    //     #endif
    //     delete FSM[c];
    // }

    return result;
}
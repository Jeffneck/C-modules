#include "Serialization.hpp"
#include <iostream>
#include "Data.hpp"


int main(int ac, char **av)
{
        if (ac == 2)
        {
                Data data(av[1]);
                std::cout << "BEFORE --" << std::endl;
                std::cout << "Data str = " << data << std::endl;

                uintptr_t ptr = Serialization::serialize(&data);
                std::cout << "---\n\nDURING -- uintptr_t obtained via serialization :" << ptr  << std::endl;

                data = *Serialization::deserialize(ptr);
                std::cout << std::endl;
                std::cout << "---\n\nAFTER --" << std::endl;
                std::cout << "Data str = " << data << std::endl;
        }
        else{

                std::cout << "Error: usage: ./serialization <string> " << std::endl;
        }


}

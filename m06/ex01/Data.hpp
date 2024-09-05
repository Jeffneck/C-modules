#ifndef DATE_HPP
#define DATE_HPP
#include <string>
#include <iostream>


class Data 
{
    public :
        Data(const std::string str);
        Data(const Data& toCopy);
        ~Data();
        Data& operator=(const Data& toAssign);

        const std::string getStr(void) const; 
        
        private :
        std::string _str;
};

std::ostream 	&operator<<( std::ostream &flux, const Data &Data );

#endif
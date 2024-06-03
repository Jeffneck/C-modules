#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Form 
{
    private :
        const std::string   _name;
        bool                _is_signed;
        const unsigned int  _grade_sign;
        const unsigned int  _grade_exec;

    public :
        Form(const std::string name, const unsigned int _grade_sign, const unsigned int _grade_exec);
        Form(Form& to_copy);
        virtual ~Form();
        
        
        const std::string       getName()       const;
        bool                    getSigned()     const;
        const unsigned int      getSignGrade()  const;
        const unsigned int      getExecGrade()  const;


};







#endif
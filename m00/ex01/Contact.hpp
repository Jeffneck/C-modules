#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
    {
        public :
            Contact();
            void    addContact();
            void    displayContact(int index) const;
            void    displayContactGlobal(int index) const;
        
        private :
            std::string firstName;
            std::string lastName;
            std::string nickname;
            std::string phoneNumber;
            std::string darkestSecret;
    };

#endif
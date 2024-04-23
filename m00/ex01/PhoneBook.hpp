#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
    class PhoneBook
    {
        public :
        PhoneBook();
        void    add();
        void    search() const;
        
        private :
        Contact contactList[8];
        int nbContacts;
        void displayHeaders() const;
    };

#endif
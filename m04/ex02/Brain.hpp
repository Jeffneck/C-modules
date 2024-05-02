#pragma once

#include <string>

class Brain
{
    public : 
    Brain();
    Brain(Brain const &to_copy);
    ~Brain();
    Brain &operator=(Brain const& other);

    void setIdea(const unsigned int index, const std::string &nIdea);
    void setIdeas(const std::string (&nIdeas)[100]);
    std::string const* getIdeas() const;

    private :
    std::string _ideas[100];
};
#ifndef HARL_HPP

# define HARL_HPP

# define RESET "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

# include <iostream>

class	Harl;
typedef struct s_levelMap
{
	std::string level;
	//on donne l'adresse d' une methode de la classe Harl
	void (Harl::*func)();
}   t_levelMap;

class	Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
        t_levelMap _levelMap[4];

};

#endif
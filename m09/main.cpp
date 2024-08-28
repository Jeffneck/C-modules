#include <iostream>
#include <ctime> //std::tm timestamp ?
#include <sstream>
#include <fstream>
#include <exception>
// #include <iomanip>

void	checkNbArgs(int ac)
{
	if(ac != 2)
		throw(std::runtime_error("Error: ./btc need 1 argument Usage: ./btc <input_file>"));
}

std::ifstream	extractFile(char *filename)
{
	std::ifstream filestream(filename);
	if(!filestream)
		throw(std::runtime_error("Error: <input_file> can't be opened"));
	return(filestream);
}



int main(int ac, char **av)
{
	try{
		checkNbArgs(ac);
		std::ifstream file = extractFile(av[1]);
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	std::string
	while()


}


#include <iostream>
#include <ctime> //std::tm timestamp ?
#include <sstream> //stringstream (gestion de la date)
#include <fstream> //filestream (gestion des fichiers)
#include <map> //std::map
#include <algorithm> //utile ?
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

std::map	mapExchangeRate(std::map &ExR, std::ifstream &inputFile)
{


}


int main(int ac, char **av)
{
	try{
		checkNbArgs(ac);
		std::ifstream inputFile = extractFile(av[1]);
		std::ifstream dataFile = extractFile("data.csv");
		std::map<std::tm, float> ExR = mapExchangeRate(dataFile);
		displayExchangeRate(ExR, inputFile);
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	std::string line
	while()


}


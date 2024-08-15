#include "Serialization.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string str = av[1];
		Data data = {str, str.length()};
		uintptr_t ptr = Serialization::serialize(&data);
		data = Serialization::deserialize(ptr);
		std::cout << "After deserialization" << std::endl; ///
	}


}
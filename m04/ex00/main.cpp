#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "\n" << std::endl;
		delete(meta);
		delete(j);
		delete(i);
	}	
    std::cout << "\n !--WRONG EXAMPLES--!" << std::endl;
	{
		const WrongAnimal* i = new WrongCat();
		const WrongAnimal* meta = new WrongAnimal();

		std::cout << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n" << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete(meta);
		delete(i);
	}
	return (0);
}
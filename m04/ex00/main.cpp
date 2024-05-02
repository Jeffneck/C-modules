#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
    {
    //construct metaclass
    const Animal* meta = new Animal();
    //construct subclasses
	const Animal* dogo = new Dog();
    const Animal* gato = new Cat();
    std::cout << dogo->getType() << " " << std::endl;
    std::cout << gato->getType() << " " << std::endl;
    gato->makeSound();
    dogo->makeSound();
    meta->makeSound();
    std::cout << "\n" << std::endl;
		delete(meta);
		delete(dogo);
		delete(gato);
	}	
    std::cout << "\n !--WRONG EXAMPLES--!" << std::endl;
	{
		const WrongAnimal* bad_gato = new WrongCat();
		const WrongAnimal* meta = new WrongAnimal();

		std::cout << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << bad_gato->getType() << " " << std::endl;
		std::cout << "\n" << std::endl;
		bad_gato->makeSound(); 
		meta->makeSound();
		delete(meta);
		delete(bad_gato);
	}
	return (0);
}
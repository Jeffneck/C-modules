#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{
	std::cout << "GIVEN MAIN\n" << std::endl;
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << "\n" << std::endl;
		delete j;
		delete i;
	}
	std::cout << "\nCREATE OBJ IN TAB\n" << std::endl;
	{
		AAnimal *tab[4]; //meta tab can contain Cat & dogs
		for (int i = 0; i < 4; i++)
		{
			if (i / 2 == 0)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
		}
		std::cout << "\nDELETE OBJ IN TAB\n" << std::endl;
		for (int i = 0; i < 4; i++)
			delete tab[i];
	}
	std::cout << "\nDEEP COPY A DOG\n" << std::endl;
	{
		Dog	dogo;
		dogo.setIdea(0, "i need to eat, wouf");
		dogo.setIdea(1, "i need to drink, wouf");
		dogo.setIdea(2, "i need to pee, wouf");
		dogo.setIdea(3, "Master, can we go out , pleeeease, wouf");
		// const Brain *dogoBrain = dogo.getBrain();
		Dog	copy(dogo);
		std::cout << "\n" << std::endl;
		std::cout << "Real Dog brain Ptr : " << dogo.getBrain() << std::endl;
		dogo.printIdeas();
		std::cout << std::endl;
		std::cout << "Copied Dog brain Ptr : " << copy.getBrain() << std::endl;
		copy.printIdeas();
		std::cout << "\n" << std::endl;
	}
	return (0);
}

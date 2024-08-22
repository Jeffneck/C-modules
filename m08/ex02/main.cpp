#include"MutantStack.hpp"
#include <list>
int main()
{
	
    std::cout << "\n-------- 1: Resultat avec un objet MutantStack ------" << std::endl;
	
	MutantStack<int>
	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);


    std::cout << "\n\n-------- 2: Resultat avec un objet list ------" << std::endl;

	std::list<int> exList;
	exList.push_back(5);
	exList.push_back(17);
	std::cout << exList.back() << std::endl;
	exList.pop_back();
	std::cout << exList.size() << std::endl;
	exList.push_back(3);
	exList.push_back(5);
	exList.push_back(737);
	//[...]
	exList.push_back(0);
	std::list<int>::iterator itL = exList.begin();
	std::list<int>::iterator iteL = exList.end();
	++itL;
	--itL;
	while (itL != iteL)
	{
	std::cout << *itL << std::endl;
	++itL;
	}
	// std::stack<int> st(exList);
	return 0;
}
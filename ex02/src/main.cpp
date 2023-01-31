#include <iostream>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base	*generate( void )
{
	srand(time(NULL));
	int	i = rand() % 3;

	//std::cout << i << std::endl;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			break;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Type of base pointer is A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Type of base is pointer B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Type of base is pointer C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "Type of base reference is A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "Type of base reference is B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "Type of base reference is C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}		
}

int	main( void )
{
	Base *p = generate();

	identify(p);
	identify(*p);

	return (0);
}
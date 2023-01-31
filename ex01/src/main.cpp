#include <iostream>
#include <Data.hpp>

Data	*deserialize(uintptr_t	raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main( int argc, char **argv )
{
	(void) argc;
	(void) argv;
	Data	*data = new Data("HOLA", 42);

	std::cout << "Data pointer data has a string with value: " << data->getS() << ", and a int with value: " << data->getI() << std::endl;

	std::cout << "Calling serialize function..." << std::endl;
	uintptr_t	u = data->serialize(data);
	
	std::cout << "Calling deserialize function..." << std::endl;
	Data	*newData = deserialize(u);

	std::cout << "Data pointer newData has a string with value: " << newData->getS() << ", and a int with value: " << newData->getI() << std::endl;
}
#include <Convert.hpp>

int	main( int argc, char **argv )
{
	if	(argc != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (0);
	}
	std::string	toConvert = argv[1];
	Convert	c(toConvert);

	c.convert();
}
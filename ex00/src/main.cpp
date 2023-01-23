#include <iostream>
#include <string>

bool	isSpecialCase(std::string toConvert)
{
	std::string	cases[6] = {"nanf", "+inff", "-inff", "nan", "+inf", "-inf"};
	int	i = 0;

	while (i < 6 && toConvert != cases[i])
		i++;
	if (i < 6)
		return (true);
	return (false);
}

bool	isSpecialCaseDouble(std::string toConvert)
{
	std::string	cases[2] = {"+inf", "-inf"};
	int	i = 0;

	while (i < 2 && toConvert != cases[i])
		i++;
	if (i < 2)
		return (false);
	return (true);	
}

int	main( int argc, char **argv )
{
	(void) argc;

	if	(argc != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (0);
	}
	std::string	toConvert = argv[1];
	if (toConvert[0] == 39 && toConvert[toConvert.length() - 1] == 39)
	{
		if (toConvert.length() == 3)
			std::cout << "Is a CHAR" << std::endl;
		else
			std::cout << "Error: Wrong argument" << std::endl;
	}
	else if (toConvert.find_first_of('.') != std::string::npos || isSpecialCase(toConvert))
	{
		if (toConvert.find_first_of('.') != toConvert.find_last_of('.'))
			std::cout << "Error: Wrong argument" << std::endl;
		else
		{
			if (toConvert[toConvert.length() -1] == 'f' && isSpecialCaseDouble(toConvert))
				std::cout << "Is a FLOAT" << std::endl;
			else
				std::cout << "Is a DOUBLE" << std::endl;
		}
	}
	else
	{
		std::string::size_type	sz;
		int	n;
		try
		{
			n = std::stoi(toConvert, &sz);
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: Wrong argument (Too long INT)" << std::endl;
			return (0);
		}
		if (toConvert.length() == sz)
			std::cout << "Is a INT" << std::endl;
		else
			std::cout << "Error: Wrong argument" << std::endl;
	}
}
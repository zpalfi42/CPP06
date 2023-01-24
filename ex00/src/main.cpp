#include <iostream>
#include <string>
#include <limits.h>

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

int to_int(char const *s)
{
    if ( s == NULL || *s == '\0' )
       throw std::invalid_argument("null or empty string argument");
    bool negate = (s[0] == '-');
    if ( *s == '+' || *s == '-' ) 
        ++s;
    if ( *s == '\0')
       throw std::invalid_argument("sign character only.");
    long long int result = 0;
    while(*s)
    {
		std::cout << result << std::endl;
         if ( *s < '0' || *s > '9' || result > 2147483647 || result < -2147483648)
           throw std::invalid_argument("invalid input string");
         result = result * 10  - (*s - '0');  //assume negative number
		 if (result > 2147483647 || result < -2147483648)
		 	throw std::invalid_argument("invalid argument");
         ++s;
    }
    return negate ? result : -result; //-result is positive!
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
		int	n;
		try
		{
			n = to_int(toConvert.c_str());
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: Wrong argument" << std::endl;
			return (0);
		}
		std::cout << "Is a INT " << n << std::endl;
	}
}
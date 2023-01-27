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

bool	isSpecialCaseFloat(std::string toConvert)
{
	std::string	cases[3] = {"+inff", "-inff", "nanf"};
	int	i = 0;

	while (i < 3 && toConvert != cases[i])
		i++;
	if (i < 3)
		return (true);
	return (false);	
}

bool	isSpecialCaseDouble(std::string toConvert)
{
	std::string	cases[3] = {"+inf", "-inf", "nan"};
	int	i = 0;

	while (i < 3 && toConvert != cases[i])
		i++;
	if (i < 3)
		return (true);
	return (false);	
}

bool	isNum(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

bool	isFloatOrDouble(std::string s, int mode)
{
	int	dot = 0;
	int	f = 0;

	if (mode == 0 && isSpecialCaseFloat(s))
		return (true);
	else if (mode == 1 && isSpecialCaseDouble(s))
		return (true);
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			continue ;
		else if (s.c_str()[i] == '.')
		{
			if (++dot > 1)
				return (false);
		}
		else if (mode == 0 && s.c_str()[i] == 'f')
		{
			if (++f > 1 || i < (int)s.length() - 1)
				return (false);
		}
		else if (!isNum(s.c_str()[i]))
			return (false);
	}
	if (mode == 0 && (s.find_first_of('.') == s.find_first_of('f') - 1 || f == 0))
		return (false);
	else if (mode == 1 && s.find_first_of('.') == s.length() - 1)
		return (false);
	return (true);
}

int		to_int(char const *s)
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
         if ( *s < '0' || *s > '9' )
           throw std::invalid_argument("invalid input string");
         result = result * 10  - (*s - '0');  //assume negative number
		 if (result > 2147483647 || result < -2147483648)
		 	throw std::invalid_argument("invalid argument");
         ++s;
    }
    return negate ? result : -result; //-result is positive!
}

int		tryChar(std::string toConvert)
{
	if (toConvert.length() == 3)
		std::cout << "Is a CHAR" << std::endl;
	else
		std::cout << "Error: Wrong argument" << std::endl;
}

int		tryFloatOrDouble(std::string toConvert)
{
	if (toConvert.find_first_of('.') != toConvert.find_last_of('.'))
		std::cout << "Error: Wrong argument" << std::endl;
	else
	{
		if (isFloatOrDouble(toConvert, 0))
			std::cout << "Is a FLOAT" << std::endl;
		else if (isFloatOrDouble(toConvert, 1))
			std::cout << "Is a DOUBLE" << std::endl;
		else
		{
			std::cout << "Error: Wrong argument" << std::endl;
			return (0);
		}
	}
}

int		tryInt(std::string toConvert)
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
		tryChar(toConvert);
	else if (toConvert.find_first_of('.') != std::string::npos || isSpecialCase(toConvert))
		tryFloatOrDouble(toConvert);
	else
		tryInt(toConvert);
}
#ifndef	DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
private:
	std::string	_s;
	int			_i;
public:
	Data( void );
	Data( Data &d );
	Data( std::string s, int i );

	~Data( void );

	Data		&operator=( Data &d );

	uintptr_t	serialize( Data *ptr );

	std::string	getS();
	int			getI();
};

# endif


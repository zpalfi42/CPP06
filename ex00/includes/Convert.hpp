#ifndef	CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class Convert
{
private:
	std::string	const	_s;
	int					_int;
	char				_char;
	float				_float;
	double				_double;
	bool				_valid;
	bool				_special;
	bool				_onlyDouble;
	bool				_noChar;
public:
	Convert( void );
	Convert( Convert &c );
	Convert( std::string s );

	Convert	&operator=( Convert &c );
	~Convert();

	bool	isNum( char c );
	bool	isSpecialCase( void );
	bool	isFloatOrDouble( int mode );
	bool	isSpecialCaseFloat( void );
	bool	isSpecialCaseDouble( void );

	bool	charDisplayable( void );

	int		toInt( char const *s );
	float	toFloat( char const *s );
	double	toDouble( char const *s );

	int		tryInt();
	int		tryChar();
	int		tryFloatOrDouble();

	void	convert();
};

#endif
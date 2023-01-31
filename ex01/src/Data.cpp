#include <Data.hpp>

Data::Data( void ): _s("Undefined"), _i(0)
{

}

Data::Data( Data &d ): _s(d._s), _i(d._i)
{

}

Data::Data( std::string s, int i ): _s(s), _i(i)
{

}

Data	&Data::operator=( Data &d )
{
	if (this != &d)
	{
		this->_s = d._s;
		this->_i = d._i;
	}
	return (*this);
}


Data::~Data( void )
{

}

uintptr_t	Data::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

std::string	Data::getS( void )
{
	return (this->_s);
}

int	Data::getI( void )
{
	return (this->_i);
}
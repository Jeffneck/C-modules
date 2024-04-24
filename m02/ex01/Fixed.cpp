#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_fixed_nb = 0;
}

Fixed::Fixed(int const nb_int)
{
	std::cout << "Int constructor called" << std::endl;
	m_fixed_nb = nb_int << m_fact_bits;
}

Fixed::Fixed(float const nb_float)
{
	std::cout << "Float constructor called" << std::endl;
	m_fixed_nb =  (int)roundf(nb_float * (1 << m_fact_bits));
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}






Fixed& Fixed::operator=(const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &other)
		return (*this);
	m_fixed_nb = other.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}




int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(this->m_fixed_nb);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	m_fixed_nb = raw;
}

int Fixed::toInt(void)	const
{
	//retourne mon nb a virgule fixe en int
	return (m_fixed_nb >> 8);
}

float Fixed::toFloat(void)	const
{
	//transforme mon nb a virgule fixe en float
	return ((float) m_fixed_nb / (1 << m_fact_bits));
}
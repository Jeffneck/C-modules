#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_fixed_nb = 0;
}
Fixed::Fixed(const Fixed &to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    m_fixed_nb = to_copy.getRawBits();
}
Fixed::Fixed& operator=(const Fixed& other )
{
	if(this == &other)
		return (*this);
	m_fixed_nb = other.getRawBits();
	return (*this);
}

Fixed::int getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->m_fixed_nb);
}
Fixed::void setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	m_fixed_nb = raw;
}
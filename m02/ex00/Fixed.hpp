#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
 
class Fixed
{
	private:
		int					m_fixed_nb;
		static const int	m_fact_bits = 8;

	public:
	Fixed();
	Fixed( Fixed &to_copy );
	Fixed &operator=( const Fixed& other );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
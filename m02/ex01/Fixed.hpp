#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
 
class Fixed
{
	private:
		int					m_fixed_nb;
		static const int	m_fact_bits = 8;

	public:
		Fixed();
		Fixed( const int to_convert);
		Fixed( const float to_convert);
		Fixed( const Fixed &to_copy );
		~Fixed();

		Fixed&			operator=( const Fixed& other );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
	std::ostream&	operator<<(std::ostream& os, const Fixed &obj);

#endif
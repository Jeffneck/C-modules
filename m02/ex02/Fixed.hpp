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

		//egalite
		Fixed&	operator=( const Fixed& other );

		//pre/post incrementation/decrementation
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		//comparaison
		bool	operator<( const Fixed& other ) const;
		bool	operator<=( const Fixed& other ) const;
		bool	operator>( const Fixed& other ) const;
		bool	operator>=( const Fixed& other ) const;
		bool	operator==( const Fixed& other ) const;
		bool	operator!=( const Fixed& other ) const;

		//arithmetique
		Fixed	operator+( const Fixed& other ) const;
		Fixed	operator-( const Fixed& other ) const;
		Fixed	operator*( const Fixed& other ) const;
		Fixed	operator/( const Fixed& other ) const;

		//fonctions surchargees
		static Fixed		&min( Fixed& a, Fixed& b );
		static Fixed		&max( Fixed& a, Fixed& b );
		static const Fixed	&min( const Fixed& a, const Fixed& b );
		static const Fixed	&max( const Fixed& a, const Fixed& b );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
	//ecriture
	std::ostream&	operator<<(std::ostream& os, const Fixed &obj);

#endif
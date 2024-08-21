#include "Span.hpp"


Span::Span( unsigned int maxSize ) : _maxSize(maxSize) {}

Span::Span( const Span &copy )
{
	if (this != &copy)
		*this = copy;
}

// Span::Span( const Span &other ) : _maxSize(other.getMaxSize()), _iVector(other.getIVector()){}

Span::~Span(){}

Span	&Span::operator=( const Span& other )
{
	if(this == &other)
		return (*this);
	_maxSize = other._maxSize;
	_iVector = other._iVector;

}

void	Span::addNumber(const int &nb) //verif si la reference est pertinente
{
	if(_iVector.size() >= _maxSize)
		throw(MaxSizeExeption());
	_iVector.push_back(nb);
}

const unsigned int &Span::shortestSpan() const
{

}

const unsigned int &Span::longestSpan() const
{
	
}





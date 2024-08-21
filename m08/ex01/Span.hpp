#include <exception>
#include <limits>

template <typename N>
class Span 
{
	public : 
		Span(const N &sMax) : _sizeMax(sMax), _sizeCurr(0), _span(new int[sMax]()){}
		Span(Span &other) : _sizeMax(other.getSizeMax()), _sizeCurr(other.getIndexCurr()), _span(new int[_sizeMax]())
		{
			for (N i = 0; i <= _indexCurr; i++)
				_span[i] = other[i];
		}
		~Span(){delete[] _span;}
		Span &operator=(Span &other)
		{
			Span newSpan(other); //faut il delete other _span ?
			return(newSpan);
		}


		const int &operator[](const N index) //const ou pas, reference ou pas ?
		{
			return(_span[index]);
		}

		void	addNumber(const int nb)
		{
			if(_indexCurr >= _sizeMax - 1)
				throw (std::exception);
			else
			{
				_span[_indexCurr] = nb;
				_indexCurr++;
			}
		}

		void	addRangeIt(); // il faudrait une autre variable template pour representer la diversite de containers possibles ?
		const N	&getSizeMax() const{ return (_sizeMax);}
		const N	&getIndexCurr() const{ return (_indexCurr);}

		const unsigned int shortestSpan() const
		{
			if (_indexCurr < 2)
				throw(std::exception);//span vide ou moins de 2 valeurs
		}
		const unsigned int longestSpan() const
		{
			if (_indexCurr < 2)
				throw(std::exception);//span vide ou moins de 2 valeurs
			
			N i = 0;
			int spanMin = _span[0];
			int spanMax = _span[0];
			
			for(N i = 0; i <= _indexCurr; i++)
			{
				if()
			}

		}

	private:
		const N	_sizeMax;
		const N	_indexCurr;
		int		*_span;

};
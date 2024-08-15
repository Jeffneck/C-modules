#pragma once

// template<typename T>
// class Array 
// {
// 	public : 
// 		Array();
// 		Array(const unsigned int &n);
// 		Array(const Array& toCopy);
// 		~Array();
// 		Array&	operator=(const Array& toAssign);
// 		T&		operator[](const unsigned int& index);

// 		const unsigned int size(void) const;

// 	private :
// 		T*				_data;
// 		unsigned int	_size;

// };

#include <iostream>
#include <stdexcept>

template <typename T>
class Array 
{
	private:
		T* _data;
		unsigned int _size; 

	public:
		Array() : _data(NULL), _size(0) {}

		Array(unsigned int n) : _size(n) 
		{
			_data = new T[n](); // Initialisation avec la valeur par défaut de T
		}

		Array(const Array& other) : _size(other._size)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i) {
				_data[i] = other._data[i];
			}
		}

		Array& operator=(const Array& other)
		{
			if (this == &other) return *this;

			delete[] _data; // Libérer l'ancienne mémoire

			_size = other._size;
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i) {
				_data[i] = other._data[i];
			}
			return *this;
		}

		~Array()
		{
			delete[] _data;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size) {
				throw std::out_of_range("Index out of range");
			}
			return _data[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};
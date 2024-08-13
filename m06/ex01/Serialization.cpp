#include "Serialization.hpp"

/*
Reinterpret_cast sert a 
*/

uintptr_t Serialization::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t ptr)
{
	return(reinterpret_cast<Data *>(ptr));
}

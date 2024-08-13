#pragma once
#include <cstdint>
#include <string>

typedef struct Data 
{
	std::string str;
	size_t		strLength;
} Data;

class Serialization
{
	public : 
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t ptr);
	
	private :
	Serialization();
};
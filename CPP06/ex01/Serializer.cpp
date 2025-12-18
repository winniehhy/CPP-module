#include "Serializer.hpp"

//OCF
Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

//1. Takes the raw memory address
//2. Reinterprets those bits as an unsigned integer
//3. Returns the address as a number
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}


// Project
// 1.Take a pointer to a Data object
// 2.Convert that pointer into an integer
// 3.Convert that integer back into the same pointer
// 4.Prove that the pointer is still the same



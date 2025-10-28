#include <iostream>
#include "Serializer.hpp"

int main() {
	Data original;
	original.id = 42;
	original.name = "example";
	original.value = 3.14;

	uintptr_t raw = Serializer::serialize(&original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original ptr: " << &original << "\n";
	std::cout << "Restored ptr: " << restored << "\n";

	if (restored == &original)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are NOT equal" << std::endl;

	std::cout << "Restored data => id: " << restored->id
			  << ", name: " << restored->name
			  << ", value: " << restored->value << std::endl;

	return 0;
}



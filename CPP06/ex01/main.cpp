#include "Serializer.hpp"

int main() {
    // =======================
    // SUCCESS CASE
    // =======================
    Data data;
    data.id = 101;
    data.name = "HexTest";
    data.value = 88.88;

    Data* originalPtr = &data;

	// Serialize pointer -> integer
    uintptr_t raw = Serializer::serialize(originalPtr);
	// Deserialize integer -> pointer
    Data* restoredPtr = Serializer::deserialize(raw);

    std::cout << "========== SUCCESS CASE ==========\n";

    std::cout << "Original pointer address : "
              << static_cast<void*>(originalPtr) << std::endl;

    std::cout << "Restored pointer address : "
              << static_cast<void*>(restoredPtr) << std::endl;

    std::cout << "Serialized value (hex)   : 0x"
              << std::hex
              << std::setw(sizeof(uintptr_t) * 2)
              << std::setfill('0')
              << raw
              << std::dec << std::endl;

    // Show deserialized pointer as hex (reinterpret pointer bits)
    std::cout << "Deserialized value (hex) : 0x"
              << std::hex
              << std::setw(sizeof(uintptr_t) * 2)
              << std::setfill('0')
              << reinterpret_cast<uintptr_t>(restoredPtr)
              << std::dec << std::endl;

    if (originalPtr == restoredPtr)
        std::cout << "Result                  : SUCCESS (same pointer)\n";
    else
        std::cout << "Result                  : FAILURE\n";

    // Access data safely
    std::cout << "\nData via restored pointer:\n";
    std::cout << "ID    : " << restoredPtr->id << std::endl;
    std::cout << "Name  : " << restoredPtr->name << std::endl;
    std::cout << "Value : " << restoredPtr->value << std::endl;

    // =======================
    // FAILURE CASE
    // =======================
    std::cout << "\n========== FAILURE CASE ==========\n";

    // Corrupt the serialized value on purpose
    uintptr_t corruptedRaw = raw + 1;
    Data* corruptedPtr = Serializer::deserialize(corruptedRaw);

    std::cout << "Original pointer address : "
              << static_cast<void*>(originalPtr) << std::endl;

    std::cout << "Corrupted pointer addr   : "
              << static_cast<void*>(corruptedPtr) << std::endl;


    std::cout << "Original ptr (hex)       : 0x"
              << std::hex
              << std::setw(sizeof(uintptr_t) * 2)
              << std::setfill('0')
              << reinterpret_cast<uintptr_t>(originalPtr)
              << std::dec << std::endl;

    std::cout << "Corrupted raw (hex)      : 0x"
              << std::hex
              << std::setw(sizeof(uintptr_t) * 2)
              << std::setfill('0')
              << corruptedRaw
              << std::dec << std::endl;

    std::cout << "Corrupted ptr (hex)      : 0x"
              << std::hex
              << std::setw(sizeof(uintptr_t) * 2)
              << std::setfill('0')
              << reinterpret_cast<uintptr_t>(corruptedPtr)
              << std::dec << std::endl;

    if (corruptedPtr != originalPtr)
        std::cout << "Expected failure: pointers differ ( FAIL)\n";
    else
        std::cout << "Unexpected success\n";

    std::cout << "\n(Note: Dereferencing corrupted pointer is undefined behavior)\n";

    return 0;
}
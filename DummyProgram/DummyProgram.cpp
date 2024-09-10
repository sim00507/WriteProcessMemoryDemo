#include <Windows.h>
#include <iostream>
#include <string>

#define CHAR_ARRAY_SIZE 128

int main() {
    int varInt = 123456;
    std::string varString("DefaultString");
    char arrChar[CHAR_ARRAY_SIZE] = "Long char array right here ->";

    int* ptr2int = (&varInt);
    int** ptr2ptr = (&ptr2int);
    int*** ptr2ptr2 = (&ptr2ptr);


    do {
        std::cout << "Process ID: " << std::dec << GetCurrentProcessId() << std::endl;
        std::cout << "varInt(0x" << std::hex << (uintptr_t)&varInt << std::dec << ") = " << varInt << std::endl;
        std::cout << "varString(0x" << std::hex << (uintptr_t)&varString << ") = " << varString << std::endl;
        std::cout << "arrChar[" << std::dec << CHAR_ARRAY_SIZE << "](0x" << std::hex << (uintptr_t)&arrChar << ") = " << arrChar << "\n" << std::endl;

        std::cout << "ptr2int(0x" << std::hex << (uintptr_t)&ptr2int << ") = " << std::hex << "0x" << ptr2int << std::endl;
        std::cout << "ptr2ptr(0x" << std::hex << (uintptr_t)&ptr2ptr << ") = " << std::hex << "0x" << ptr2ptr << std::endl;
        std::cout << "ptr2ptr2(0x" << std::hex << (uintptr_t)&ptr2ptr2 << ") = " << std::hex << "0x" << ptr2ptr2 << "\n" << std::endl;

        std::cout << "Press ENTER to print again." << std::endl;
        getchar();
        std::cout << "-----------------------------------------------" << std::endl << std::endl;

    } while (true);

    return EXIT_SUCCESS;
}

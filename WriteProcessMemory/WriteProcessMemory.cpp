#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

#define CHAR_ARRAY_SIZE 128

int main()
{

    int choice;

    DWORD processID = 0;
    std::cout << "PID: ";
    std::cin >> std::dec >> processID;


    HANDLE hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_VM_OPERATION, FALSE, processID); // PROCESS_VM_WRITE or PROCESS_VM_OPERATION
    if (hProcess == NULL) {
        std::cout << "OpenProcess faild. GetLastError() = " << std::dec << GetLastError() << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    else if (hProcess) {
        std::cout << "OpenProcess Success.." << std::endl;
    }

    uintptr_t baseAddress = 0x0;

    std::cout << "Select the type of variable to read:\n";
    std::cout << "1. integer\n";
   // std::cout << "2. string\n";
   // std::cout << "3. char array\n";
    std::cin >> choice;

    BOOL wpmReturn = FALSE;

    switch (choice) {
    case 1: // integer
    {
        std::cout << "Memory address of the integer to read (in hexadecimal): 0x";
        std::cin >> std::hex >> baseAddress;
        std::cout << "Reading 0x" << std::hex << baseAddress << "..." << std::endl;

        int intToWrite = 312532;
        
        wpmReturn = WriteProcessMemory(hProcess, (LPVOID)baseAddress, &intToWrite, sizeof(int), NULL);


        if (wpmReturn == FALSE) {
            std::cout << "WriteProcessMemory failed. GetLastError() = " << std::dec << GetLastError() << std::endl;
            system("pause");
            return EXIT_FAILURE;
        }
        else if (wpmReturn) {
            std::cout << "Overwritten successfully" << std::endl;
        }

        break;
    }
 
    default:
        std::cout << "Invaild choice." << std::endl;
        break;
    }


    std::cout << "Press ENTER to quit." << std::endl;
    system("pause > nul");
    CloseHandle(hProcess); // 리소스 누수 방지

    return EXIT_SUCCESS;



}


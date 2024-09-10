# WriteProcessMemory Demo

This repository demonstrates how to use the `WriteProcessMemory` function in a Windows environment to overwrite memory in a target process. It includes two programs:

1. **Dummy Program**: A simple console application that runs in a loop and prints out memory addresses and values of variables.
2. **WriteProcessMemory Program**: A console application that allows you to write new values to the memory of the Dummy Program.

## How to Use

### Step 1: Compile and Run the Dummy Program

1. Build and run the `DummyProgram.cpp` file.  
   - This program prints out the memory addresses and values of variables such as `varInt`.
   - The program also prints the process ID (PID), which will be used in the `WriteProcessMemory` program.
   - The program will loop indefinitely, allowing you to keep it running while you execute the `WriteProcessMemory` program.

### Step 2: Compile and Run the WriteProcessMemory Program

1. Build and run the `WriteProcessMemory.cpp` file.
2. Enter the **PID** of the Dummy Program that is printed in its output.
3. Select the type of variable to overwrite. In this demo, you can overwrite the `varInt` integer variable.
4. Enter the memory address of the variable (`varInt`) from the Dummy Program.
5. The program will use the `WriteProcessMemory` function to overwrite the integer with a new value (`intToWrite = 312532`).
6. If the operation is successful, the console will display a success message. Otherwise, it will show an error message with the error code.

## Program Structure

### DummyProgram.cpp

- The Dummy Program runs in a loop and prints the values and memory addresses of three variables:
  - `varInt`: An integer initialized with the value `123456`.

### WriteProcessMemory.cpp

- The WriteProcessMemory program allows you to enter a target process's PID and memory address, then overwrites the target memory with a new integer value.
- The program uses the Windows API function `WriteProcessMemory` to perform the memory modification.
- After overwriting the memory, the program prints whether the operation was successful or if an error occurred.

## Example

1. Run the Dummy Program and note the output:
```c++
Process ID: 12345 
varInt(0x7ff64812f8ac) = 123456
varString(0x7ff64812f8c0) = DefaultString
arrChar128 = Long char array right here ->
```
2. Run the WriteProcessMemory Program:
```c++
PID: 12345
Select the type of variable to read:
1.integer
Memory address of the integer to read (in hexadecimal): 0x7ff64812f8ac
Overwritten successfully
```
3. After the write operation, the `DummyProgram` will display the updated `varInt` value:
```c++
varInt(0x7ff64812f8ac) = 312532
```

## Files

- `DummyProgram.cpp`: Source code for the Dummy Program.
- `WriteProcessMemory.cpp`: Source code for the WriteProcessMemory Program.

## Requirements

- Windows operating system
- Visual Studio or any C++ compiler that supports Windows API
- Administrator privileges may be required to run the `WriteProcessMemory` function

## Disclaimer

This project is for educational purposes only. Modifying the memory of other processes can be illegal or harmful if used improperly. Always ensure that you have the right to modify the memory of the target process, and do not use this code for malicious purposes.

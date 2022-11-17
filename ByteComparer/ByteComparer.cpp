#include <iostream>
#include "tchar.h"

#include "IProgram.h"
#include "Impl_MainProgram.h"


std::string retrieveArg(const char** const pArgv, int index)
{
    std::string data;
    
    int j = 0;
    while (pArgv[index][j] != '\0')
    {
        data += pArgv[index][j];
        j++;
    }
    return data;
};

int main(int argc, char** argv)
{

    if (argc > 3 && argc < 2)
    {
        std::cout << "Error: must be 2 cmd line arguments. File path1 [string], file path2 [string]";
        return 1;
    }

    IProgram* prog = new Impl_MainProgram(retrieveArg(argv, 1), retrieveArg(argv, 2));
    while (prog->wantToExit())
    {
        prog->run();
    }

    return 0;
}

#include <string>
#include <iostream>
#include <fstream>

#include "Impl_MainProgram.h"
#include "IResult.h"
#include "ICompareAlgo.h"


Impl_MainProgram::Impl_MainProgram(const std::string& rPath1, const std::string& rPath2) : m_filePath1(rPath1), m_filePath2(rPath2) {}

void Impl_MainProgram::run()
{
}

void Impl_MainProgram::compare()
{
}

bool Impl_MainProgram::_readFile(const std::string& rPath, byte* const pTarget)
{
    //int arraysize = 100000;
    //char myArray[arraysize];

    std::ifstream myfile(rPath);

    if (myfile.is_open())
    {
        try
        {
            const int byteSize = 1;
            myfile.read(pTarget, sizeof(byteSize));
        }
        
        catch (std::exception &e)
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

void Impl_MainProgram::loadData()
{
    if (!_readFile(m_filePath1, m_firstData) && !_readFile(m_filePath2, m_pSecondData))
    {
        //error
    }

    //do someth
}

void Impl_MainProgram::processResult()
{
    m_pResult->process();
}

bool Impl_MainProgram::wantToExit()
{
    return ABaseProgram::wantToExit();
}

void Impl_MainProgram::_compareData()
{
    m_pResult = m_pCompareAlgo->compare();
}

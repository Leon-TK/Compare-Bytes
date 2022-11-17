#pragma once
#include <string>

#include "IProgram.h"
#include "ABaseProgram.h"


class IResult;
class ICompareAlgo;

typedef char byte;


class Impl_MainProgram final : public ABaseProgram, public IProgram
{
private:
	byte* m_firstData = nullptr;
	byte* m_pSecondData = nullptr;
	IResult* m_pResult = nullptr;
	ICompareAlgo* m_pCompareAlgo = nullptr; //strategy

	std::string m_filePath1;
	std::string m_filePath2;

	Impl_MainProgram() = default;

public:
	Impl_MainProgram(const std::string& rFilePath1, const std::string& rFilePath2);
	Impl_MainProgram(const Impl_MainProgram&) = delete;
	Impl_MainProgram(const Impl_MainProgram&&) = delete;
	~Impl_MainProgram()	{ delete m_firstData; delete m_pSecondData; delete m_pResult; delete m_pCompareAlgo;	}

	Impl_MainProgram& operator=(const Impl_MainProgram&) = delete;

	// Inherited via IProgram
	void run() override final;
	void compare() override final;
	void loadData() override final;
	void processResult() override final;
	bool wantToExit() override final;

private:
	bool _readFile(const std::string& rPath, byte* const pTarget);

	void _compareData();

};


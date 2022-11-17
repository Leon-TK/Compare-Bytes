#pragma once

#include "IProgram.h"

class ABaseProgram
{
protected:
	bool m_wantToExit = false;

	ABaseProgram() = default;
	ABaseProgram(const ABaseProgram&) = delete;
	ABaseProgram(const ABaseProgram&&) = delete;
	ABaseProgram& operator=(const ABaseProgram&) = delete;

public:

	bool wantToExit() const;

};
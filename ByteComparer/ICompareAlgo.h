#pragma once

class IResult;

class ICompareAlgo
{
public:
	virtual ~ICompareAlgo() {};
	virtual IResult* compare() = 0;
};
class IResult
{	
public:
	virtual ~IResult() {};
	virtual void process() = 0;
};
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:
	std::map<std::string, ATarget *> targets;
	TargetGenerator(TargetGenerator const &ref);
	TargetGenerator &operator=(TargetGenerator const &ref);
public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *);
	void forgetTargetType(std::string const &targetName);
	ATarget *createTarget(std::string const &targetName);
};


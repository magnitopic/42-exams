#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(TargetGenerator const &ref)
{
	*this = ref;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &ref)
{
	this->targets = ref.targets;
	return *this;
}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
			this->targets[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &targetName)
{
	std::map<std::string, ATarget *>::iterator it = this->targets.find(targetName);
	if (it != this->targets.end())
		this->targets.erase(it);
}

ATarget *TargetGenerator::createTarget(std::string const &targetName)
{
	ATarget *tmp = NULL;
	if (this->targets.find(targetName) != this->targets.end())
		tmp = this->targets[targetName];
	return tmp;
}


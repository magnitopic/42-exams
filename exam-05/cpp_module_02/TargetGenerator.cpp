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

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *Target)
{
	if (Target)
		this->targets[Target->getType()] = Target;
}

void TargetGenerator::forgetTargetType(std::string const &TargetType)
{
	std::map<std::string, ATarget *>::iterator it = this->targets.find(TargetType);
	if (it != this->targets.end())
		this->targets.erase(it);
}

ATarget *TargetGenerator::createTarget(std::string const &TargetType)
{
	ATarget* tmp = NULL;
	if (this->targets.find(TargetType) != this->targets.end())
		tmp = this->targets[TargetType];
	return tmp;
}


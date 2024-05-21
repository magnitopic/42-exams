#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(ATarget const &ref)
{
	*this = ref;
}

ATarget &ATarget::operator=(ATarget const &ref)
{
	this->type = ref.type;
	return *this;
}

std::string ATarget::getType() const
{
	return this->type;
}

ATarget::ATarget(std::string type)
{
	this->type = type;
}

ATarget::~ATarget() {}

void ATarget::getHitBySpell(ASpell const &ref) const
{
	std::cout << this->type << " has been " << ref.getEffects() << "!" << std::endl;
}


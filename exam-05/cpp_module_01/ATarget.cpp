#include "ATarget.hpp"


ATarget::ATarget(ATarget const &ref)
{
	*this = ref;
}

ATarget &ATarget::operator=(ATarget const &ref)
{
	this->type = ref.type;
	return *this;
}

ATarget::~ATarget() {}

std::string ATarget::getType() const
{
	return this->type;
}

ATarget::ATarget(std::string type)
{
	this->type = type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}


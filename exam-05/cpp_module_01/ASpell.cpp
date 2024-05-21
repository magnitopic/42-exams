#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(ASpell const &ref)
{
	*this = ref;
}

ASpell &ASpell::operator=(ASpell const &ref)
{
	this->name = ref.name;
	this->effects = ref.effects;
	return *this;
}

std::string ASpell::getName() const
{
	return this->name;
}

std::string ASpell::getEffects() const
{
	return this->effects;
}

ASpell::ASpell(std::string name, std::string effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::~ASpell() {}

void ASpell::launch(ATarget const &target)
{
	target.getHitBySpell(*this);
}


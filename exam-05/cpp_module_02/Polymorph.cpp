#include "Polymorph.hpp"

Polymorph::~Polymorph() {}

Polymorph::Polymorph() : ASpell("Polymorph", "burnt to a crisp") {}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}


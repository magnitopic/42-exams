#include "Fireball.hpp"

Fireball::~Fireball() {}

Fireball::Fireball() : ASpell("Fireball", "turned into a critter") {}

ASpell *Fireball::clone() const
{
	return (new Fireball());
}


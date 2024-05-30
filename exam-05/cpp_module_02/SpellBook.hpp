#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
	std::map<std::string, ASpell *> knownSpells;
	SpellBook(SpellBook const &ref);
	SpellBook &operator=(SpellBook const &ref);
public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *);
	void forgetSpell(std::string const &spellName);
	ASpell *createSpell(std::string const &spellName);
};


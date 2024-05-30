#include "SpellBook.hpp"


SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &ref)
{
	*this = ref;
}

SpellBook &SpellBook::operator=(SpellBook const &ref)
{
	this->knownSpells = ref.knownSpells;
	return *this;
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell *>::iterator it = this->knownSpells.begin(); it != this->knownSpells.end(); it++)
		delete it->second;
	this->knownSpells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
			this->knownSpells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = this->knownSpells.find(spellName);
	if (it != this->knownSpells.end())
	{
		delete it->second;
		this->knownSpells.erase(it);
	}
}

ASpell *SpellBook::createSpell(std::string const &spellName)
{
	ASpell *tmp = NULL;
	if (this->knownSpells.find(spellName) != this->knownSpells.end())
		tmp = this->knownSpells[spellName];
	return tmp;
}


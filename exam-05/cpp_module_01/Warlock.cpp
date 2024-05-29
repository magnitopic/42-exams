#include "Warlock.hpp"


Warlock::Warlock() {}

Warlock::Warlock(Warlock const &ref)
{
	*this = ref;
}

Warlock &Warlock::operator=(Warlock const &ref)
{
	this->name = ref.name;
	this->title = ref.title;
	return *this;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done." << std::endl;
	for (std::map<std::string, ASpell *>::iterator it = this->knownSpells.begin(); it != this->knownSpells.end(); it++)
		delete it->second;
	this->knownSpells.clear();
}

std::string Warlock::getName() const
{
	return this->name;
}

std::string Warlock::getTitle() const
{
	return this->title;
}

void Warlock::setTitle(std::string const &str)
{
	this->title = str;
}

Warlock::Warlock(std::string name, std::string title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		if (this->knownSpells.find(spell->getName()) == this->knownSpells.end())
			this->knownSpells[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spellName)
{
	if (this->knownSpells.find(spellName) != this->knownSpells.end())
		this->knownSpells.erase(this->knownSpells.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	if (this->knownSpells.find(spellName) != this->knownSpells.end())
		this->knownSpells[spellName]->launch(target);
}


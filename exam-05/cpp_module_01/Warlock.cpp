#include "Warlock.hpp"

Warlock::Warlock(){}

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

std::string const &Warlock::getName() const
{
	return this->name;
}

std::string const &Warlock::getTitle() const
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

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell *>::iterator it = this->SpellBook.begin(); it != this->SpellBook.end(); ++it)
		delete it->second;
	this->SpellBook.clear();
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		if (this->SpellBook.find(spell->getName()) == this->SpellBook.end())
			this->SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spellName)
{
	if (this->SpellBook.find(spellName) != this->SpellBook.end())
		this->SpellBook.erase(this->SpellBook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	if (this->SpellBook.find(spellName) != this->SpellBook.end())
		this->SpellBook[spellName]->launch(target);
}


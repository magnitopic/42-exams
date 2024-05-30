#include "SpellBook.hpp"


SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &ref)
{
	*this = ref;
}

SpellBook &SpellBook::operator=(SpellBook const &ref)
{
	this->book = ref.book;
	return *this;
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell *>::iterator it = this->book.begin(); it != this->book.end(); it++)
		delete it->second;
	this->book.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		this->book[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = this->book.find(spellName);
	if (it != this->book.end())
	{
		delete it->second;
		this->book.erase(it);
	}
}

ASpell *SpellBook::createSpell(std::string const &spellName)
{
	ASpell* tmp = NULL;
	if (this->book.find(spellName) != this->book.end())
		tmp = this->book[spellName];
	return tmp;
}


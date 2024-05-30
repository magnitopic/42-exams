#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	SpellBook book;
	Warlock();
	Warlock(Warlock const &ref);
	Warlock &operator=(Warlock const &ref);
public:
	~Warlock();
	std::string getName() const;
	std::string getTitle() const;
	void setTitle(std::string const &str);
	Warlock(std::string name, std::string title);
	void introduce() const;
	void learnSpell(ASpell *);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget &target);
};


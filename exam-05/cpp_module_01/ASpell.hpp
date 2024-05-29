#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
	std::string name;
	std::string effects;
	ASpell(ASpell const &ref);
	ASpell &operator=(ASpell const &ref);
public:
	virtual ~ASpell();
	std::string getName() const;
	std::string getEffects() const;
	ASpell(std::string name, std::string effects);
	virtual ASpell *clone() const = 0;
	void launch(ATarget const &target);
};


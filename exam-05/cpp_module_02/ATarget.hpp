#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
	std::string type;
	ATarget(ATarget const &ref);
	ATarget &operator=(ATarget const &ref);
public:
	virtual ~ATarget();
	std::string getType() const;
	ATarget(std::string type);
	virtual ATarget *clone() const = 0;
	void getHitBySpell(ASpell const &spell) const;
};


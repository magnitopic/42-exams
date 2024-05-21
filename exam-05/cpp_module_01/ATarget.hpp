#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
	std::string type;
	ATarget();
	ATarget(ATarget const &ref);
	ATarget &operator=(ATarget const &ref);

public:
	std::string getType() const;
	virtual ATarget *clone() const = 0;
	ATarget(std::string type);
	virtual ~ATarget();
	void getHitBySpell(ASpell const &ref) const;
};

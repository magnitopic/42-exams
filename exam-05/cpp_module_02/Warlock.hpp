#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	std::map<std::string, ASpell *> knownSpells;
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


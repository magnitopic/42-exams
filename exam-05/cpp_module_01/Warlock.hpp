#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(Warlock const &ref);
	Warlock &operator=(Warlock const &ref);
	std::map<std::string, ASpell *> SpellBook;

public:
	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &str);
	Warlock(std::string name, std::string title);
	~Warlock();
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget &target);
};


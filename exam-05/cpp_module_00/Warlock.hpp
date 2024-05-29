#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;
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
};


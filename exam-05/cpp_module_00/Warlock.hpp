#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock & operator=(Warlock const & ref);
		Warlock(Warlock const & ref);
	public:
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & str);
		Warlock(std::string name, std::string title);
		~Warlock();
		void introduce() const;
};


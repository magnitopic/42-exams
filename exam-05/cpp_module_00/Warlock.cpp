#include "Warlock.hpp"

Warlock::Warlock(){};

Warlock & Warlock::operator=(Warlock const & ref)
{
	this->name = ref.name;
	this->title = ref.title;
	return *this;
}


Warlock::Warlock(Warlock const & ref)
{
	*this = ref;
}

std::string const & Warlock::getName() const
{
	return this->name;
}

std::string const & Warlock::getTitle() const
{
	return this->title;
}


void Warlock::setTitle(std::string const & str)
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
	std::cout << this->name << ":My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}



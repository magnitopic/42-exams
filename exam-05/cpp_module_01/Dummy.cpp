#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Taget Practice Dummy";
}

Dummy::~Dummy() {}

ATarget* Dummy::clone() const
{
	return (new Dummy());
}

#pragma once
#include <string>
#include "PluralInflector.h"

class EnglishPluralInflector : public PluralInflector
{
	void set_consonant_y_replaces();
public:
	EnglishPluralInflector();
	std::string plural(std::string word) override;

protected:
	void set_replaces() override;
	void set_irregulars() override;
};

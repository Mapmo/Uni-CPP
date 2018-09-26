#pragma once

enum Continent { Africa, Antractica, Asia, Australia, Europe, NorthAmerica, SouthAmerica };

class Country
{
	Continent getCont()const { return this->m_Where; };
public:
	virtual ~Country() {};
protected:
	Continent m_Where;
};

class Bulgaria :public Country
{
public:
	Bulgaria() { this->m_Where = Europe; };
};

//this way we have to deal with an additional class member and we waste memmory
//the way I prefer to deal with such situations is

class Country2
{
	virtual Continent getCont()const = 0;
public:
	virtual ~Country2() {};
};

class USA :public Country2
{
public:
	Continent getCont() const override { return NorthAmerica; };
};

//this way we have to override the getCont function every time, but it costs the same effort as having to write the name in the constructor,
//but now we have 1 less class memeber and we save some space
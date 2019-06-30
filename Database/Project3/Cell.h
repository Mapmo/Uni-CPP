#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstdarg>
#include <fstream>
enum Type { Double, Int, String, Error };

class Cell
{
public:
	Cell(const std::string& val = "NULL");
	const std::string& GetValue()const;
	void SetValue(const std::string&);
private:
	std::string m_Value;
};
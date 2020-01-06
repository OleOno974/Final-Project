/*================================================================= =
Name: Olena Onopriyenko
	File : Utilities.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Nov 2019
	Workshop : Milston Final
	==================================================================*/

#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter = '\0';


// sets the field width of the current object to the value of the parameter
void Utilities::setFieldWidth(size_t input) {

	m_widthField = input;

}


// returns the field width of the current object
size_t Utilities::getFieldWidth() const {

	return m_widthField;

}


// extracts tokens from the first parameter
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	std::string result;



	if (str[next_pos] == getDelimiter())

		throw "error, no token";

	size_t newPos = str.find(getDelimiter(), next_pos);

	if (newPos == std::string::npos) {

		more = false;

		result = str.substr(next_pos);

	}
	else {

		result = str.substr(next_pos, newPos - next_pos);

		more = true;

		next_pos = newPos + 1;

		if (m_widthField < result.length()) {

			m_widthField = result.length();

		}

	}



	return result;

}


// set delimiter
void Utilities::setDelimiter(const char input) {

	m_delimiter = input;



}


// get deimiter
const char Utilities::getDelimiter() const {

	return m_delimiter;

}

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
#ifndef UTILITIES_H

#define UTILITIES_H



#include <iostream>



namespace std {

	class Utilities {
	// specifying the length of the token extracted;

	// used for display purpose later; default value is 1.

		size_t m_widthField = 1;



		// separates the tokens from a given std::string.

		// All Utilities objects share the same delimiter.

		static char m_delimiter;

	public:

		Utilities() { m_widthField = 1; }

		void setFieldWidth(size_t);

		size_t getFieldWidth() const;

		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(const char);

		const char getDelimiter() const;



	};
}


#endif /* Utilities_h */

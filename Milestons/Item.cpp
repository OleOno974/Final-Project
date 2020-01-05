/*================================================================= =
Name: Olena Onopriyenko
	File : Item.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Nov 2019
	Workshop : Milston Final
	==================================================================*/

#include <iomanip>

#include <string>

#include "Item.h"

#include "Utilities.h"



namespace std {

	size_t Item::m_widthField = 1;


	// default construcror
	Item::Item() {

		m_name = "";

		m_description = "";

		m_serialNumber = 0;

		m_quantity = 0;

	}


	// custom constructor receives a reference to an unmodifiable std::string.

	// This string contains a single record(one line) that has been retrieved

	// from the input file specified by the user.

	Item::Item(const std::string& input) {

		Utilities util;

		size_t currPos = 0;

		bool more;

		m_name = util.extractToken(input, currPos, more);

		try {

			if (more)

				m_serialNumber = stoi(util.extractToken(input, currPos, more));

			if (more)

				m_quantity = stoi(util.extractToken(input, currPos, more));

			if (more)

				m_description = util.extractToken(input, currPos, more);

		}
		catch (...) {

			std::cout << ":)" << std::endl;

		}



		Item::m_widthField = util.getFieldWidth();



	}


	// returns the name of the current Item object
	const std::string& Item::getName() const {

		return m_name;

	}


	// returns the next serial number to be used on

	// the assembly line and increments m_serialNumber
	const unsigned int Item::getSerialNumber() {

		return m_serialNumber++;

	}


	// returns the remaining quantity of the current Item object
	const unsigned int Item::getQuantity() {

		return m_quantity;

	}


	// substracts 1 from the available quantity; should not go below 0.
	void Item::updateQuantity() {

		if (m_quantity >= 1)

			m_quantity--;

	}


	// inserts the content of the current object into first parameter.

	// if full is false display just the name and SN, else display the

	// name, SN, quanitity and description of an Item
	void Item::display(std::ostream& os, bool full) const {

		os << std::left << std::setw(Item::m_widthField) << m_name << " [" << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << std::setfill(' ') << "]";

		if (full)

			os << " Quantity: " << std::left << std::setw(Item::m_widthField) << m_quantity << " Description: " << m_description;

		os << std::endl;

	}
}

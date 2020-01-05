/*================================================================= =
Name: Olena Onopriyenko
	File : Item.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Sep 2019
	Workshop : Milston Final
	==================================================================*/
#ifndef ITEM_H

#define ITEM_H


#include <iostream>

namespace std {
	// An object from Item class manages a single item on the assembly line.


	class Item {

		std::string m_name;

		std::string m_description;

		unsigned int m_serialNumber;

		unsigned int m_quantity;

		static size_t m_widthField;

	public:

		Item();

		Item(const std::string&);

		const std::string& getName() const;

		const unsigned int getSerialNumber();

		const unsigned int getQuantity();

		void updateQuantity();

		void display(std::ostream& os, bool full) const;

	};
}
#endif

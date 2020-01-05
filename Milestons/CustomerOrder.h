/*================================================================= =
Name: Olena Onopriyenko
	File : CustomerOrder.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Sep 2019
	Workshop : Milston Final
	==================================================================*/
#ifndef CUSTOMERORDER_H

#define CUSTOMERORDER_H


#include <string>

#include <iomanip>

#include "Item.h"

#include "Utilities.h"

namespace std {

	struct ItemInfo

	{

		std::string m_itemName;

		unsigned int m_serialNumber = 0;

		bool m_fillState = false;



		ItemInfo(std::string src) : m_itemName(src) {};

	};



	class CustomerOrder {

		std::string m_name;

		std::string m_product;

		unsigned int m_cntItm;

		ItemInfo** m_lstItem;

		static size_t m_widthField;



	public:

		CustomerOrder();

		CustomerOrder(std::string);



		//restrict copy assignment and constructor

		CustomerOrder(const CustomerOrder&) { throw "Error"; }

		CustomerOrder& operator = (CustomerOrder&) = delete;



		CustomerOrder(CustomerOrder&&) noexcept;

		CustomerOrder& operator = (CustomerOrder&&);



		~CustomerOrder();



		bool getItemFillState(std::string) const;

		bool getOrderFillState() const;

		void fillItem(Item& item, std::ostream& os);

		void display(std::ostream& os) const;

	};
}
#endif 

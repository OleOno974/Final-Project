/*================================================================= =
Name: Olena Onopriyenko
	File : CustomerOrder.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Sep 2019
	Workshop : Mileston Final
	==================================================================*/
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 1;



CustomerOrder::CustomerOrder() {

	m_name = "";

	m_product = "";

	m_cntItm = 0;

	m_lstItem = nullptr;

}


// custom constructor takes a reference to a string

//containing a single record from the input file
CustomerOrder::CustomerOrder(std::string input) : CustomerOrder() {

	Utilities util;

	bool more;

	size_t currPos = 0;

	m_cntItm = 0;

	m_lstItem = nullptr;

	try {

		m_name = util.extractToken(input, currPos, more);

		if (more)

			m_product = util.extractToken(input, currPos, more);



		size_t tempPos = currPos;

		while (more) {

			std::string dummy = util.extractToken(input, currPos, more);

			m_cntItm++;

		}



		m_lstItem = new ItemInfo*[m_cntItm];

		currPos = tempPos;

		more = true;



		for (size_t i = 0; i < m_cntItm; i++) {

			std::string dummy = util.extractToken(input, currPos, more);

			if (dummy[dummy.length() - 1] == '\r' || dummy[dummy.length() - 1] == '\n') {

				dummy = dummy.substr(0, dummy.length() - 1);

			}

			m_lstItem[i] = new ItemInfo(dummy);

		}



		if (CustomerOrder::m_widthField < util.getFieldWidth())

			CustomerOrder::m_widthField = util.getFieldWidth();



	}
	catch (...) {

		std::cout << "Error" << std::endl;

	}



}



CustomerOrder::CustomerOrder(CustomerOrder&& input) noexcept : CustomerOrder() {

	*this = std::move(input);

}



CustomerOrder& CustomerOrder::operator=(CustomerOrder&& input) {

	if (this != &input) {



		for (size_t i = 0; i < m_cntItm; i++)

			delete m_lstItem[i];





		delete[] m_lstItem;



		m_lstItem = input.m_lstItem;

		m_name = input.m_name;

		m_product = input.m_product;

		m_cntItm = input.m_cntItm;



		input.m_name = "";

		input.m_product = "";

		input.m_cntItm = 0;

		input.m_lstItem = nullptr;

	}



	return *this;

}



CustomerOrder::~CustomerOrder() {

	for (size_t i = 0; i < m_cntItm; i++) {

		delete m_lstItem[i];

		m_lstItem[i] = nullptr;

	}



	delete[] m_lstItem;

	m_lstItem = nullptr;

}


// returns the ItemInfo::m_fillState of the item specified as a parameter.

// If the item doesn’t exist in the order, return true.
bool CustomerOrder::getItemFillState(std::string input) const {

	bool result = true;

	for (size_t i = 0; i < m_cntItm; i++)

		if (input == m_lstItem[i]->m_itemName)

			result = m_lstItem[i]->m_fillState;

	return result;

}


// returns true if all the items in the order have been filled; false otherwise
bool CustomerOrder::getOrderFillState() const {

	bool result = true;

	for (size_t i = 0; i < m_cntItm; i++)

		if (!m_lstItem[i]->m_fillState)

			return false;

	return result;

}


// fills the item in the current order that corresponds to

// the item passed into the function
void CustomerOrder::fillItem(Item& item, std::ostream& os) {

	for (size_t i = 0; i < m_cntItm; i++) {

		if (item.getName() == m_lstItem[i]->m_itemName) {

			if (item.getQuantity() > 0) {

				item.updateQuantity();

				m_lstItem[i]->m_serialNumber = item.getSerialNumber();

				m_lstItem[i]->m_fillState = true;

				os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;

			}
			else {

				os << "Unable to fill " << m_name << ", " << m_product << std::endl;

			}



		}

	}

}


// displays the state of the current object in the format
void CustomerOrder::display(std::ostream& os) const {

	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItm; i++) {

		os << "[" << std::setfill('0') << std::setw(6) << std::right << m_lstItem[i]->m_serialNumber

			<< std::setfill(' ') << "] " << std::left << std::setw(CustomerOrder::m_widthField) << m_lstItem[i]->m_itemName

			<< " - " << ((m_lstItem[i]->m_fillState) ? "FILLED" : "MISSING");

		os << std::endl;

	}



}

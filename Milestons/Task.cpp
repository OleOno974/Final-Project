/*================================================================= =
Name: Olena Onopriyenko
	File : Task.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Nov 2019
	Workshop : Milston Final
	==================================================================*/
#include "Task.h"

#include <iostream>

namespace std {

    Task::Task() : Item() {

		m_pNextTask = nullptr;

	}

    Task::Task(const std::string& input) : Item(input) {

		Task();

	}



	Task& Task::operator += (CustomerOrder&& input) {

		m_order.push_front(std::move(input));

		return *this;

	}



	void Task::runProcess(std::ostream & os) {

		if (m_order.size() > 0) {

			if (!m_order.back().getItemFillState(getName())) {

				

				m_order.back().fillItem(*this, os);

			}

		}

	}



	bool Task::moveTask() {

		if (m_order.size() <= 0) {

			return false;

		}

		else if (m_order.back().getItemFillState(getName())) {

			// true means all items filled, false otherwise

			*m_pNextTask += (std::move(m_order.back()));

			m_order.pop_back();

			return true;

		}

		else

			return false;

	}


	void Task::setNextTask(Task& input) {

		m_pNextTask = &input;

	}



	bool Task::getCompleted(CustomerOrder& ord) {

		if (m_order.size() <= 0)

			return false;

		else {

			if (m_order.back().getItemFillState(getName())) {

				ord = std::move(m_order.back());

				m_order.pop_back();

				return true;

			}

			else

				return false;

		}

	}


	void Task::validate(std::ostream& os) {

		if (m_pNextTask != nullptr)

			os << getName() << " --> " << m_pNextTask->getName() << std::endl;

		else

			os << getName() << " --> END OF LINE" << std::endl;

	}
	Task::~Task() {

		m_pNextTask = nullptr;

	}

}

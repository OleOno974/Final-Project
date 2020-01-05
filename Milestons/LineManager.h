/*================================================================= =
Name: Olena Onopriyenko
	File : Linemanager.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Nov 2019
	Workshop : Milston Final
	==================================================================*/
#ifndef LINEMANAGER_H

#define LINEMANAGER_H


#include <vector>

#include <deque>

#include <string>



#include "Task.h"

namespace std {

	class LineManager {

		std::vector<Task*> AssemblyLine;

		std::deque<CustomerOrder> ToBeFilled;

		std::deque<CustomerOrder> Completed;

		unsigned int m_cntCustomerOrder;
		


	public:

		LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);

		bool run(std::ostream&);

		void displayCompleted(std::ostream&) const;

		void validateTasks() const;



	};

}

#endif /* LineManager_h */

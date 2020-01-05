/*================================================================= =
Name: Olena Onopriyenko
	File : Task.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Section : B
	Date : 30 Nov 2019
	Workshop : Milston Final
	==================================================================*/
#ifndef TASK_H

#define TASK_H



#include <deque>



#include "Item.h"

#include "CustomerOrder.h"



namespace std {

	class Task : public Item {
	// m_orders is a double ended queue (deque) with

	// new CustomerOrders coming in one side and

	//exiting out the other once filled

		std::deque<CustomerOrder> m_order;

		Task* m_pNextTask;



	public:

		Task();
	// custom constructor

	// This string contains a single record that

	// has been retrieved from the input file

	// specified by the user to be used for Item instantiation.

	// it also set the pNextTask to a safe state.
		Task(const std::string&);


		// Copy constructor prevent copy of a Task object

		Task(Task&) = delete;

		// Copy assignment operator set to delete

		Task& operator=(Task&) = delete;

		// Move constructor prevent move of a Task object

		Task(Task&&) = delete;

		// Move assignment operator set to delete

		Task& operator=(Task&&) = delete;



		// This function runs a single cycle of the assembly line for the current task.

		// If there are CustomerOrders in the queue, it will verify the

		// fill status of the last CustomerOrder and fill it if the order

		// contains the Item specified by the current Task.

		void runProcess(std::ostream&);



		// This function moves the last CustomerOrder in the queue

		// to the next task on the assembly line

		// if the orders fill state for the current Item

		// is true.Otherwise, the CustomerOrder should remain

		// in the queue for the next processing cycle.

		// If the queue is empty, return false.

		bool moveTask();



		// This function stores the provided Task object’s reference

		// into the m_pNextTask pointer.

		void setNextTask(Task&);



		// This function Removes the last CustomerOrder from the queue,

		// places it in the parameter and returns true.

		// If the CustomerOrder queue is empty, return false.

		bool getCompleted(CustomerOrder&);



		// This function writes the name of the Item

		// this Task is responsible for

		// into the parameter : ITEM_NAME-- > NEXT_ITEM_NAME

		// if m_pNextTask does not exist it writes: ITEM_NAME --> END OF LINE

		// the messages are terminated with an endline

		void validate(std::ostream&);



		// Move the parameter onto the front of the CustomerOrder queue

		Task& operator+=(CustomerOrder&&);

		// destructor

		~Task();

	};

}

#endif /* Task_h */

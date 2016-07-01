// Todo: Alter the complete_tasks method so that it only calls 'complete' on
//           non-completed task.
//       Add a remove_task method that removes only one task by id
//
//       Upon calling Complete() on a task, set _value of that task object to the number of occurrences of the
//          string "CCN" (case in-sensitive) that appears in the task's name.
//
//       Fix the Task object id, so that it is unique for each new task.
//       Fix other bugs.

// Note: - You cannot edit/change the TaskManager class directly. Think of it as a 3rd party library
//       - You can create new objects, etc

#ifndef __Task__
#define __Task__

#include <string>


class Task {
    int _id;
	std::string _name;
	int _value;
	bool _completed;

	public:
		Task(std::string);

		void Complete();

		bool IsCompleted() const { return _completed; }
		string Name() const { return _name; }
		int Id() const { return _id; }
};

Task::Task(std::string name) {
	_id = 0;
	_name = name;
	_completed = false;
}

void Task::Complete() {
	_completed = true;
}

#endif




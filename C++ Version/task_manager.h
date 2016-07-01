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

#ifndef __TaskManager__
#define __TaskManager__

#include <vector>
#include <iostream>
#include <algorithm>

#include "task.h"


// This class cannot be edited directly
class TaskManager {
    protected:
        std::vector<Task> _tasks;

    public:
        TaskManager() {}

        void CompleteTasks();
        void RemoveTasks();

        void ImportTask(Task task) { _tasks.push_back(task); }
};

void TaskManager::CompleteTasks() {
    if (!_tasks.empty()) {
        if (!std::all_of(_tasks.begin(), _tasks.end(), [](Task& task){return task.IsCompleted();})) {
            for (auto &task : _tasks) {
                task.Complete();
                std::cout << "task " << task.Name() << " completed." << std::endl;
            }
        }
    }
}

void TaskManager::RemoveTasks() {
    _tasks.erase(_tasks.begin(), _tasks.end());
    _tasks.clear();
}

#endif
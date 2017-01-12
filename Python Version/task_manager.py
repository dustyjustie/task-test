""" Todo:
        - Alter the complete_tasks method so that it only calls 'complete' on
            non-completed task.
        - Add a remove_task method that removes only one task by id

        - Upon calling complete() on a task, set _value of that task object to the number of occurrences of the
            string "CCN" (case in-sensitive) that appears in the task's name.

        - Fix the Task object id, so that it is unique for each new task. (please consider scalability and
            what else the Id could be used for)

        - Fix other bugs and make improvements where you see fit
        - Add error handling where you see fit

    Note:
        - You cannot edit/change the TaskManager class directly. Think of it as a 3rd party library
        - You can create new objects, etc
"""


class Task(object):


    counter = 0

    def __init__(self, name):
        self._id = Task.counter
        self._name = name
        self._value = None
        self._completed = False
        Task.counter += 1

    def complete(self):
        if self.is_completed is False:
            self._completed = True
            self._value = self.name.lower().count("ccn")

    @property
    def is_completed(self):
        return self._completed

    @property
    def name(self):
        return self._name


    @property
    def value(self):
        return self._value


# This class cannot be edited directly
class TaskManager(object):

    def __init__(self):
        self._tasks = []

    def import_task(self, task):
        self._tasks.append(task)

    def complete_tasks(self):
        if len(self._tasks) > 0:
            if not all([task.is_completed for task in self._tasks]):
                for task in self._tasks:
                    task.complete()
                    print('task {name} completed'.format(name=task.name))

    def remove_tasks(self):
        while len(self._tasks) > 0:
            self._tasks.pop()
            print('Removing all tasks')

class RefactoredTaskManager(TaskManager):

    def complete_tasks(self):
        if len(self._tasks) > 0:
            if not all([task.is_completed for task in self._tasks]):
                for task in self._tasks:
                    if not task.is_completed:
                        task.complete()
                        print('task {name} completed'.format(name=task.name))
                    else:
                        print('requested task already completed')

    def remove_task(self, id):
        while len(self._tasks) > 0:
            for task in self.tasks:
                if task.id == id:
                    self.tasks.remove(task)
                    print ('removing task {task}'.format(task=task.id))

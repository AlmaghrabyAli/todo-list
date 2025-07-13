#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;
string tasks[MAX_TASKS];
int taskCount = 0;

//   add a task 

void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "The list is full. Cannot add more tasks.\n";
        return;
    }
    cout << "Enter task description: ";
    cin.ignore(); 
    getline(cin, tasks[taskCount]);
    taskCount++;
    cout << "Task added successfully.\n";
}

//  show all tasks

void showTasks() {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\n--- Task List ---\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ") " << tasks[i] << endl;
    }
}

//  delete a task

void deleteTask() {
    int index;
    showTasks();
    if (taskCount == 0) return;

    cout << "Enter the task number to delete: ";
    cin >> index;
    if (index < 1 || index > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }

    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task deleted successfully.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- To-Do List Manager ---\n";
        cout << "1. View tasks\n";
        cout << "2. Add task\n";
        cout << "3. Delete task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: showTasks(); break;
            case 2: addTask(); break;
            case 3: deleteTask(); break;
            case 0: cout << "Exiting the program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

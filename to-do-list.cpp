#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold task details
struct Task {
    string description;
    bool isCompleted;
};

// Function to display the task list
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
    } else {
        cout << "\nTo-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

// Function to add a task to the list
void addTask(vector<Task>& tasks) {
    string newTask;
    cout << "Enter the task description: ";
    cin.ignore();  // Ignore any leftover newline characters
    getline(cin, newTask);

    // Create a Task object and push it into the vector
    Task task;
    task.description = newTask;
    task.isCompleted = false;
    
    tasks.push_back(task);  // Add the task to the list
    cout << "Task added!" << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
    int taskNumber;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;  // Task list
    int choice;

    do {
        cout << "\nTo-Do List Manager:" << endl;
        cout << "1. View Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 0:
                cout << "Exiting the to-do list manager." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}


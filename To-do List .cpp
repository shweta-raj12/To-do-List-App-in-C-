// simple To-Do List App in C++:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "To-Do List App" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
    } else {
        cout << "Available Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
    } else {
        viewTasks(tasks);
        int taskNumber;
        cout << "Enter task number to mark as completed: ";
        cin >> taskNumber;
        cin.ignore(); // Ignore newline character
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
    } else {
        viewTasks(tasks);
        int taskNumber;
        cout << "Enter task number to delete: ";
        cin >> taskNumber;
        cin.ignore(); // Ignore newline character
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting the app. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

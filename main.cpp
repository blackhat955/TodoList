#include <iostream>
#include <vector>
#include <limits>
#include "todo.hpp"
#include "storage.hpp"

void print_tasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    for (const auto& t : tasks) {
        std::cout << "[" << t.id << "] " << (t.completed ? "[✓] " : "[ ] ") << t.description << "\n";
    }
}

int main() {
    std::vector<Task> tasks = load_tasks("tasks.txt");
    int nextId = tasks.empty() ? 1 : tasks.back().id + 1;

    while (true) {
        std::cout << "\n--- To-Do List ---\n"
                  << "1. View Tasks\n2. Add Task\n3. Edit Task\n4. Delete Task\n5. Save & Exit\nChoose: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            print_tasks(tasks);
        } else if (choice == 2) {
            std::string desc;
            std::cout << "Enter task description: ";
            std::getline(std::cin, desc);
            tasks.emplace_back(nextId++, desc);
        } else if (choice == 3) {
            int id;
            std::cout << "Enter task ID to edit: ";
            std::cin >> id;
            std::cin.ignore();
            for (auto& task : tasks) {
                if (task.id == id) {
                    std::cout << "New description: ";
                    std::getline(std::cin, task.description);
                    std::cout << "Mark completed? (1=Yes, 0=No): ";
                    std::cin >> task.completed;
                    break;
                }
            }
        } else if (choice == 4) {
            int id;
            std::cout << "Enter task ID to delete: ";
            std::cin >> id;
            tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                         [id](const Task& t) { return t.id == id; }), tasks.end());
        } else if (choice == 5) {
            save_tasks(tasks, "tasks.txt");
            std::cout << "Tasks saved. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
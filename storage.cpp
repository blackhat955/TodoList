#include "storage.hpp"
#include <fstream>
#include <sstream>

void save_tasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.to_string() << "\n";
    }
}

std::vector<Task> load_tasks(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, desc, doneStr;
        std::getline(ss, idStr, '|');
        std::getline(ss, desc, '|');
        std::getline(ss, doneStr, '|');
        tasks.emplace_back(std::stoi(idStr), desc, doneStr == "1");
    }

    return tasks;
}
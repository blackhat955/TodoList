#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>
#include "todo.hpp"

void save_tasks(const std::vector<Task>& tasks, const std::string& filename);
std::vector<Task> load_tasks(const std::string& filename);

#endif
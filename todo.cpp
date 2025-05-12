#include "todo.hpp"

Task::Task(int id, const std::string& desc, bool completed)
    : id(id), description(desc), completed(completed) {}

std::string Task::to_string() const {
    return std::to_string(id) + "|" + description + "|" + (completed ? "1" : "0");
}
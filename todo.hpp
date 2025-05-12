#ifndef TODO_HPP
#define TODO_HPP

#include <string>

class Task {
public:
    int id;
    std::string description;
    bool completed;

    Task(int id, const std::string& desc, bool completed = false);
    std::string to_string() const;
};

#endif
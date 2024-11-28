// Staff.cpp

#include "Staff.hpp"

/**
 * @brief Construct a new Staff object.
 */
Staff::Staff(const std::string& id, const std::string& name,
    const std::string& address, const std::string& cellPhone,
    const std::chrono::system_clock::time_point& dateOfBirth,
    double salary, const std::string& department)
    : Employee(id, name, address, cellPhone, dateOfBirth, salary),
    department(department) {
    std::cout << "[INFO] Created Staff with ID: " << id << std::endl;
}

void Staff::setDepartment(const std::string& department) {
    assert(!department.empty() && "Department cannot be empty");
    this->department = department;
}

std::string Staff::getDepartment() const {
    return department;
}

// Overloaded output operator to display Staff details
std::ostream& operator<<(std::ostream& os, const Staff& staff) {
    os << static_cast<const Employee&>(staff);
    os << "Department: " << staff.department << "\n";
    return os;
}

// Overloaded input operator to input Staff details
std::istream& operator>>(std::istream& is, Staff& staff) {
    is >> static_cast<Employee&>(staff);
    std::cout << "Enter Department: ";
    is.ignore();
    std::getline(is, staff.department);
    return is;
}

// Equality operator compares IDs
bool Staff::operator==(const Staff& other) const {
    return Employee::operator==(other);
}

// File I/O functions
void Staff::printToFile(std::ofstream& ofs) const {
    if (!ofs) {
        std::cerr << "[ERROR] Failed to open file for writing.\n";
        throw std::runtime_error("File open failed");
    }
    ofs << "Staff\n";
    CommunityMember::printToFile(ofs);
    ofs << salary << "\n";
    ofs << department << "\n";
}

void Staff::readFromFile(std::ifstream& ifs) {
    Employee::readFromFile(ifs);
    std::getline(ifs, department);
}

// Employee.cpp

#include "Employee.hpp"

/**
 * @brief Construct a new Employee object.
 */
Employee::Employee(const std::string& id, const std::string& name,
    const std::string& address, const std::string& cellPhone,
    const std::chrono::system_clock::time_point& dateOfBirth,
    double salary)
    : CommunityMember(id, name, address, cellPhone, dateOfBirth), salary(salary) {
    std::cout << "[INFO] Created Employee with ID: " << id << std::endl;
}

void Employee::setSalary(double salary) {
    assert(salary >= 0 && "Salary cannot be negative");
    this->salary = salary;
}

double Employee::getSalary() const {
    return salary;
}

// Overloaded increment operator to increase salary by 5%
Employee& Employee::operator++() {
    salary += salary * 0.05;
    std::cout << "[INFO] Salary increased by 5%. New salary: " << salary << std::endl;
    return *this;
}

// Overloaded decrement operator to decrease salary by 5%
Employee& Employee::operator--() {
    salary -= salary * 0.05;
    std::cout << "[INFO] Salary decreased by 5%. New salary: " << salary << std::endl;
    return *this;
}

// Overloaded output operator to display Employee details
std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << static_cast<const CommunityMember&>(emp);
    os << "Salary: " << emp.salary << "\n";
    return os;
}

// Overloaded input operator to input Employee details
std::istream& operator>>(std::istream& is, Employee& emp) {
    is >> static_cast<CommunityMember&>(emp);
    std::cout << "Enter Salary: ";
    is >> emp.salary;
    return is;
}

// Equality operator compares IDs
bool Employee::operator==(const Employee& other) const {
    return CommunityMember::operator==(other);
}

// File I/O functions
void Employee::printToFile(std::ofstream& ofs) const {
    if (!ofs) {
        std::cerr << "[ERROR] Failed to open file for writing.\n";
        throw std::runtime_error("File open failed");
    }
    ofs << "Employee\n";
    CommunityMember::printToFile(ofs);
    ofs << salary << "\n";
}

void Employee::readFromFile(std::ifstream& ifs) {
    CommunityMember::readFromFile(ifs);
    std::string salary_str;
    if (std::getline(ifs, salary_str)) {
        salary = std::stod(salary_str);
    }
}

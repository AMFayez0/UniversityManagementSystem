// Employee.hpp

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "CommunityMember.hpp"

/**
 * @brief Derived class representing an employee.
 */
class Employee : public CommunityMember {
protected:
    double salary;

public:
    /**
     * @brief Parameterized constructor with default values.
     */
    Employee(const std::string& id = "", const std::string& name = "",
        const std::string& address = "", const std::string& cellPhone = "",
        const std::chrono::system_clock::time_point& dateOfBirth = std::chrono::system_clock::now(),
        double salary = 0.0);

    void setSalary(double salary);
    double getSalary() const;

    // Overloaded increment/decrement operators
    Employee& operator++();   // Increase salary by 5%
    Employee& operator--();   // Decrease salary by 5%

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
    friend std::istream& operator>>(std::istream& is, Employee& emp);
    bool operator==(const Employee& other) const;

    // File I/O functions
    void printToFile(std::ofstream& ofs) const override;
    void readFromFile(std::ifstream& ifs) override;
};

#endif // EMPLOYEE_HPP

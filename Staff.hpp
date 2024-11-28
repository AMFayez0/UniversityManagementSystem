// Staff.hpp

#ifndef STAFF_HPP
#define STAFF_HPP

#include "Employee.hpp"

/**
 * @brief Derived class representing a staff member.
 */
class Staff : public Employee {
private:
    std::string department;

public:
    /**
     * @brief Parameterized constructor with default values.
     */
    Staff(const std::string& id = "", const std::string& name = "",
        const std::string& address = "", const std::string& cellPhone = "",
        const std::chrono::system_clock::time_point& dateOfBirth = std::chrono::system_clock::now(),
        double salary = 0.0, const std::string& department = "");

    void setDepartment(const std::string& department);
    std::string getDepartment() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Staff& staff);
    friend std::istream& operator>>(std::istream& is, Staff& staff);
    bool operator==(const Staff& other) const;

    // File I/O functions
    void printToFile(std::ofstream& ofs) const override;
    void readFromFile(std::ifstream& ifs) override;
};

#endif // STAFF_HPP

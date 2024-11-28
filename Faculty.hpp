// Faculty.hpp

#ifndef FACULTY_HPP
#define FACULTY_HPP

#include "Employee.hpp"

/**
 * @brief Derived class representing a faculty member.
 */
class Faculty : public Employee {
private:
    std::string specialty;
    std::string academicRank;
    std::string position;
    std::string currentJob;

public:
    /**
     * @brief Parameterized constructor with default values.
     */
    Faculty(const std::string& id = "", const std::string& name = "",
        const std::string& address = "", const std::string& cellPhone = "",
        const std::chrono::system_clock::time_point& dateOfBirth = std::chrono::system_clock::now(),
        double salary = 0.0, const std::string& specialty = "",
        const std::string& academicRank = "", const std::string& position = "",
        const std::string& currentJob = "");

    void setSpecialty(const std::string& specialty);
    std::string getSpecialty() const;

    void setAcademicRank(const std::string& academicRank);
    std::string getAcademicRank() const;

    void setPosition(const std::string& position);
    std::string getPosition() const;

    void setCurrentJob(const std::string& currentJob);
    std::string getCurrentJob() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Faculty& fac);
    friend std::istream& operator>>(std::istream& is, Faculty& fac);
    bool operator==(const Faculty& other) const;

    // File I/O functions
    void printToFile(std::ofstream& ofs) const override;
    void readFromFile(std::ifstream& ifs) override;
};

#endif // FACULTY_HPP

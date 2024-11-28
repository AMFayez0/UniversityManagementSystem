// Student.hpp

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "CommunityMember.hpp"
#include <vector>

/**
 * @brief Derived class representing a student.
 */
class Student : public CommunityMember {
private:
    double gpa;
    std::vector<std::string> courseList;
    int creditHours;

public:
    /**
     * @brief Parameterized constructor with default values.
     */
    Student(const std::string& id = "", const std::string& name = "",
        const std::string& address = "", const std::string& cellPhone = "",
        const std::chrono::system_clock::time_point& dateOfBirth = std::chrono::system_clock::now(),
        double gpa = 0.0, const std::vector<std::string>& courseList = {},
        int creditHours = 0);

    void setGPA(double gpa);
    double getGPA() const;

    void setCourseList(const std::vector<std::string>& courseList);
    std::vector<std::string> getCourseList() const;

    void setCreditHours(int creditHours);
    int getCreditHours() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Student& st);
    friend std::istream& operator>>(std::istream& is, Student& st);
    bool operator==(const Student& other) const;

    // File I/O functions
    void printToFile(std::ofstream& ofs) const override;
    void readFromFile(std::ifstream& ifs) override;
};

#endif // STUDENT_HPP

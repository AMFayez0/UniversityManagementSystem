// Student.cpp

#include "Student.hpp"

/**
 * @brief Construct a new Student object.
 */
Student::Student(const std::string& id, const std::string& name,
    const std::string& address, const std::string& cellPhone,
    const std::chrono::system_clock::time_point& dateOfBirth,
    double gpa, const std::vector<std::string>& courseList,
    int creditHours)
    : CommunityMember(id, name, address, cellPhone, dateOfBirth),
    gpa(gpa), courseList(courseList), creditHours(creditHours) {
    std::cout << "[INFO] Created Student with ID: " << id << std::endl;
}

void Student::setGPA(double gpa) {
    assert(gpa >= 0.0 && gpa <= 4.0 && "GPA must be between 0.0 and 4.0");
    this->gpa = gpa;
}

double Student::getGPA() const {
    return gpa;
}

void Student::setCourseList(const std::vector<std::string>& courseList) {
    this->courseList = courseList;
}

std::vector<std::string> Student::getCourseList() const {
    return courseList;
}

void Student::setCreditHours(int creditHours) {
    assert(creditHours >= 0 && "Credit hours cannot be negative");
    this->creditHours = creditHours;
}

int Student::getCreditHours() const {
    return creditHours;
}

// Overloaded output operator to display Student details
std::ostream& operator<<(std::ostream& os, const Student& st) {
    os << static_cast<const CommunityMember&>(st);
    os << "GPA: " << st.gpa << "\n"
        << "Credit Hours: " << st.creditHours << "\n"
        << "Course List: ";
    for (const auto& course : st.courseList) {
        os << course << " ";
    }
    os << "\n";
    return os;
}

// Overloaded input operator to input Student details
std::istream& operator>>(std::istream& is, Student& st) {
    is >> static_cast<CommunityMember&>(st);
    std::cout << "Enter GPA: ";
    is >> st.gpa;
    std::cout << "Enter Credit Hours: ";
    is >> st.creditHours;
    std::cout << "Enter number of courses: ";
    int numCourses;
    is >> numCourses;
    is.ignore();
    st.courseList.resize(numCourses);
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "Enter Course " << (i + 1) << ": ";
        std::getline(is, st.courseList[i]);
    }
    return is;
}

// Equality operator compares IDs
bool Student::operator==(const Student& other) const {
    return CommunityMember::operator==(other);
}

// File I/O functions
void Student::printToFile(std::ofstream& ofs) const {
    if (!ofs) {
        std::cerr << "[ERROR] Failed to open file for writing.\n";
        throw std::runtime_error("File open failed");
    }
    ofs << "Student\n";
    CommunityMember::printToFile(ofs);
    ofs << gpa << "\n";
    ofs << creditHours << "\n";
    ofs << courseList.size() << "\n";
    for (const auto& course : courseList) {
        ofs << course << "\n";
    }
}

void Student::readFromFile(std::ifstream& ifs) {
    CommunityMember::readFromFile(ifs);
    std::string gpa_str, creditHours_str, numCourses_str;
    if (std::getline(ifs, gpa_str) &&
        std::getline(ifs, creditHours_str) &&
        std::getline(ifs, numCourses_str)) {
        gpa = std::stod(gpa_str);
        creditHours = std::stoi(creditHours_str);
        int numCourses = std::stoi(numCourses_str);
        courseList.resize(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            std::getline(ifs, courseList[i]);
        }
    }
}

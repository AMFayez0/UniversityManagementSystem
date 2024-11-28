// Faculty.cpp

#include "Faculty.hpp"

/**
 * @brief Construct a new Faculty object.
 */
Faculty::Faculty(const std::string& id, const std::string& name,
    const std::string& address, const std::string& cellPhone,
    const std::chrono::system_clock::time_point& dateOfBirth,
    double salary, const std::string& specialty,
    const std::string& academicRank, const std::string& position,
    const std::string& currentJob)
    : Employee(id, name, address, cellPhone, dateOfBirth, salary),
    specialty(specialty), academicRank(academicRank),
    position(position), currentJob(currentJob) {
    std::cout << "[INFO] Created Faculty with ID: " << id << std::endl;
}

void Faculty::setSpecialty(const std::string& specialty) {
    assert(!specialty.empty() && "Specialty cannot be empty");
    this->specialty = specialty;
}

std::string Faculty::getSpecialty() const {
    return specialty;
}

void Faculty::setAcademicRank(const std::string& academicRank) {
    assert(!academicRank.empty() && "Academic rank cannot be empty");
    this->academicRank = academicRank;
}

std::string Faculty::getAcademicRank() const {
    return academicRank;
}

void Faculty::setPosition(const std::string& position) {
    assert(!position.empty() && "Position cannot be empty");
    this->position = position;
}

std::string Faculty::getPosition() const {
    return position;
}

void Faculty::setCurrentJob(const std::string& currentJob) {
    assert(!currentJob.empty() && "Current job cannot be empty");
    this->currentJob = currentJob;
}

std::string Faculty::getCurrentJob() const {
    return currentJob;
}

// Overloaded output operator to display Faculty details
std::ostream& operator<<(std::ostream& os, const Faculty& fac) {
    os << static_cast<const Employee&>(fac);
    os << "Specialty: " << fac.specialty << "\n"
        << "Academic Rank: " << fac.academicRank << "\n"
        << "Position: " << fac.position << "\n"
        << "Current Job: " << fac.currentJob << "\n";
    return os;
}

// Overloaded input operator to input Faculty details
std::istream& operator>>(std::istream& is, Faculty& fac) {
    is >> static_cast<Employee&>(fac);
    std::cout << "Enter Specialty: ";
    is.ignore();
    std::getline(is, fac.specialty);
    std::cout << "Enter Academic Rank: ";
    std::getline(is, fac.academicRank);
    std::cout << "Enter Position: ";
    std::getline(is, fac.position);
    std::cout << "Enter Current Job: ";
    std::getline(is, fac.currentJob);
    return is;
}

// Equality operator compares IDs
bool Faculty::operator==(const Faculty& other) const {
    return Employee::operator==(other);
}

// File I/O functions
void Faculty::printToFile(std::ofstream& ofs) const {
    if (!ofs) {
        std::cerr << "[ERROR] Failed to open file for writing.\n";
        throw std::runtime_error("File open failed");
    }
    ofs << "Faculty\n";
    CommunityMember::printToFile(ofs);
    ofs << salary << "\n";
    ofs << specialty << "\n";
    ofs << academicRank << "\n";
    ofs << position << "\n";
    ofs << currentJob << "\n";
}

void Faculty::readFromFile(std::ifstream& ifs) {
    Employee::readFromFile(ifs);
    std::getline(ifs, specialty);
    std::getline(ifs, academicRank);
    std::getline(ifs, position);
    std::getline(ifs, currentJob);
}

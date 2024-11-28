// Alumnus.cpp

#include "Alumnus.hpp"

/**
 * @brief Construct a new Alumnus object.
 */
Alumnus::Alumnus(const std::string& id, const std::string& name,
    const std::string& address, const std::string& cellPhone,
    const std::chrono::system_clock::time_point& dateOfBirth,
    int yearOfGraduation)
    : CommunityMember(id, name, address, cellPhone, dateOfBirth),
    yearOfGraduation(yearOfGraduation) {
    std::cout << "[INFO] Created Alumnus with ID: " << id << std::endl;
}

void Alumnus::setYearOfGraduation(int year) {
    assert(year >= 1900 && "Year of graduation must be valid");
    this->yearOfGraduation = year;
}

int Alumnus::getYearOfGraduation() const {
    return yearOfGraduation;
}

// Overloaded output operator to display Alumnus details
std::ostream& operator<<(std::ostream& os, const Alumnus& alu) {
    os << static_cast<const CommunityMember&>(alu);
    os << "Year of Graduation: " << alu.yearOfGraduation << "\n";
    return os;
}

// Overloaded input operator to input Alumnus details
std::istream& operator>>(std::istream& is, Alumnus& alu) {
    is >> static_cast<CommunityMember&>(alu);
    std::cout << "Enter Year of Graduation: ";
    is >> alu.yearOfGraduation;
    return is;
}

// Equality operator compares IDs
bool Alumnus::operator==(const Alumnus& other) const {
    return CommunityMember::operator==(other);
}

// File I/O functions
void Alumnus::printToFile(std::ofstream& ofs) const {
    if (!ofs) {
        std::cerr << "[ERROR] Failed to open file for writing.\n";
        throw std::runtime_error("File open failed");
    }
    ofs << "Alumnus\n";
    CommunityMember::printToFile(ofs);
    ofs << yearOfGraduation << "\n";
}

void Alumnus::readFromFile(std::ifstream& ifs) {
    CommunityMember::readFromFile(ifs);
    std::string year_str;
    if (std::getline(ifs, year_str)) {
        yearOfGraduation = std::stoi(year_str);
    }
}

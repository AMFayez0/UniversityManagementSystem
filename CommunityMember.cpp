// CommunityMember.cpp

#include "CommunityMember.hpp"

/**
 * @brief Construct a new Community Member object.
 */
CommunityMember::CommunityMember(const std::string& id, const std::string& name,
    const std::string& address, const std::string& cellPhone,
    const std::chrono::system_clock::time_point& dateOfBirth)
    : id(id), name(name), address(address), cellPhone(cellPhone), dateOfBirth(dateOfBirth) {
    // Log the creation of a new CommunityMember
    std::cout << "[INFO] Created CommunityMember with ID: " << id << std::endl;
}

// Getters and Setters implementations with assertions
void CommunityMember::setId(const std::string& id) {
    assert(!id.empty() && "ID cannot be empty");
    this->id = id;
}

std::string CommunityMember::getId() const {
    return id;
}

void CommunityMember::setName(const std::string& name) {
    assert(!name.empty() && "Name cannot be empty");
    this->name = name;
}

std::string CommunityMember::getName() const {
    return name;
}

void CommunityMember::setAddress(const std::string& address) {
    assert(!address.empty() && "Address cannot be empty");
    this->address = address;
}

std::string CommunityMember::getAddress() const {
    return address;
}

void CommunityMember::setCellPhone(const std::string& cellPhone) {
    assert(!cellPhone.empty() && "Cell phone cannot be empty");
    this->cellPhone = cellPhone;
}

std::string CommunityMember::getCellPhone() const {
    return cellPhone;
}

void CommunityMember::setDateOfBirth(const std::chrono::system_clock::time_point& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

std::chrono::system_clock::time_point CommunityMember::getDateOfBirth() const {
    return dateOfBirth;
}

// Overloaded output operator to display CommunityMember details
std::ostream& operator<<(std::ostream& os, const CommunityMember& cm) {
    // Convert dateOfBirth to time_t
    std::time_t dob_time = std::chrono::system_clock::to_time_t(cm.dateOfBirth);
    std::tm dob_tm = {};  // Initialize tm structure

#if defined(_WIN32) || defined(_WIN64)
    // Use localtime_s on Windows
    errno_t err = localtime_s(&dob_tm, &dob_time);
    if (err != 0) {
        std::cerr << "[ERROR] Failed to convert time using localtime_s.\n";
        os << "Date of Birth: Unknown\n";
    }
    else {
        os << "Date of Birth: " << std::put_time(&dob_tm, "%Y-%m-%d") << "\n";
    }
#else
    // Use localtime_r on POSIX systems
    if (localtime_r(&dob_time, &dob_tm) == nullptr) {
        std::cerr << "[ERROR] Failed to convert time using localtime_r.\n";
        os << "Date of Birth: Unknown\n";
    }
    else {
        os << "Date of Birth: " << std::put_time(&dob_tm, "%Y-%m-%d") << "\n";
    }
#endif

    // Output other member details
    os << "ID: " << cm.id << "\n"
        << "Name: " << cm.name << "\n"
        << "Address: " << cm.address << "\n"
        << "Cell Phone: " << cm.cellPhone << "\n";

    return os;
}

// Overloaded input operator to input CommunityMember details
std::istream& operator>>(std::istream& is, CommunityMember& cm) {
    std::cout << "Enter ID: ";
    is >> cm.id;
    is.ignore(); // Ignore leftover newline
    std::cout << "Enter Name: ";
    std::getline(is, cm.name);
    std::cout << "Enter Address: ";
    std::getline(is, cm.address);
    std::cout << "Enter Cell Phone: ";
    std::getline(is, cm.cellPhone);
    // For simplicity, date of birth is set to current time
    cm.dateOfBirth = std::chrono::system_clock::now();
    return is;
}

// Equality operator compares IDs
bool CommunityMember::operator==(const CommunityMember& other) const {
    return this->id == other.id;
}

// File I/O functions
void CommunityMember::printToFile(std::ofstream& ofs) const {
    if (!ofs) {
        std::cerr << "[ERROR] Failed to open file for writing.\n";
        throw std::runtime_error("File open failed");
    }
    std::time_t dob_time = std::chrono::system_clock::to_time_t(dateOfBirth);
    ofs << id << "\n"
        << name << "\n"
        << address << "\n"
        << cellPhone << "\n"
        << dob_time << "\n";
}

void CommunityMember::readFromFile(std::ifstream& ifs) {
    if (!ifs) {
        std::cerr << "[ERROR] Failed to open file for reading.\n";
        throw std::runtime_error("File open failed");
    }
    std::string dob_str;
    if (std::getline(ifs, id) &&
        std::getline(ifs, name) &&
        std::getline(ifs, address) &&
        std::getline(ifs, cellPhone) &&
        std::getline(ifs, dob_str)) {
        std::time_t dob_time = std::stoll(dob_str);
        dateOfBirth = std::chrono::system_clock::from_time_t(dob_time);
    }
}

// CommunityMember.hpp

#ifndef COMMUNITYMEMBER_HPP
#define COMMUNITYMEMBER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <chrono>
#include <iomanip>

/**
 * @brief Base class representing a community member.
 */
class CommunityMember {
protected:
    std::string id;
    std::string name;
    std::string address;
    std::string cellPhone;
    std::chrono::system_clock::time_point dateOfBirth;

public:
    /**
     * @brief Parameterized constructor with default values.
     */
    CommunityMember(const std::string& id = "", const std::string& name = "",
        const std::string& address = "", const std::string& cellPhone = "",
        const std::chrono::system_clock::time_point& dateOfBirth = std::chrono::system_clock::now());

    // Getters and Setters with input validation
    void setId(const std::string& id);
    std::string getId() const;

    void setName(const std::string& name);
    std::string getName() const;

    void setAddress(const std::string& address);
    std::string getAddress() const;

    void setCellPhone(const std::string& cellPhone);
    std::string getCellPhone() const;

    void setDateOfBirth(const std::chrono::system_clock::time_point& dateOfBirth);
    std::chrono::system_clock::time_point getDateOfBirth() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const CommunityMember& cm);
    friend std::istream& operator>>(std::istream& is, CommunityMember& cm);

    // Equality operator based on ID
    bool operator==(const CommunityMember& other) const;

    // File I/O functions
    virtual void printToFile(std::ofstream& ofs) const;
    virtual void readFromFile(std::ifstream& ifs);

    // Virtual destructor
    virtual ~CommunityMember() = default;
};

#endif // COMMUNITYMEMBER_HPP

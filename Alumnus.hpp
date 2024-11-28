// Alumnus.hpp

#ifndef ALUMNUS_HPP
#define ALUMNUS_HPP

#include "CommunityMember.hpp"

/**
 * @brief Derived class representing an alumnus.
 */
class Alumnus : public CommunityMember {
private:
    int yearOfGraduation;

public:
    /**
     * @brief Parameterized constructor with default values.
     */
    Alumnus(const std::string& id = "", const std::string& name = "",
        const std::string& address = "", const std::string& cellPhone = "",
        const std::chrono::system_clock::time_point& dateOfBirth = std::chrono::system_clock::now(),
        int yearOfGraduation = 0);

    void setYearOfGraduation(int year);
    int getYearOfGraduation() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Alumnus& alu);
    friend std::istream& operator>>(std::istream& is, Alumnus& alu);
    bool operator==(const Alumnus& other) const;

    // File I/O functions
    void printToFile(std::ofstream& ofs) const override;
    void readFromFile(std::ifstream& ifs) override;
};

#endif // ALUMNUS_HPP

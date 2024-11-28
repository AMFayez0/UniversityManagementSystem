// main.cpp

#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Student.hpp"
#include "Alumnus.hpp"
#include "Staff.hpp"
#include "Faculty.hpp"

/**
 * @brief Main function demonstrating the use of classes.
 */
int main() {
    try {
        // Mutex and condition variable for thread synchronization
        std::mutex mtx;
        std::condition_variable cv;
        int ready = 0;

        // Input for Student
        std::cout << "===== Entering details for Student =====\n";
        Student st1;
        std::cin >> st1;

        // Write to file asynchronously
        std::thread t1([&]() {
            std::lock_guard<std::mutex> lock(mtx);
            std::ofstream ofs("Community.dat", std::ios::app);
            st1.printToFile(ofs);
            ofs.close();
            ready++;
            cv.notify_one();
            });

        // Input for Alumnus
        std::cout << "===== Entering details for Alumnus =====\n";
        Alumnus alu1;
        std::cin >> alu1;

        // Write to file asynchronously
        std::thread t2([&]() {
            std::lock_guard<std::mutex> lock(mtx);
            std::ofstream ofs("Community.dat", std::ios::app);
            alu1.printToFile(ofs);
            ofs.close();
            ready++;
            cv.notify_one();
            });

        // Input for Staff
        std::cout << "===== Entering details for Staff =====\n";
        Staff staff1;
        std::cin >> staff1;

        // Write to file asynchronously
        std::thread t3([&]() {
            std::lock_guard<std::mutex> lock(mtx);
            std::ofstream ofs("Community.dat", std::ios::app);
            staff1.printToFile(ofs);
            ofs.close();
            ready++;
            cv.notify_one();
            });

        // Input for Faculty
        std::cout << "===== Entering details for Faculty =====\n";
        Faculty fac1;
        std::cin >> fac1;

        // Increase salary using overloaded operator
        ++fac1;

        // Write to file asynchronously
        std::thread t4([&]() {
            std::lock_guard<std::mutex> lock(mtx);
            std::ofstream ofs("Community.dat", std::ios::app);
            fac1.printToFile(ofs);
            ofs.close();
            ready++;
            cv.notify_one();
            });

        // Compare staff1 and fac1 objects using equality operator
        std::cout << "\n===== Comparing Staff and Faculty IDs =====\n";
        if (static_cast<const CommunityMember&>(staff1) == static_cast<const CommunityMember&>(fac1)) {
            std::cout << "[INFO] Staff and Faculty have the same ID.\n";
        }
        else {
            std::cout << "[INFO] Staff and Faculty have different IDs.\n";
        }


        // Wait for all threads to finish writing
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]() { return ready == 4; });

        // Read all data stored in the file “Community.dat”, then display on the screen
        std::ifstream ifs("Community.dat");
        if (!ifs) {
            std::cerr << "[ERROR] Failed to open file for reading.\n";
            throw std::runtime_error("File open failed");
        }

        std::cout << "\n===== Data Stored in File =====\n";
        std::string line;
        while (std::getline(ifs, line)) {
            std::cout << line << std::endl;
        }

        // Join threads
        t1.join();
        t2.join();
        t3.join();
        t4.join();

    }
    catch (const std::exception& ex) {
        std::cerr << "[EXCEPTION] " << ex.what() << std::endl;
    }

    return 0;
}

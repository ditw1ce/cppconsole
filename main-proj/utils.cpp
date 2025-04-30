#include "utils.h"
#include <iomanip>
#include <iostream>
#include <sstream>

std::string seconds_to_time(int seconds) {
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << h << ":"
        << std::setw(2) << std::setfill('0') << m << ":"
        << std::setw(2) << std::setfill('0') << s;
    return oss.str();
}

void print_spartak(const std::vector<Participant>& data) {
    std::cout << "\n=== Участники из клуба 'Спартак' ===\n";
    for (const auto& p : data) {
        if (p.club == "Спартак") {
            std::cout << p.surname << " " << p.name << " - "
                << seconds_to_time(p.result_seconds) << "\n";
        }
    }
}

void print_best_time(const std::vector<Participant>& data) {
    const int TARGET = 2 * 3600 + 50 * 60;
    std::cout << "\n=== Участники с результатом лучше 2:50:00 ===\n";
    for (const auto& p : data) {
        if (p.result_seconds < TARGET) {
            std::cout << p.surname << " " << p.name << " (" << p.club << ") - "
                << seconds_to_time(p.result_seconds) << "\n";
        }
    }
}
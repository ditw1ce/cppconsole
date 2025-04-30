#include "file_reader.h"
#include <fstream>
#include <sstream>

std::vector<Participant> read_data(const std::string& filename) {
    std::vector<Participant> participants;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        Participant p;
        int id;
        std::string patronymic, start, finish;
        std::istringstream iss(line);

        iss >> id >> p.surname >> p.name >> patronymic >> start >> finish;
        std::getline(iss, p.club);
        p.club = p.club.substr(p.club.find_first_not_of(' '));

        // Конвертация времени
        auto time_to_seconds = [](const std::string& time) {
            int h, m, s;
            char colon;
            std::istringstream iss(time);
            iss >> h >> colon >> m >> colon >> s;
            return h * 3600 + m * 60 + s;
            };

        p.result_seconds = time_to_seconds(finish) - time_to_seconds(start);
        participants.push_back(p);
    }

    return participants;
}
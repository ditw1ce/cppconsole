#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>
#include <string>

struct Participant {
    std::string surname;
    std::string name;
    std::string club;
    int result_seconds;
};

std::vector<Participant> read_data(const std::string& filename);

#endif
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "file_reader.h"

std::string seconds_to_time(int seconds);
void print_spartak(const std::vector<Participant>& data);
void print_best_time(const std::vector<Participant>& data);

#endif
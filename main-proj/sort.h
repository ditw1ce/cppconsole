#ifndef SORT_H
#define SORT_H

#include <vector>
#include "file_reader.h"

void bubble_sort(std::vector<Participant>& data);
void quick_sort(std::vector<Participant>& data, int low, int high);

#endif
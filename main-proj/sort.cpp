#include "sort.h"
#include <algorithm>

// Пузырьковая сортировка
void bubble_sort(std::vector<Participant>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j].result_seconds > data[j + 1].result_seconds) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

// Быстрая сортировка (вспомогательная функция)
int partition(std::vector<Participant>& data, int low, int high) {
    auto& pivot = data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (data[j].club < pivot.club ||
            (data[j].club == pivot.club && data[j].surname < pivot.surname)) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

void quick_sort(std::vector<Participant>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quick_sort(data, low, pi - 1);
        quick_sort(data, pi + 1, high);
    }
}
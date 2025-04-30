#include <iostream>
#include "file_reader.h"
#include "sort.h"
#include "utils.h"

void show_menu() {
    std::cout << "\n=== Меню ===" << std::endl;
    std::cout << "1. Участники из клуба 'Спартак'" << std::endl;
    std::cout << "2. Участники с результатом лучше 2:50:00" << std::endl;
    std::cout << "3. Выбрать сортировку" << std::endl;
    std::cout << "4. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    std::vector<Participant> participants = read_data("input.txt");
    std::vector<Participant> filtered = participants;
    int choice;

    do {
        show_menu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            print_spartak(filtered);
            break;
        case 2:
            print_best_time(filtered);
            break;
        case 3:
            int sort_choice;
            std::cout << "\n=== Сортировка ===\n"
                << "1. Пузырьковая (по времени)\n"
                << "2. Быстрая (по клубу и фамилии)\n"
                << "Выберите метод: ";
            std::cin >> sort_choice;

            if (sort_choice == 1) {
                bubble_sort(filtered);
                std::cout << "\nДанные отсортированы по времени!\n";
            }
            else if (sort_choice == 2) {
                quick_sort(filtered, 0, filtered.size() - 1);
                std::cout << "\nДанные отсортированы по клубу и фамилии!\n";
            }
            break;
        case 4:
            std::cout << "Выход..." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 4);

    return 0;
}
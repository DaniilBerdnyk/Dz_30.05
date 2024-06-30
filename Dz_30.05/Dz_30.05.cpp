#include <iostream>
#include <vector>
#include <algorithm>
#include "Date.h"

void printDate(const Date& date) {
    std::cout << date.getDay() << "-" << date.getMonth() << "-" << date.getYear() << std::endl;
}

int main() {
    std::vector<Date> dates = { Date(1, 1, 2022), Date(2, 2, 2023), Date(3, 3, 2024) };

    auto it = std::find(dates.begin(), dates.end(), Date(2, 2, 2023));
    if (it != dates.end()) {
        std::cout << "Знайдено заданий елемент: ";
        printDate(*it);
    }
    else {
        std::cout << "Заданий елемент не знайдено.\n";
    }

    it = std::min_element(dates.begin(), dates.end());
    if (it != dates.end()) {
        std::cout << "Мінімальний елемент: ";
        printDate(*it);
        dates.erase(it);
    }

    it = std::find(dates.begin(), dates.end(), Date(3, 3, 2024));
    if (it != dates.end()) {
        std::cout << "Знайдено елемент з заданим ключем: ";
        printDate(*it);
        dates.erase(it);
    }

    std::replace_if(dates.begin(), dates.end(), [](const Date& d){
        return d.getYear() < 2024 || (d.getYear() == 2024 && d.getMonth() < 6) || (d.getYear() == 2024 && d.getMonth() == 6 && d.getDay() < 30);
        }, Date(30, 6, 2024));

    std::sort(dates.begin(), dates.end(),[](const Date& a , const Date& b){
        return b < a;
        });
  
    std::sort(dates.begin(), dates.end());

    return 0;
}

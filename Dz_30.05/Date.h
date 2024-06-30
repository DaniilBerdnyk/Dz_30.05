#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Date {
    int day;
    int month;
    int year;
public:
    

   
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool operator<(const Date& rhs) const {
        if (year != rhs.year)
            return year < rhs.year;
        if (month != rhs.month)
            return month < rhs.month;
        return day < rhs.day;
    }

   
    bool operator==(const Date& rhs) const {
        return day == rhs.day && month == rhs.month && year == rhs.year;
    }

    void printDate(const Date& date) {
        std::cout << date.day << "-" << date.month << "-" << date.year << std::endl;
    }
};


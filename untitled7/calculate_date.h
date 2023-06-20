#include <stdio.h>
#include <math.h>

int is_leap_year(int year);
int count_days(int day1, int month1, int year1, int day2, int month2, int year2);
    int correct();

int two_dates() {
    int day1, month1, year1;
    int day2, month2, year2;

    printf("Введіть першу дату (день, місяць, рік): ");
    scanf("%d %d %d", &day1, &month1, &year1);

    printf("Введіть другу дату (день, місяць, рік): ");
    scanf("%d %d %d", &day2, &month2, &year2);

    int days_between = count_days(day1, month1, year1, day2, month2, year2);
    if (days_between != -1) {
        if(year1 == year2) printf("Кількість днів між датами: %d\n", days_between - 365);
        else printf("Кількість днів між датами: %d\n", days_between);
    }

    return 0;
}

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; // Високосний рік
    } else {
        return 0; // Невисокосний рік
    }
}

int count_days(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0;

    // Перевірка коректності введених дат
    if (month1 < 1 || month1 > 12 || month2 < 1 || month2 > 12 ||
        day1 < 1 || day1 > days_in_month[month1 - 1] ||
        day2 < 1 || day2 > days_in_month[month2 - 1]) {
        printf("Некоректні дані введені.\n");
        return -1;
    }

    // Додаємо дні до кінця року першої дати
    for (int i = month1 - 1; i < 12; i++) {
        if (i == month1 - 1) {
            total_days += days_in_month[i] - day1; // Враховуємо перший день
        } else {
            total_days += days_in_month[i];
        }
    }

    // Додаємо дні між роками
    for (int i = year1 + 1; i < year2; i++) {
        if (is_leap_year(i)) {
            total_days += 366; // Високосний рік
        } else {
            total_days += 365; // Невисокосний рік
        }
    }

    // Додаємо дні від початку року другої дати
    for (int i = 0; i < month2 - 1; i++) {
        if (i == month2 - 1 && is_leap_year(year2)) {
            total_days += days_in_month[i] + 1;
        } else {
            total_days += days_in_month[i];
        }
    }
    total_days += day2;

    return total_days;
}

int correct(){
    int day, month, year;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Введіть дату (день, місяць, рік): ");
    scanf("%d %d %d", &day, &month, &year);

    if (month < 1 || month > 12 ||
        day < 1 || day > days_in_month[month - 1]) {
        printf("Такої дати не існує.\n");
        return -1;
    }
    else printf("Дата записана коректно.\n");

    return 0;
}
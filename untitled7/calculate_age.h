#include <stdio.h>
#include <time.h>

int calculateAge(int year, int month, int day) {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    int age = currentYear - year;

    if (currentMonth < month) {
        age--;
    } else if (currentMonth == month && currentDay < day) {
        age--;
    }

    return age;
}

int age() {
    int year, month, day;

    printf("Введіть дату (день, місяць, рік): ");
    scanf("%d %d %d", &day, &month, &year);

    int age = calculateAge(year, month, day);

    printf("Вік: %d років\n", age);

    return 0;
}


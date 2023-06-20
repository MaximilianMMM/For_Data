#include <time.h>

int day_now() {
    // Отримуємо поточну дату та час
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Витягуємо компоненти дати та часу
    int year = current_time->tm_year + 1900;
    int month = current_time->tm_mon + 1;
    int day = current_time->tm_mday;

    // Виводимо поточну дату
    printf("Сьогоднішня дата: %02d.%02d.%d\n", day, month, year);

    return 0;
}

int time_now(){
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    int hour = current_time->tm_hour;
    int minute = current_time->tm_min;
    int second = current_time->tm_sec;

    // Виводимо поточний час
    printf("Поточний час: %02d:%02d:%02d\n", hour, minute, second);

    return 0;
}
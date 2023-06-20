#include <stdio.h>
#include "today.h"
#include "calculate_date.h"
#include "weekday.h"
#include "calculate_age.h"

int chouse();

int menu(){
    printf("\nВас вітає програма для роботи із датою та часом\n");
    printf("Просимо вас обрати опцію яку ви хочете виконати:\n");

    chouse();
    
    return 0;
};

int chouse(){
    int task;

    printf("Перелік допустимих задач: \n\t1) Дізнатися поточну дату; \n\t2) Дізнатися поточну годину;\n\t3) Обрахувати к-сть днів між 2-ма датами;\n\t4) Дізнатися чи існує така дата;\n\t5) Дізнатися день тижня за дотою;\n\t6) Дізнатися вік людини;\n");
    printf("Введіть номер задачі: ");
    scanf("%d", &task);

    while((task>0)&&(task<7)) {

        switch (task) {
            case 1: {
                day_now();
                break;
            }
            case 2: {
                time_now();
                break;
            }
            case 3: {
                two_dates();
                break;
            }
            case 4: {
                correct();
                break;
            }
            case 5: {
                week();
                break;
            }
            case 6: {
                age();
                break;
            }
            default: break;
        }

        printf("\nБажаєте вибрати іншу задачу?\n  (Якщо так, то оберіть номер задачі, інакше напишіть 0)\n");
        scanf("%d", &task);
    }

    printf("Дякуємо що обрали нас!\n");

    return 0;
}
/*
 * Урок #29. Введение в массивы
 */
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>   /* SetConsoleOutputCP - русский текст в консоли Windows */
#endif

#define TOTAL_MARKS 13

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int marks[TOTAL_MARKS];

    /* обнуляем массив, чтобы не печатать "мусор" */
    for (int i = 0; i < TOTAL_MARKS; ++i)
        marks[i] = 0;

    marks[2] = 4;           /* третий элемент (индексы с нуля) */
    marks[0] = 2 * 3;       /* первый элемент */
    marks[12] = 7 - 2;      /* последний элемент: индекс TOTAL_MARKS-1 */
    /* marks[13] = 1;  - ошибка: выход за границу массива! */

    int x = marks[2];
    printf("x = marks[2] = %d\n", x);

    printf("Все элементы: ");
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    printf("\n");

    /* заполнение в цикле и сумма */
    int sum = 0;
    for (int i = 0; i < TOTAL_MARKS; ++i) {
        marks[i] = i % 4 + 2;   /* оценки 2..5 */
        sum += marks[i];
    }
    printf("Новые оценки:  ");
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    printf("\nСумма = %d, среднее = %.2f\n", sum, (double)sum / TOTAL_MARKS);

    return 0;
}

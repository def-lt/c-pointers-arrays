/*
 * Урок #29. Введение в массивы
 */
#include <stdio.h>

#define TOTAL_MARKS 13

int main(void)
{
    int marks[TOTAL_MARKS];

    /* обнуляем массив, чтобы не печатать "musor" */
    for (int i = 0; i < TOTAL_MARKS; ++i)
        marks[i] = 0;

    marks[2] = 4;           /* третий элемент (индексы с нуля) */
    marks[0] = 2 * 3;       /* первый элемент */
    marks[12] = 7 - 2;      /* последний элемент: индекс TOTAL_MARKS-1 */
    /* marks[13] = 1;  - ошибка: выход за границу массива! */

    int x = marks[2];
    printf("x = marks[2] = %d\n", x);

    printf("Vse elementy: ");
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    printf("\n");

    /* заполнение в цикле и сумма */
    int sum = 0;
    for (int i = 0; i < TOTAL_MARKS; ++i) {
        marks[i] = i % 4 + 2;   /* оценки 2..5 */
        sum += marks[i];
    }
    printf("Novye otsenki:  ");
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    printf("\nSumma = %d, srednee = %.2f\n", sum, (double)sum / TOTAL_MARKS);

    return 0;
}

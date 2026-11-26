/*
 * Урок #30. Вычисление размера массива. Инициализация массивов
 */
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>   /* SetConsoleOutputCP - русский текст в консоли Windows */
#endif
#include <stdlib.h>

#define TOTAL_MARKS 13

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /* глобальный */

static void print_int(const char *name, const int *a, size_t n)
{
    printf("%s: ", name);
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    /* 1. Размер массива */
    int marks[TOTAL_MARKS] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t bytes = sizeof(marks);
    size_t size1 = sizeof(marks) / sizeof(marks[0]);
    size_t size2 = sizeof(marks) / sizeof(*marks);
    printf("1) sizeof(marks) = %zu байт, элементов: %zu (= %zu)\n\n", bytes, size1, size2);

    /* 2. Частичная инициализация - остальные нули */
    int part[TOTAL_MARKS] = {1, 2, 3};
    print_int("2) {1, 2, 3}      ", part, sizeof(part) / sizeof(*part));

    /* 3. Размер берётся из списка инициализации */
    int coords[] = {10, -2, 30};
    printf("3) coords[] = {10, -2, 30}, элементов: %zu\n",
           sizeof(coords) / sizeof(*coords));

    /* 4. Назначенные инициализаторы (C99) */
    short digits[10] = {-1, [2] = 5, 18, [9] = -1};
    printf("4) {-1, [2]=5, 18, [9]=-1}: ");
    for (size_t i = 0; i < sizeof(digits) / sizeof(*digits); ++i)
        printf("%d ", digits[i]);
    printf("\n");

    /* 5. Глобальный массив */
    print_int("5) month[]        ", month, sizeof(month) / sizeof(*month));

    /* 6. Локальный массив можно инициализировать переменными и функциями */
    int val = -7;
    int loc[TOTAL_MARKS] = {1, 2, 3, 4, val, abs(val)};
    print_int("6) {.., val, abs(val)}", loc, sizeof(loc) / sizeof(*loc));

    /* marks = {1, 2, 3}; - ошибка: так можно только при объявлении */
    return 0;
}

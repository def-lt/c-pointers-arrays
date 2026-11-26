/*
 * Урок #31. Указатели на массивы
 */
#include <stdio.h>

int main(void)
{
    short ar[] = {4, 3, 2, 1, 5, 6, 7};
    size_t n = sizeof(ar) / sizeof(*ar);

    /* 1. Имя массива - адрес его первого элемента */
    short a_1 = *ar;
    short a_4 = *(ar + 3);
    printf("1) *ar = %d, *(ar+3) = %d\n", a_1, a_4);

    printf("   vse elementy cherez *(ar+i): ");
    for (size_t i = 0; i < n; ++i)
        printf("%d ", *(ar + i));
    printf("\n\n");

    /* 2. Обычный указатель на массив */
    short *ptr_ar = ar;         /* то же, что &ar[0] */
    short x = *ptr_ar;
    *(ptr_ar + 1) = -3;         /* меняем второй элемент */
    printf("2) x = *ptr_ar = %d, posle *(ptr_ar+1) = -3: ar[1] = %d\n\n", x, ar[1]);

    /* 3. sizeof массива и указателя */
    printf("3) sizeof(ar) = %zu, sizeof(ptr_ar) = %zu\n\n", sizeof(ar), sizeof(ptr_ar));

    /* 4. Указатель можно двигать, имя массива - нельзя */
    /* ar++;  - ошибка компиляции */
    printf("4) obhod cherez ptr_ar++: ");
    for (short *p = ar; p < ar + n; p++)
        printf("%d ", *p);
    printf("\n\n");

    /* 5. Индексация через указатель */
    ptr_ar = ar;
    printf("5) ptr_ar[2] = %d, ar[2] = %d, *(ar+2) = %d, 2[ar] = %d\n",
           ptr_ar[2], ar[2], *(ar + 2), 2[ar]);

    /* 6. Указатель на весь массив: short (*)[7] */
    short (*pa)[7] = &ar;
    printf("6) pa = %p, pa + 1 = %p (sdvig na %td bayt)\n",
           (void *)pa, (void *)(pa + 1), (char *)(pa + 1) - (char *)pa);
    printf("   (*pa)[6] = %d\n", (*pa)[6]);

    return 0;
}

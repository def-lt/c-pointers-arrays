/*
 * Урок #28. Адресная арифметика
 */
#include <stdio.h>

int main(void)
{
    /* 1. Инкремент/декремент указателя сдвигает адрес на sizeof(тип) */
    int g = 4;
    int *ptr = &g;

    printf("1) sizeof(int) = %zu\n", sizeof(int));
    printf("   ptr     = %p\n", (void *)ptr);
    ptr++;
    printf("   ptr++  -> %p\n", (void *)ptr);
    ptr--;
    printf("   ptr--  -> %p\n\n", (void *)ptr);

    /* 2. Сложение и вычитание целых чисел */
    int *start = ptr;
    ptr += 3;
    ptr -= 4;
    ptr = ptr + 10;
    ptr = ptr - 9;
    --ptr;
    ptr++;
    printf("2) после +3 -4 +10 -9 -1 +1 указатель вернулся: %s\n\n",
           ptr == start ? "да" : "нет");

    /* 3. Разность указателей - расстояние в элементах */
    short ar[10];
    short *p1 = ar;
    short *p2 = &ar[3];
    printf("3) p1 = %p, p2 = %p\n", (void *)p1, (void *)p2);
    printf("   p2 - p1 = %td (элементов), в байтах: %td\n\n",
           p2 - p1, (char *)p2 - (char *)p1);

    /* 4. Побайтовый просмотр int через char* */
    int n = 476789;
    unsigned char *pb = (unsigned char *)&n;
    printf("4) байты числа %d (0x%08X):\n   ", n, n);
    for (size_t i = 0; i < sizeof(n); ++i)
        printf("%d ", *pb++);   /* сначала берём значение, потом сдвигаем */
    printf("\n\n");

    /* 5. Приоритеты операций */
    unsigned char *q = (unsigned char *)&n;
    printf("5) Приоритеты:\n");
    printf("   *q + 1   = %d (первый байт + 1)\n", *q + 1);
    printf("   *(q + 1) = %d (второй байт)\n", *(q + 1));
    int x = *q++;
    printf("   x = *q++ = %d, теперь *q = %d\n", x, *q);
    x = (*q)++;
    printf("   x = (*q)++ = %d, теперь *q = %d (изменилось значение)\n", x, *q);

    int *pg = &g;
    *pg += 1;
    printf("   *pg += 1 -> g = %d\n", g);

    return 0;
}

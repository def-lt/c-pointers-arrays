/*
 * Урок #27. Указатели. Приведение типов. Константа NULL
 */
#include <stdio.h>

int main(void)
{
    /* 1. Два указателя на одну переменную */
    int arg = 7;
    int *ptr_arg, *ptr;

    ptr_arg = &arg;
    ptr = ptr_arg;              /* копируем адрес из одного указателя в другой */

    printf("1) Dva ukazatelya na odnu peremennuyu\n");
    printf("   *ptr = %d, arg = %d\n", *ptr, arg);
    *ptr_arg = 100;             /* меняем значение через первый указатель */
    printf("   *ptr = %d, arg = %d\n\n", *ptr, arg);

    /* 2. Приведение типов: смотрим на int через char* */
    int num = 777;
    int *p_int = &num;
    char *p_ch = (char *)p_int; /* явное приведение int* -> char* */

    printf("2) Privedenie tipov ukazateley\n");
    printf("   num = %d\n", num);
    *p_ch = 1;                  /* записываем только в младший байт */
    printf("   posle *p_ch = 1: *p_int = %d, num = %d\n\n", *p_int, num);
    /* 777 = 0x0309, младший байт 0x09 заменили на 0x01 -> 0x0301 = 769 */

    /* 3. Указатель void* */
    void *p = p_ch;             /* в void* можно записать любой адрес */
    p_int = p;                  /* и обратно - без приведения */
    printf("3) void*: p = %p, p_int = %p, *p_int = %d\n\n", p, (void *)p_int, *p_int);
    /* *p = 10; - ошибка: через void* нельзя читать и записывать */

    /* 4. Константа NULL */
    int val = 5;
    int *pn = NULL;             /* указатель пока никуда не указывает */

    printf("4) Konstanta NULL\n");
    if (pn != NULL)
        *pn = 1;
    else
        printf("   pn == NULL, zapis propuschena, val = %d\n", val);

    pn = &val;
    if (pn != NULL)
        *pn = 1;
    printf("   pn = &val, posle zapisi val = %d\n", val);

    return 0;
}

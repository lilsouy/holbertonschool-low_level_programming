#include "main.h"

/**
 * main - test print_sign function
 *
 * Return: 0
 */
int main(void)
{
    int r;

    r = print_sign(98);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0'); /* 1 will print correctly */
    _putchar('\n');

    r = print_sign(0);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0'); /* 0 will print correctly */
    _putchar('\n');

    r = print_sign(0xff); /* 255 */
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0'); /* 1 will print correctly */
    _putchar('\n');

    r = print_sign(-1);
    _putchar(',');
    _putchar(' ');
    _putchar('-'); /* لا تستخدم r + '0' للرقم السالب */
    _putchar('\n');

    return (0);
}

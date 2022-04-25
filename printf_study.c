#include <stdio.h>

int main()
{
    int a = 5;
    int *b = &a;

    printf("----------printf with c characters----------\n");
    printf("1) %s %3c\n", "%3c", 'm');
    /*printf("2) %s %3.2c\n", "%3.2c", "m"); c dont have precision
    printf("3) %s % 3c\n", "% 3c", "m"); c dont have space flag
    printf("4) %s %03c\n", "%03c", "m"); c dont have zero flag*/
    printf("5) %s %-3c\n", "%-3c", 'm');
    /*printf("6) %s %+3c\n", "%+3c", "m"); c dont have plus flag*/
    printf("----------printf with s characters----------\n");
    printf("1) %s %.4s\n", "%.4s", "he");
    printf("2) %s %5.1s\n", "%5.1s", "he");
    //printf("3) %s % 5s\n", "% 5s", "he"); s dont have space flag
    printf("4) %s %.s\n", "%.s", "he");
    printf("5) %s %-5s\n", "%-5s", "he");
    printf("6) %s %5s\n", "%5s", "he");
    printf("----------printf with d characters----------\n");
    printf("1) %s %6.d\n", "%6.d", 0);
    printf("2) %s %6.4d\n", "%6.4d", 123);
    printf("3) %s % .2d\n", "% .2d", 123);
    printf("4) %s %06d\n", "%06d", 123);
    printf("5) %s %-5d\n", "%-5d", 123);
    printf("6) %s %+2.5d\n", "%+2.5d", 123);
    printf("----------printf with i characters----------\n");
    printf("1) %s %3.i\n", "%3.i", -20);
    printf("2) %s %3.2i\n", "%3.2i", -20);
    printf("3) %s % 3i\n", "% 3i", -20);
    printf("4) %s %03i\n", "%03i", -20);
    printf("5) %s %-.3i\n", "%-.3i", -20);
    printf("6) %s %-3i\n", "%-3i", -20);
    printf("----------printf with u characters----------\n");
    printf("1) %s %5.u\n", "%5.u", 20);
    printf("2) %s %5.2u\n", "%5.2u", 20);
    //printf("3) %s %+3u\n", "%+3u", 20);
    printf("4) %s %05u\n", "%05u", 20);
    printf("5) %s %-.5u\n", "%-.5u", 20);
    printf("6) %s %-5u\n", "%-5u", 20);
    printf("----------printf with x characters----------\n");
    printf("1) %s %6.x\n", "%6.x", 123);
    printf("2) %s %6.1x\n", "%6.1x", 123);
    /*printf("3) %s % 6x\n", "% 6c", 123); x cant  have space flag*/
    printf("4) %s %0x\n", "%0x", 123);
    printf("5) %s %#6.4x\n", "%#6.4x", 123);
    printf("6) %s %#6.4X\n", "%#6.4X", 123);
    /*printf("6) %s %+6x\n", "%+6c", 123); x cant have plus or minus flag*/
    printf("----------printf with p characters----------\n");
    printf("1) %s %3p\n", "%3p", b);
    //printf("2) %s %3.2p\n", "%3.2p", b);
    //printf("3) %s % 3p\n", "% 3p", b);
    //printf("4) %s %03p\n", "%03p", b);
    printf("5) %s %-3p\n", "%-3p", b);
    //printf("6) %s %+3p\n", "%+3p", b);
    return (0);
}
#include <stdio.h>

int main()
{
    printf("----------printf with c characters----------\n");
    /*printf("1) %s %3.c\n", "%3.c", "m"); c dont have precision
    printf("2) %s %3.2c\n", "%3.2c", "m"); c dont have precision
    printf("3) %s % 3c\n", "% 3c", "m"); c dont have space flag
    printf("4) %s %03c\n", "%03c", "m"); c dont have zero flag*/
    printf("5) %s %-3c\n", "%-3c", 'm');
    printf("5) %s %3c\n", "%3c", 'm');
    /*printf("6) %s %+3c\n", "%+3c", "m"); c dont have plus flag*/
    printf("----------printf with s characters----------\n");
    printf("1) %s %5.s\n", "%5.s", "he");
    printf("2) %s %5.2s\n", "%5.2s", "he");
    /*printf("3) %s % 5s\n", "% 5s", "he"); s dont have space flag
    printf("4) %s %05s\n", "%05s", "he"); s dont have zero flag*/
    printf("5) %s %-5s\n", "%-5s", "he");
    /*printf("6) %s %+5s\n", "%+5s", "he"); s dont have plus flag*/
    printf("----------printf with d characters----------\n");
    printf("1) %s %6.d\n", "%6.d", 123);
    printf("2) %s %6.2d\n", "%6.2d", 123);
    printf("3) %s % 6d\n", "% 6d", 123);
    printf("4) %s %06d\n", "%06d", 123);
    printf("5) %s %-6d\n", "%-6d", 123);
    printf("6) %s %+6d\n", "%+6d", 123);
    printf("----------printf with i characters----------\n");
    printf("1) %s %3.i\n", "%3.i", 4);
    printf("2) %s %3.2i\n", "%3.2i", 4);
    printf("3) %s % 3i\n", "% 3i", 4);
    printf("4) %s %03i\n", "%03i", 4);
    printf("5) %s %-3i\n", "%-3i", 4);
    printf("6) %s %+3i\n", "%+3i", 4);
    printf("----------printf with x characters----------\n");
    printf("1) %s %6.x\n", "%6.c", 123);
    printf("2) %s %6.2x\n", "%6.2c", 123);
    /*printf("3) %s % 6x\n", "% 6c", 123); x cant  have space flag*/
    printf("4) %s %06x\n", "%06c", 123);
    printf("5) %s %#6x\n", "%#6c", 123);
    /*printf("6) %s %+6x\n", "%+6c", 123); x cant have plus or minus flag*/
    printf("----------printf with errors----------\n");
    //printf("%v\n");
    //printf("%s % #x", "% #x", 20);
    printf("%s %-+d\n", "-+d", 20);
    printf("%s %+-d\n", "+-d", 20);
    printf("%s %+060d\n", "+060d", 20);
    return (0);
}
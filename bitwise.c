#include <stdio.h>
#include <stdlib.h>

void    print_bit(int c)
{
    char byte[9];

    byte[8] = '\0';
    int i = 7;
    while(i >= 0)
    {
        if (c % 2 == 0)
            byte[i] = '0';
        else if (c % 2 == 1)
            byte[i] = '1';
        c = c / 2;
        i--;
    }
    printf("%s\n", byte);
}

// int main(int ac, char **av)
// {
//     // printf("hi");
//     int a = atoi(av[1]);
//     int b = atoi(av[2]);

//     print_bit(a);
//     print_bit(b);
//     printf("%d & %d = %d\n", a, b, a & b); // and
//     printf("%d | %d = %d\n", a, b, a | b); // or
//     printf("%d ^ %d = %d\n", a, b, a ^ b); // xor
//     printf("~ %d = %d\n", a, ~a); // not
//     printf("~ %d = %d\n", b, ~b); // not
    
//     print_bit(a<<b); // equivalent to a = a * 2^b
//     printf("%d << %d = %d\n", a , b, a << b); // left shift
//     print_bit(a>>b); // equivalent to a = a / 2^b
//     printf("%d >> %d = %d\n", a , b, a >> b); // right shift
// }

void    print_bit2(int c)
{
    char byte[9];

    byte[8] = '\0';
    int i = 7;
    while(i >= 0)
    {
        if ((c & 1) == 1)
            byte[i] = '1';
        else
            byte[i] = '0';
        c = c >> 1;
        i--;
    }
    printf("%s\n", byte);
}

int main(int ac, char **av)
{
    // printf("hi");
    int a = atoi(av[1]);
    // int b = atoi(av[2]);

    print_bit(a);
    print_bit2(a);

    printf("%d\n", 0&1);
}

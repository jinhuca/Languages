#include <stdio.h>

/* strlen: return length of s */
int strlen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

int main()
{
    char str[] = "I am a string";
    int result = strlen(str);
    printf("The length of string: %d", result);
}
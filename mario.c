#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int level = -1;
    while (level < 0 || level > 8){
        level = get_int("Height: ");
    }

    char pyramid = '#';
    int space = level;

    for (int i = 0; i < level; i++){
        for (int j = space - 1; j > 0; j--) {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) {
            printf("%c",pyramid);
        }
        printf("  ");
        for (int k = 0; k <= i; k++) {
            printf("%c",pyramid);
        }
        printf("\n");

        //printf("%c  %c\n", pyramid, pyramid);
        //pyramid = pyramid + "#";
        space--;
    }
}
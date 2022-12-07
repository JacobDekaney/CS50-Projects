/*
Code for the CS50 cerification course

This code pritns out a pyramid of #s based on the number
inputted by the user
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int level = -1;
    while (level < 0 || level > 8){
        level = get_int("Height: "); //takes a user input the is between 0 and 8
    }

    char pyramid = '#';
    int space = level;

    for (int i = 0; i < level; i++){
        for (int j = space - 1; j > 0; j--) { //prints the amount of spaces based on pyramid size and level
            printf(" ");
        }
        for (int k = 0; k <= i; k++) { //prints the left side of the pyramid based on size and level
            printf("%c",pyramid);
        }
        printf("  ");
        for (int k = 0; k <= i; k++) { //prints the right side of the pyramid based on size and level
            printf("%c",pyramid);
        }
        printf("\n");

        space--;
    }
}
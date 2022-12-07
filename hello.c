/*
Code written for the CS50 certification course

Code takes user input and prints a statement based off the user input
*/

#include <stdio.h>
#include <cs50.h>

int main(void) {
    string name = get_string("What's your name? "); //takes input from the user
    printf("Hello, %s\n", name); //prints Hello, with the user's input
}
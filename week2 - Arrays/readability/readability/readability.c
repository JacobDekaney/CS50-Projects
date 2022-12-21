#include <cs50.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text) //counts the letters in the user input
{
    int letters = 0;
    int index = 0;

    while (text[index] != 0)
    {
        if ((text[index] >= 65 && text[index] <= 90) || (text[index] >= 97
                && text[index] <= 122)) //checks to see if the given characters are within the ASCII decimal values of letters
        {
            letters++;
        }
        index++;
    }
    return letters;
}

int count_words(string text)
{
    int words = 1; //starts with one work in order to account for the first word entered
    int index = 0;

    while (text[index] != 0)
    {
        if (text[index] == 32) //checks to see if a character is equal to the ASCII decimal value of a space
        {
            words++;
        }
        index++;
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int index = 0;

    while (text[index] != 0)
    {
        if ((text[index] == 46) || (text[index] == 33)
            || (text[index] == 63)) //checks to see if a character is equal to the ASCII value of a . or ? or !
        {
            sentences++;
        }
        index++;
    }

    return sentences;
}

int grade_level(double letters, double words, double sentences)
{
    double grade = 0;
    double L = 0;
    double S = 0;

    L = (letters / words) * 100; //computes the L value in the algorithm
    S = (sentences / words) * 100; //computes the S value in the algorithm

    grade = .0588 * L - 0.296 * S - 15.8; //uses the values to calculate the Coleman-Liau index

    return round(grade); //rounds the value to the nearest whole number
}

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = grade_level(letters, words, sentences);
    if (grade < 1) //checks to see if grade is above or below 1 or 16 respectivley
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
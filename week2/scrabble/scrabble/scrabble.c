#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("score1: %d\n",score1);
    printf("score2: %d\n",score2);

    bool x = score1  > score2;
    bool z = score1 == score2;

    //printf("%d\n",x);

    if (x) {
        printf("Player 1 wins!\n");
    }
    else if (!x) {
        printf("Player 2 wins!\n");
    }
    if (z) {
        printf("Tie!\n");
    }
    //printf("test\n");
    return 0;
}

int compute_score(string word)
{
    int score = 0;
    //printf("%lu\n", strlen(word));
    for (unsigned long i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            word[i] -= 65;
        }
        else if (islower(word[i])) {
            word[i] -= 97;
        }
        else {
            word[i] = -1;
        }
        for (int j = 0; j < 26; j++) {
            if (word[i] == j) {
                score += POINTS[j];
            }
        }

    }
    //printf("%d\n",score);
    return score;
}

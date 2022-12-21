#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int test_sum = 0;

    if (argc != 2)
    {
        return 1;
    }

    string cypher = argv[1];

    if (strlen(cypher) != 26 || cypher == NULL)
    {
        return 1;
    }

    for (int j = 0; j < 26; j++)
    {
        if (isupper(cypher[j]))
        {
            cypher[j] += 32;
            test_sum += cypher[j];
        }
        else if (islower(cypher[j]))
        {
            test_sum += cypher[j];
        }
        /*
        else
        {
            return 1;
        }
        */
    }
    if (test_sum != 2847)
    {
        return 1;
    }

    string text = get_string("plaintext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            text[i] -= 65;
            text[i] = cypher[(int)text[i]];
            text[i] -= 32;
        }
        else if (islower(text[i]))
        {
            text[i] -= 97;
            text[i] = cypher[(int)text[i]];
        }
    }

    printf("ciphertext: %s\n", text);

    return 0;
}
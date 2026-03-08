#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char letter, int times);

int main(int argc, string argv[])
{

    int key = 0;
    string plaintext = NULL;

    if (argc == 2 && only_digits(argv[1]))
    {
        key = atoi(argv[1]);
        plaintext = get_string("plaintext: ");

        int length = strlen(plaintext);

        printf("ciphertext: ");

        for (int i = 0; i < length; i++)
        {
            printf("%c", rotate(plaintext[i], key));
        }
        printf("\n");
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

bool only_digits(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char letter, int times)
{
    times = times % 26;

    if (isupper(letter))
    {
        return 'A' + ((letter - 'A' + times) % 26);
    }
    else if (islower(letter))
    {
        return 'a' + ((letter - 'a' + times) % 26);
    }
    else
    {
        return letter;
    }
}

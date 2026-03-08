#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float calculate_average_per_100_words(int letters, int words);

int main(void)
{
    string text = NULL;
    float S = 0;
    float L = 0;
    int letters = 0, words = 0, sentences = 0;

    text = get_string("Text: ");
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        if ((i == 0) && (isalpha(text[i])))
        {
            words++;
        }
        else
        {
            if ((isalpha(text[i]) && isblank(text[i - 1])) ||
                (isalpha(text[i]) && text[i - 1] == '!') ||
                (isalpha(text[i]) && text[i - 1] == '?') ||
                (isalpha(text[i]) && text[i - 1] == '"'))
            {
                words++;
            }
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    L = calculate_average_per_100_words(letters, words);
    S = calculate_average_per_100_words(sentences, words);

    float index = 0.0588 * L - 0.296 * S - 15.8l;
    int result = round(index);

    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", result);
    }
}

float calculate_average_per_100_words(int Dividend, int Divisor)
{
    float x;
    x = ((float) Dividend / Divisor) * 100;
    return x;
}

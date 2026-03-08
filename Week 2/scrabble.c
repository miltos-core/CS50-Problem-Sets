#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void makeUpperCase(string answer);

int calculation(string answer);

void comparison(string answer1, string answer2);

int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(void)
{
    string answer1 = " ", answer2 = " ";

    answer1 = get_string("Player 1:");
    answer2 = get_string("Player 2:");
    makeUpperCase(answer1);
    makeUpperCase(answer2);
    comparison(answer1, answer2);
}

void makeUpperCase(string answer)
{
    int length = strlen(answer);

    for (int i = 0; i < length; i++)
    {
        answer[i] = toupper(answer[i]);
    }
}

int calculation(string answer)
{
    int sum = 0;
    int length = strlen(answer);
    int alphabetLen = 26;

    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < alphabetLen; j++)
        {

            if (answer[i] == chars[j])
            {
                sum += values[j];
                break;
            }
        }
    }

    return sum;
}

void comparison(string answer1, string answer2)
{
    int points1 = calculation(answer1);
    int points2 = calculation(answer2);

    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points1 == points2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

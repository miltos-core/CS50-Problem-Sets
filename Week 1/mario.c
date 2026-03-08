#include <cs50.h>
#include <stdio.h>

int main()
{

    int height = 0;

    do
    {
        height = get_int("Choose the height of the Pyramid: ");
    }
    while (height < 0 || height == 0);

    for (int i = 0; i < height; i++)
    {

        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        printf("#");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

#include <cs50.h>
#include <stdio.h>

int calculation(int amount)
{
    int coins = 0;
    coins += amount / 25;
    amount %= 25;

    coins += amount / 10;
    amount %= 10;

    coins += amount / 5;
    amount %= 5;

    coins += amount;
    return coins;
}
int main(void)
{
    int amount = 0;

    do
    {
        amount = get_int("Change owed: ");
    }
    while (amount < 0);

    printf("%i\n", calculation(amount));
}

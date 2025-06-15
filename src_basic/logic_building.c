#include <stdio.h>

int fsqrt(int num)
{
    int n = 1;
    while ((n * n) <= num)
    {
        n++;
    }
    return n - 1;
}

int count_divisors(int val)
{
    int count = 0;

    for (int i = 1; i <= val; i++)
    {
        if ((val % i) == 0)
        {
            count++;
        }
    }
    return count;
}

void three_divisors(int val)
{
    for (int i = 1; i <= val; i++)
    {
        if (count_divisors(i) == 3)
        {
            printf(" %d", i);
        }
    }
}

int power(int a, int b)
{
    int pwr = 1;
    if (a == 1)
    {
        return pwr;
    }
    else
    {
        for (int i = 1; i <= b; i++)
        {
            pwr *= a;
        }

        return pwr;
    }
}

int kth_digit(int a, int b, int k)
{
    int pwr = power(a, b);
    int count = 0;

    while (pwr > 0 && count <= k)
    {

        int rem = pwr % 10; // get last digit
        count++;

        if (count == k)
        {
            return rem;
        }

        pwr = pwr / 10; // remove last digit
    }
}
int main()
{
    int sqrt_n = fsqrt(16);
    //printf("square root of n is %d", sqrt_n);
    three_divisors(25);
    // int pwr = power(2,5);
    //printf("kth digit in a power b is %d", kth_digit(2, 1, 1));
}

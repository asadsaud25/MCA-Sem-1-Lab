
#include <stdio.h>

int gcdR(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcdR(b, a % b);
}

int gcdNR(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int a, b, res1, res2;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    res1 = gcdR(a, b);
    res2 = gcdNR(a, b);

    printf("GCD of %d and %d is %d using recursion\n", a, b, res1);
    printf("GCD of %d and %d is %d without using recursion\n", a, b, res2);
    
	return 0;
}



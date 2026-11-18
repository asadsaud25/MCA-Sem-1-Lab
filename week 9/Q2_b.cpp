// No TRecurrsion
#include <stdio.h>
#include <math.h>

void moveDisk(int rods[3][10], int top[3],
              char names[3], int from, int to)
{
    int disk = rods[from][top[from]--];

    rods[to][++top[to]] = disk;

    printf("Move disk %d from %c to %c\n",
           disk, names[from], names[to]);
}

void tower(int n)
{
    int rods[3][10] = {0};
    int top[3] = {-1, -1, -1};
    char names[3] = {'A', 'B', 'C'};

    int totalMoves = pow(2, n) - 1;

    for (int i = n; i >= 1; i--)
        rods[0][++top[0]] = i;

    if (n % 2 == 0)
    {
        char temp = names[1];
        names[1] = names[2];
        names[2] = temp;
    }

    for (int i = 1; i <= totalMoves; i++)
    {
        int from, to;

        if (i % 3 == 1)
        {
            from = 0;
            to = 2;
        }
        else if (i % 3 == 2)
        {
            from = 0;
            to = 1;
        }
        else
        {
            from = 1;
            to = 2;
        }

        int a = from, b = to;

        if (top[a] == -1)
        {
            moveDisk(rods, top, names, b, a);
        }
        else if (top[b] == -1)
        {
            moveDisk(rods, top, names, a, b);
        }
        else if (rods[a][top[a]] < rods[b][top[b]])
        {
            moveDisk(rods, top, names, a, b);
        }
        else
        {
            moveDisk(rods, top, names, b, a);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    tower(n);

    return 0;
}


#include <stdio.h>

int Ehprimo(int x, int y)
{
    if (y == 1)
    {
        return 1;
    }
    else
    {
        if (x % y == 0)
        {
            return 0;
        }
        else
        {
            return Ehprimo(x, y - 1);
        }
    }
}

int mmc(int x, int y, int r)
{
    if (r > x)
    {
        return 1;
    }
    else if (Ehprimo(r, r - 1) == 1)
    {
        if (x % r == 0 && y % r == 0)
        {
            return r * mmc(x / r, y / r, r);
        }
        if (x % r == 0)
        {
            return r * mmc(x / r, y, r);
        }
        else if (y % r == 0)
        {
            return r * mmc(x, y / r, r);
        }
        else
        {
            return mmc(x, y, r + 1);
        }
    }
    else if (Ehprimo(r, r - 1) == 0)
    {
        return mmc(x, y, r + 1);
    }

}

int mdc(int x, int y, int r)
{
    if (r > y)
    {
        return 1;
    }
    else if (Ehprimo(r, r - 1) == 1)
    {
        if (x % r != 0 || y % r != 0)
        {
            return mdc(x, y, r + 1);
        }
        else
        {
            return r * mdc(x / r, y / r, r);
        }
    }
    else if (Ehprimo(r, r - 1) == 0)
    {
        return mdc(x, y, r + 1);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int x, y;

    if (n >= m)
    {
        x = mdc(n, m, 2);
        y = mmc(n, m, 2);
    }
    else if (n < m)
    {
        x = mdc(m, n, 2);
        y = mmc(m, n, 2);
    }

    printf("MDC(%d, %d) = %d\n", n, m, x);
    printf("MMC(%d, %d)  = %d\n", n, m, y);

    return 0;
}

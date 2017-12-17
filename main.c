#include <stdio.h>
#include <stdlib.h>

void skaityti(int *n, int ***kvdrt, int *sum);
int eilutesSuma(int *arr, int n);
int arEilutesOk(int **Kvdrt, int n, int sum);
int arStulpeliaiOk(int **Kvdrt, int n, int ktSum);
int arIstrizainesOk(int **Kvdrt, int n, int ktSum);

int main()
{
    int n = 0, sum = 0;
    int i;
    int **kvdrt;
    skaityti(&n, &kvdrt, &sum);
    if (arEilutesOk(kvdrt, n, sum) && arStulpeliaiOk(kvdrt, n, sum) && arIstrizainesOk(kvdrt, n, sum))
        printf("Jusu ivestas kvadratas - magiskas\n");
    else
        printf("Jusu ivestas kvadratas nera magiskas\n");
    for(i = 0; i < n; i++)
    {
        free(kvdrt[i]);
    }
    free(kvdrt);
    return 0;
}

void skaityti(int *n, int ***kvdrt, int *sum)
{
    int i, j;
    while(*n < 1)
    {
        printf("Iveskite teigiama sveikaji skaiciu N: ");
        scanf("%d", n);
    }
    *kvdrt = malloc(*n * sizeof(int*));
    for(i = 0; i < *n; i++)
    {
        (*kvdrt)[i] = malloc(*n * sizeof(int));
    }
    printf("Iveskite teigiamus skaicius matricai: \n");
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *n; j++)
        {
            scanf("%d", &(*kvdrt)[i][j]);
        }
        *sum += (*kvdrt)[i][0];
    }
}

int eilutesSuma(int *arr, int n)
{
    int sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int arEilutesOk(int **Kvdrt, int n, int sum)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (sum != eilutesSuma(Kvdrt[i], n))
            return 0;
    }
    return 1;
}

int arStulpeliaiOk(int **Kvdrt, int n, int ktSum)
{
    int i, j, sum;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += Kvdrt[j][i];
        }
        if (sum != ktSum)
            return 0;
    }
    return 1;
}

int arIstrizainesOk(int **Kvdrt, int n, int ktSum)
{
    int i, sum1 = 0, sum2 = 0;
    for (i = 0; i < n; i++)
    {
        sum1 += Kvdrt[i][i];
        sum2 += Kvdrt[n - 1 - i][n - 1 - i];
    }
    if (sum1 == ktSum && sum2 == ktSum)
        return 1;
    else
        return 0;
}

// Implementation of chain matrix multiplication using dynamic
// programming.

#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions of matrices:\n");
    printf("For example, for matrices 10x20, 20x30, 30x40 enter:\n");
    printf("10 20 30 40\n\n");

    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // DP table
    int m[n + 1][n + 1];

    // Cost of multiplying one matrix is zero
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // Chain length
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            m[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications = %d\n",
           m[1][n]);

    return 0;
}
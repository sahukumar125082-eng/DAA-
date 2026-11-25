#include <stdio.h>

int main() {
    int n, amount, i, j;
    int coins[20], dp[1000];

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    printf("Enter coin denominations:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter total amount: ");
    scanf("%d", &amount);

    dp[0] = 0;
    for (i = 1; i <= amount; i++) {
        dp[i] = 9999;
    }

    for (i = 1; i <= amount; i++) {
        for (j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    if (dp[amount] == 9999) {
        printf("Change cannot be made.\n");
    } else {
        printf("Minimum coins required = %d\n", dp[amount]);
    }

    return 0;
}
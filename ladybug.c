#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int len;
        scanf("%d", &len);

        int* arr1 = (int*)malloc(len * sizeof(int));
        int* arr2 = (int*)malloc(len * sizeof(int));
        char* buffer = (char*)malloc((len + 1) * sizeof(char));

        scanf("%s", buffer); 
        for (int i = 0; i < len; i++) {
            arr1[i] = buffer[i] - '0'; 
        }
        scanf("%s", buffer); 
        for (int i = 0; i < len; i++) {
            arr2[i] = buffer[i] - '0';
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                sum1 += arr1[i];
                sum2 += arr2[i];
            } else {
                sum1 += arr2[i];
                sum2 += arr1[i];
            }
        }
        if ((sum1 > len / 2) || (sum2 > (len - len / 2))) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        free(arr1);
        free(arr2);
        free(buffer);
    }
    return 0;
}
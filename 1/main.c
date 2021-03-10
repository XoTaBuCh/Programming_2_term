#include <stdio.h>
#include <stdlib.h>

#define max(x,y) ((x)>(y)?(x):(y))

int Double(char arr[]) {
    int i = 0, sum1 = 0, sum2 = 0;
    while (arr[i] != 0 && arr[i] != '.') {
      if (arr[i] < '0' || arr[i] > '9') {
          printf("Error!\n");
           return 0;
      }
      sum1 += arr[i] - '0';
      i++;
    }
    if (arr[i] != 0) {
    i++;
    }
    while (arr[i] != 0) {
           if (arr[i] < '0' || arr[i] > '9') {
            printf("Error!\n");
            return 0;
        }
        sum2 += arr[i] - 48;
        i++;
    }
    return max(sum1, sum2);
}

int main(int argc, const char * argv[]) {
    char arr[(int)1e6];
    printf("Enter a (double, length < 10^6):\n");
    scanf("%s", arr);
    printf("Max sum = %d\n", Double(arr));
    system("pause");
    return 0;
}
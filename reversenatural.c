#include <stdio.h>
int main() {
int n, i;
printf("Enter a Number : ");
scanf("%d", &n);
printf("the first %d natural numbers are:\n", n);
for (i = n; i >= 1; i--) {
printf("%d" ,i);
}
printf("\n");
return 0;
} 

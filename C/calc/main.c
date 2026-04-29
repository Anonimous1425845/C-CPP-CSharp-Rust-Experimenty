#include "tinyexpr.h"
#include <string.h>
#include <stdio.h>

int main(){
    char expression[1000];
    printf("Priklad: ");

    if (fgets(expression, sizeof(expression), stdin)) {
        // odstránenie \n
        expression[strcspn(expression, "\n")] = 0;

        int error = 0;
        double result = te_interp(expression, &error);

        if (error == 0) {
            printf("Visledok: %f\n", result);
        } else {
            // asi preklep
            printf("Chyba v príklade: %d\n", error);
        }
    }
    return 0;
}
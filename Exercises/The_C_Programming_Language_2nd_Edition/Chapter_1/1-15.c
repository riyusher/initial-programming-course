// Rewrite the temperature conversion program to use a function for conversion
#include <stdio.h>

/* Function prototype */
float fahrenheit_to_celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main() {
    float fahr;
    float lower, upper, step;
    
    lower = 0;    /* lower limit of temperature scale */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */
    fahr = lower;
    
    while (fahr <= upper) {
        printf("%3.0f %6.1f\\n", fahr, fahrenheit_to_celsius(fahr));
        fahr += step;
    }

    return 0;
}
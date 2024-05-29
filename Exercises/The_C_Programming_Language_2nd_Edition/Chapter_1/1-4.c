//Write a program to print the corresponding Celsius to Fahrenheit table
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
int main()
    {
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    celsius = lower;

    printf ("Celsius   Fahrenheit\\n");

    while (celsius <= upper) {
        fahr = (9.0/5.0 * celsius) + (32);
        printf("%3.0f°C %10.1f°F\\n", celsius, fahr);
        celsius = celsius + step;
    }
}

/*Celsius   Fahrenheit
  0°C       32.0°F
 20°C       68.0°F
 40°C      104.0°F
 60°C      140.0°F
 80°C      176.0°F
100°C      212.0°F
120°C      248.0°F
140°C      284.0°F
160°C      320.0°F
180°C      356.0°F
200°C      392.0°F
220°C      428.0°F
240°C      464.0°F
260°C      500.0°F
280°C      536.0°F
300°C      572.0°F*/
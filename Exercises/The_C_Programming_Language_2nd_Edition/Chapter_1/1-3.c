//Modify the temperature conversion program to print a heading above the table
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
    fahr = lower;

    printf ("Farenheit   Celsius\\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f°F %10.1f°C\\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/*Farenheit   Celsius
  0°F      -17.8°C
 20°F       -6.7°C
 40°F        4.4°C
 60°F       15.6°C
 80°F       26.7°C
100°F       37.8°C
120°F       48.9°C
140°F       60.0°C
160°F       71.1°C
180°F       82.2°C
200°F       93.3°C
220°F      104.4°C
240°F      115.6°C
260°F      126.7°C
280°F      137.8°C
300°F      148.9°C*/
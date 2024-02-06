#include <stdio.h>
#include <math.h>

double target = 0;

double f(double x) {
    return pow(9, x) + pow(25, x) - pow(45, x);
}

double df(double x) {
    return pow(9, x) * log(9) + pow(25, x) * log(25) - pow(45, x) * log(45);
}

int newton(double initial_value, double threshold, double epsilon, double* x, double* y, double* dy) {
    int unlimited = 0;
    *x = initial_value;
    *y = f(*x);
    *dy = df(*x);
    printf("Calculated values are x=%lf, y=%lf, dy=%lf\n", *x, *y, *dy);
    while (fabs(*y - target) > threshold && !unlimited) {
        *x = *x - *y / *dy;
        *y = f(*x);
        *dy = df(*x);
        if (fabs(*dy) < epsilon) {
            unlimited = 1;
            break;
        }
        printf("Calculated values are x=%lf, y=%lf, dy=%lf\n", *x, *y, *dy);
    }

    return unlimited;
}

int main() {
    int estimated_left = -3;
    int estimated_right = 5;

    double x, y, dy;
    for (int initial_value = estimated_left; initial_value < estimated_right; initial_value++) {
        int unlimited = newton(initial_value, 5e-324, 1e-255, &x, &y, &dy);
        if (!unlimited) {
            printf("Final calculated values are x=%lf, y=%lf, dy=%lf\n", x, y, dy);
            break;
        } else {
            printf("Wrong selection of initial value x=%d\n", initial_value);
        }
    }

    return 0;
}

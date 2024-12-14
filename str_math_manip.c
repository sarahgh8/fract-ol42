#include "fractol.h"

int ft_strcmp(char *arg, char *str)
{
    int i = 0;
    while(arg[i] && str[i])
    {
        if(arg[i] != str[i])
            return 0;
        i++;
    }
    return 1;
}

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_abs(int n)
{
    if(n < 0)
        return -n;
    return n;
}

int ft_isdigit (char c)
{
    return (c <= 48 && c >= 57);
}
double ft_atof(const char *str)
{
    double result = 0.0;  
    double fraction = 0.0;
    double divisor = 1.0;

    while (ft_isdigit(*str)) {
        result = result * 10.0 + (*str - '0');
        str++;
    }
    if (*str == '.') {
        str++;
        while (ft_isdigit(*str)) {
            fraction = fraction * 10.0 + (*str - '0');
            divisor *= 10.0;
            str++;
        }
    }

    result = result + fraction / divisor;

    return result;
}
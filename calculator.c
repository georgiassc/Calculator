#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int c)
{
    if (c == -2147483648)
	{
        write(1, "-2147483648", 11);
		return ;
	}
	if (c < 0)
	{
		ft_putchar('-');
		c = c * -1;
	}
	if (c > 9)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else
	{
		ft_putchar (c + '0');
	}
}

void    ft_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

int ft_strcmp(char *str1, char *str2)
{
    while(*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int ft_add(int a, int b)
{
    int s = a+b;
    return (s);
}

int ft_sub(int a, int b)
{
    int s = a - b;
    return (s);
}

int ft_div(int a, int b)
{
    int s = a/b;
    return (s);
}

int ft_mul(int a, int b)
{
    int s = a * b;
    return (s);
}

int main(void)
{
    int a,b;
    char c[4];
    char r;
    ft_putstr("What is the first number?");
    if(scanf("%d", &a) != 1)
    {
        ft_putstr("You entered an invalid value");
        return (0);
    }
    ft_putstr("What is the second number?");
    if(scanf("%d", &b) != 1)
    {
        ft_putstr("You entered an invalid value");
        return (0);
    }
    ft_putstr("What kind of calculator do you want to make? (Write 'add' for addition, 'sub' for subtraction, 'div' for division, or 'mul' for multiplication.");
    scanf("%3s", c);
    if(ft_strcmp(c, "add") == 0)
    {
        ft_putstr("The answer is:");
        ft_putnbr(ft_add(a,b));
        ft_putchar('\n');
    } 
    else if(ft_strcmp(c, "sub") == 0)
    {
        ft_putstr("The answer is:");
        ft_putnbr(ft_sub(a,b));
        ft_putchar('\n');
    }
    else if(ft_strcmp(c, "div") == 0)
    {
        ft_putstr("The answer is:");
        ft_putnbr(ft_div(a,b));
        ft_putchar('\n');
    }
    else if(ft_strcmp(c, "mul") == 0)
    {
        ft_putstr("The answer is:");
        ft_putnbr(ft_mul(a,b));
        ft_putchar('\n');
    }
    else
        ft_putstr("You entered an invalid calculation.");
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:49:16 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/22 15:59:55 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_putnbr(long int nbr, int base)
{
	int  n;			//OJO! int !
	char *hexa;
	char *dec;

	hexa = "0123456789abcdef";
	dec = "0123456789";

	if (nbr / base != 0)
		ft_putnbr(nbr / base, base);
	n = nbr % base;
	if (base == 16)
		write(1, &hexa[n], 1);
	if (base == 10)
        write(1, &dec[n], 1);
}

int ft_print(long int nbr, int base)
{
    int len;

    len = 0;
	if (nbr == 0) //OJO! Si es cero, print 0 y return!
	{
		len += write(1, "0", 1);
		return (len);
	}
    if (nbr < 0)
    {
        len += write(1, "-", 1);
        nbr *= -1;
    }
    ft_putnbr(nbr, base);
    while (nbr != 0)
    {
        nbr /= base;
        len++;
    }
	return (len);
}

int ft_putstr(char *str) //OJO! Si es null (null)
{
    int len;

	len = 0;
	if (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
    while (*str)
	{
		len += write(1, str, 1);
		str++;
	}
    return (len);
}

//////////////////////////////UTILS///////////////////////////////////

int ft_typeof(char type, va_list args)
{
	int len;

	len = 0;
	if (type == 's')
		len = ft_putstr(va_arg(args, char*));
	if (type == 'd')
		len = ft_print(va_arg(args, int), 10);
	if (type == 'x')
		len = ft_print(va_arg(args, unsigned int), 16);
	return (len);
}	


int ft_printf(char *str, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_typeof(*str, args);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}

/////////////////////////FUNCTIONS/////////////////////////

/*int main(void)
{
    int len;
    char *s = "Holi";
    int d = -5355;
    int x = -60;


    len = printf("Print ofi: %s, %d, %x\n", s, d, x);
    printf("len: %d\n", len);
    len = ft_printf("Print mio: %s, %d, %x\n", s, d, x);
    printf("len: %d\n", len);
    return (0);

}*/

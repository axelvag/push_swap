/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:25:09 by avaganay          #+#    #+#             */
/*   Updated: 2022/12/07 14:18:31 by avaganay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_allformat(va_list arg, char s)
{
	int	len;

	len = 0;
	if (s == 'c')
		len = ft_putcharprintf(va_arg(arg, int));
	else if (s == 's')
		len = ft_putstrprintf(va_arg(arg, char *));
	else if (s == 'p')
		len = ft_print_ptr(va_arg(arg, unsigned long long));
	else if (s == 'd' || s == 'i')
		len = ft_putnbrprintf(va_arg(arg, int));
	else if (s == 'u')
		len = ft_putnbrunsignedint(va_arg(arg, unsigned int));
	else if (s == 'x')
		len = ft_putnbr_baseprintf(va_arg(arg, int), "0123456789abcdef", &len);
	else if (s == 'X')
		len = ft_putnbr_baseprintf(va_arg(arg, int), "0123456789ABCDEF", &len);
	else if (s == '%')
		len = ft_putpourcent();
	else if (s == '\0')
		return (0);
	else
		return (write(1, &s, 1), 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, s);
	if (write(1, 0, 0) != 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + ft_allformat(arg, s[i + 1]);
			i += 2;
		}
		else
		{
			len = len + ft_putcharprintf(s[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:54:38 by avaganay          #+#    #+#             */
/*   Updated: 2022/11/23 11:48:05 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lennb(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbrprintf(int nb)
{
	int		len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putcharprintf('-');
		len = 1;
	}
	if (nb > 9)
		ft_putnbrprintf(nb / 10);
	ft_putcharprintf(nb % 10 + '0');
	len += lennb(nb);
	return (len);
}

int	ft_putnbrunsignedint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_putnbrprintf(nb / 10);
	len += ft_putcharprintf(nb % 10 + '0');
	return (len);
}

int	ft_putnbr_baseprintf(unsigned int nbr, char *base, int *len)
{
	long int	nb;

	if (nbr == 0)
	{
		ft_putcharprintf(base[0]);
		return (1);
	}
	nb = (long int)nbr;
	if (nb != 0)
	{
		if (nb / ft_strlen(base) != 0)
			ft_putnbr_baseprintf(nb / ft_strlen(base), base, len);
		ft_putcharprintf(base[nb % ft_strlen(base)]);
		(*len)++;
	}
	return (*len);
}

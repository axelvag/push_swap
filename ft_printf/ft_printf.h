/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:47 by avaganay          #+#    #+#             */
/*   Updated: 2022/11/23 11:45:45 by avaganay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

int		ft_intlen(const char *s);
int		ft_putcharprintf(int c);
int		ft_putstrprintf(char *str);
int		ft_ptrlen(uintptr_t num);
void	ft_putptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_putnbrprintf(int nb);
int		ft_putnbrunsignedint(unsigned int nb);
int		ft_putpourcent(void);
int		ft_putnbr_baseprintf(unsigned int nbr, char *base, int *len);
int		ft_allformat(va_list arg, char s);
int		ft_printf(const char *s, ...);
int		lennb(long nb);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:50:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/01/22 16:59:27 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_arg(char *str, t_opt s)
{
	size_t	i;

	if (s.opt == '-')
		ft_putstr(str);
	i = 0;
	if (s.min_size > 0 && ft_strlen(str) < s.min_size)
	{
		while (i != s.min_size - ft_strlen(str))
		{
			if (i == s.min_size - ft_strlen(str) - 1 && (s.opt == '+' || s.opt == ' '))
				ft_putchar('+');
			else if (s.opt == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}
	if (s.opt != '-')
		ft_putstr(str);
}

char	*get_arg(va_list ap, const char *arg, int i)
{
	char	*str;

	if (arg[i] == 'd')
		str = ft_itoa(va_arg(ap, int));
	if (arg[i] == 's')
		str = ft_strdup(va_arg(ap, char *));
	return (str);
}

t_opt	convert(va_list ap, const char *arg, t_opt s)
{
	char	*str;

	s.i++;
	s = is_option(arg, s);
	s = is_min_size(arg, s);
	//i += is_accurate
	//i += is_size
	str = get_arg(ap, arg, s.i);
	put_arg(str, s);
	free(str);
	return (s);
}

int		ft_printf(const char *arg, ...)
{
	t_opt	s;
	va_list	ap;

	s.i = 0;
	va_start(ap, arg);
	while (arg[s.i])
	{
		if (arg[s.i] == '%')
			s = convert(ap, arg, s);
		else
			ft_putchar(arg[s.i]);
		s.i++;
	}
	va_end(ap);
	return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 14:00:23 by ncolliau          #+#    #+#             */
/*   Updated: 2015/01/22 16:29:41 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	is_option(const char *arg, t_opt s)
{
	s.opt = '\0';
	if (arg[s.i] == '#')
		s.opt = '#';
	else if (arg[s.i] == '+')
		s.opt = '+';
	else if (arg[s.i] == '-')
		s.opt = '-';
	else if (arg[s.i] == ' ')
		s.opt = ' ';
	else if (arg[s.i] == '0')
		s.opt = '0';
	else
		return (s);
	s.i++;
	return (s);
}

t_opt	is_min_size(const char *arg, t_opt s)
{
	s.min_size = 0;
	if (ft_isdigit(arg[s.i]))
	{
		s.min_size = ft_atoi(arg + s.i);
		s.i += ft_nbrlen(s.min_size);
	}
	return (s);
}

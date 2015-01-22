/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:47:40 by ncolliau          #+#    #+#             */
/*   Updated: 2015/01/22 16:22:38 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_opt
{
	int			i;
	char		opt;
	size_t		min_size;
	int			acc;
}				t_opt;

int				ft_printf(const char *arg, ...);

t_opt				is_option(const char *arg, t_opt s);
t_opt				is_min_size(const char *arg, t_opt s);

#endif

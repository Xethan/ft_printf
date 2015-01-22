/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:57:02 by ncolliau          #+#    #+#             */
/*   Updated: 2015/01/22 16:43:23 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	char	*str;
	int		nbr;

	str = "Corobizar";
	nbr = 42;
	ft_printf("Bonjour : %028d et |%+12s| %0s %-1s !\n", nbr, str, "le", "lamasticot");
	return (0);
}
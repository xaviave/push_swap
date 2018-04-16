/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 15:03:42 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:42:11 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		sa(t_nu **pile_a, t_nu **pile_b, int aff)
{
	int	tmp;

	if ((*pile_a) && (*pile_a)->next)
	{
		tmp = (*pile_a)->number;
		(*pile_a)->number = (*pile_a)->next->number;
		(*pile_a)->next->number = tmp;
		if ((*pile_b))
			tmp = (*pile_b)->number;
		if (aff)
			ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int		sb(t_nu **pile_a, t_nu **pile_b, int aff)
{
	int	tmp;

	if ((*pile_b) && (*pile_b)->next)
	{
		tmp = (*pile_b)->number;
		(*pile_b)->number = (*pile_b)->next->number;
		(*pile_b)->next->number = tmp;
		if ((*pile_a))
			tmp = (*pile_a)->number;
		if (aff)
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int		ss(t_nu **pile_a, t_nu **pile_b, int aff)
{
	sa(pile_a, pile_b, 0);
	sb(pile_a, pile_b, 0);
	if (aff)
		ft_printf("ss\n");
	return (1);
}

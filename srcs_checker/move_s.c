/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 15:03:42 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 17:24:05 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		sa(t_nu **pile_a, t_nu **pile_b)
{
	int	tmp;

	if ((*pile_a) && (*pile_a)->next)
	{
		{
			tmp = (*pile_a)->number;
			(*pile_a)->number = (*pile_a)->next->number;
			(*pile_a)->next->number = tmp;
		}
		if ((*pile_b))
			tmp = (*pile_b)->number;
		return (1);
	}
	return (0);
}

int		sb(t_nu **pile_a, t_nu **pile_b)
{
	int	tmp;

	if ((*pile_b) && (*pile_b)->next)
	{
		{
			tmp = (*pile_b)->number;
			(*pile_b)->number = (*pile_b)->next->number;
			(*pile_b)->next->number = tmp;
		}
		if ((*pile_a))
			tmp = (*pile_a)->number;
		return (1);
	}
	return (0);
}

int		ss(t_nu **pile_a, t_nu **pile_b)
{
	sa(pile_a, pile_b);
	sb(pile_a, pile_b);
	return (1);
}

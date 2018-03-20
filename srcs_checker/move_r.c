/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_r.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:59:55 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 18:13:22 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ra(t_nu **pile_a, t_nu **pile_b)
{
	t_nu	*tmp;
	t_nu	*save;

	if (!(*pile_a) || !((*pile_a)->next))
		return (0);
	save = (*pile_a);
	tmp = (*pile_a)->next;
	while ((*pile_a)->next)
		(*pile_a) = (*pile_a)->next;
	(*pile_a)->next = save;
	save->next = NULL;
	(*pile_a) = tmp;
	if ((*pile_b))
		return (0);
	return (1);
}

int			rb(t_nu **pile_a, t_nu **pile_b)
{
	t_nu	*tmp;
	t_nu	*save;

	if (!(*pile_b) || !((*pile_b)->next))
		return (0);
	save = (*pile_b);
	tmp = (*pile_b)->next;
	while ((*pile_b)->next)
		(*pile_b) = (*pile_b)->next;
	(*pile_b)->next = save;
	save->next = NULL;
	(*pile_b) = tmp;
	if ((*pile_a))
		return (0);
	return (1);
}

int			rr(t_nu **pile_a, t_nu **pile_b)
{
	ra(pile_a, pile_b);
	rb(pile_a, pile_b);
	return (1);
}

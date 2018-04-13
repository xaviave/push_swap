/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_r.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:59:55 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 11:39:57 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ra(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	t_nu	*tmp;
	t_nu	*save;

	if (!(*pile_a) || !((*pile_a)->next))
		return (0);
	if (graph && graph->aff)
		visu(graph, pile_a, pile_b, "ra");
	save = (*pile_a);
	tmp = (*pile_a)->next;
	while ((*pile_a)->next)
		(*pile_a) = (*pile_a)->next;
	(*pile_a)->next = save;
	save->next = NULL;
	(*pile_a) = tmp;
	if (aff)
		ft_printf("ra\n");
	if ((*pile_b))
		return (0);
	return (1);
}

int			rb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	t_nu	*tmp;
	t_nu	*save;

	if (!(*pile_b) || !((*pile_b)->next))
		return (0);
	if (graph && graph->aff)
		visu(graph, pile_a, pile_b, "rb");
	save = (*pile_b);
	tmp = (*pile_b)->next;
	while ((*pile_b)->next)
		(*pile_b) = (*pile_b)->next;
	(*pile_b)->next = save;
	save->next = NULL;
	(*pile_b) = tmp;
	if (aff)
		ft_printf("rb\n");
	if ((*pile_a))
		return (0);
	return (1);
}

int			rr(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	ra(pile_a, pile_b, 0, graph);
	rb(pile_a, pile_b, 0, graph);
	if (aff)
		ft_printf("rr\n");
	return (1);
}

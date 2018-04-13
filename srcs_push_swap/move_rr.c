/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_rr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 15:02:28 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 11:40:37 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rra(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	t_nu	*tmp;
	t_nu	*save;

	if (!(*pile_a) || !(*pile_a)->next)
		return (0);
	if (graph && graph->aff)
		visu(graph, pile_a, pile_b, "rra");
	tmp = (*pile_a);
	while ((*pile_a)->next->next)
		(*pile_a) = (*pile_a)->next;
	save = (*pile_a)->next;
	save->next = tmp;
	(*pile_a)->next = NULL;
	(*pile_a) = save;
	if (aff)
		ft_printf("rra\n");
	if (!(*pile_b))
		return (0);
	return (1);
}

int			rrb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	t_nu	*tmp;
	t_nu	*save;

	if (!(*pile_b) || !(*pile_b)->next)
		return (0);
	if (graph && graph->aff)
		visu(graph, pile_a, pile_b, "rrb");
	tmp = (*pile_b);
	while ((*pile_b)->next->next)
		(*pile_b) = (*pile_b)->next;
	save = (*pile_b)->next;
	save->next = tmp;
	(*pile_b)->next = NULL;
	(*pile_b) = save;
	if (aff)
		ft_printf("rrb\n");
	if (!(*pile_a))
		return (0);
	return (1);
}

int			rrr(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	rra(pile_a, pile_b, 0, graph);
	rrb(pile_a, pile_b, 0, graph);
	if (aff)
		ft_printf("rrr\n");
	return (1);
}

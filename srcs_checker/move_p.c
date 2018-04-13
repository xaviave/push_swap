/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_p.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:58:24 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 11:39:45 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			pa(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	t_nu	*test;
	t_nu	*tmp;

	if (!(*pile_b))
		return (0);
	if (graph && graph->aff)
		visu(graph, pile_a, pile_b, "pa");
	test = *pile_a;
	tmp = *pile_b;
	*pile_a = *pile_b;
	*pile_b = tmp->next;
	tmp->next = test;
	if (aff)
		ft_printf("pa\n");
	return (1);
}

int			pb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph)
{
	t_nu	*test;
	t_nu	*tmp;

	if (!(*pile_a))
		return (0);
	if (graph && graph->aff)
		visu(graph, pile_a, pile_b, "pb");
	test = *pile_b;
	tmp = *pile_a;
	*pile_b = *pile_a;
	*pile_a = tmp->next;
	tmp->next = test;
	if (aff)
		ft_printf("pb\n");
	return (1);
}

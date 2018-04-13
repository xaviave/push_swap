/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 16:31:23 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 12:55:01 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int ac, char **av)
{
	t_mem		graph;
	t_nu		*pile_a;

	if (!parse_checker(ac - 1, av, &pile_a, &graph))
		return (0);
	if (graph.aff > 0)
		init_visu(&graph, &pile_a);
	apply_checker(pile_a, &graph);
}

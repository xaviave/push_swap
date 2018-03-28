/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_push_swap.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 13:28:15 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 10:41:56 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	t_nu	*pile_a;
	t_nu	*pile_b;

	pile_b = NULL;
	if (!parse_push_swap(ac - 1, av, &pile_a))
		return (0);
	color("parse ok", 0);
	apply_push_swap(pile_a, pile_b);
	return (0);
}

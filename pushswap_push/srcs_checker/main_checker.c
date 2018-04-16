/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 16:31:23 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:40:51 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int ac, char **av)
{
	t_nu		*pile_a;

	if (!parse_checker(ac - 1, av, &pile_a))
		return (0);
	apply_checker(pile_a);
}

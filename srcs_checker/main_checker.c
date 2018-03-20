/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 16:31:23 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 17:41:31 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				color(char *str, int color)
{
	if (!color)
		ft_putstr(RED);
	if (color == 1)
		ft_putstr(BLUE);
	if (color == 2)
		ft_putstr(YEL);
	if (color == 3)
		ft_putstr(GRN);
	ft_putendl(str);
	ft_putstr(RESET);
	return (0);
}

int				main(int ac, char **av)
{
	t_nu		*pile_a;

	if (!parse_checker(ac - 1, av, &pile_a))
		return (0);
	apply_checker(pile_a);
}

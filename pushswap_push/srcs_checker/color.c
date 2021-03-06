/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:38:41 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:42:37 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		color(char *str, int color)
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

void	free_tab(char **tab_nu)
{
	int i;

	i = 0;
	while (tab_nu[i])
	{
		ft_strdel(&tab_nu[i]);
		i++;
	}
	free(tab_nu);
}

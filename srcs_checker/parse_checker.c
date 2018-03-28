/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_checker.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 11:47:54 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 16:02:58 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 0 && (str[i] == '-' || str[i] == '+'))
		return (0);
	return (1);
}

static int	check_double(int *tab, int max)
{
	int		i;
	int		j;
	int		*save;

	i = -1;
	if (!(save = (int *)malloc(sizeof(int) * max)))
		return (0);
	while (++i < max)
	{
		j = -1;
		while (++j < i)
			if (tab[i] == tab[j])
			{
				free(save);
				return (0);
			}
	}
	free(save);
	return (1);
}

int			parse_checker(int ac, char **av, t_nu **pile_a)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	if (!ac)
		return (color("Usage", 2));
	if (!(tab = (int *)malloc(sizeof(int) * ac)))
		return (color("Error", 0));
	while (++i <= ac)
	{
		if (!check_arg(av[i]))
			return (color("Error", 0));
		tab[j] = ft_atoi(av[i]);
		j++;
	}
	if (!check_double(tab, j))
		return (color("Error", 0));
	if (!((*pile_a) = new_list(j, tab)))
		return (color("Error", 0));
	free(tab);
	return (1);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_checker.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 11:31:59 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 11:50:02 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_graph(char *str, t_mem *graph)
{
	if (!ft_strcmp(str, "-g"))
	{
		graph->aff = 1;
		return (1);
	}
	else if (!ft_strcmp(str, "-sg"))
	{
		graph->aff = 2;
		return (1);
	}
	graph->aff = 0;
	return (0);
}

static int	check_move(char **move)
{
	int		i;

	i = 0;
	while (move[i])
	{
		if (!ft_strcmp("sa", move[i]) || !ft_strcmp("sb", move[i])
				|| !ft_strcmp("ss", move[i]) || !ft_strcmp("pa", move[i])
				|| !ft_strcmp("pb", move[i]) || !ft_strcmp("ra", move[i])
				|| !ft_strcmp("rb", move[i]) || !ft_strcmp("rr", move[i])
				|| !ft_strcmp("rrb", move[i]) || !ft_strcmp("rra", move[i])
				|| !ft_strcmp("rrr", move[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_well(t_nu **pile_a, t_nu **pile_b)
{
	t_nu	*tmp_a;
	t_nu	*tmp_b;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	if (tmp_b)
		return (color("KO", 1));
	while (tmp_a->next)
	{
		if (tmp_a->number >= (tmp_a)->next->number)
			return (color("KO", 1));
		tmp_a = tmp_a->next;
	}
	return (color("OK", 3));
}

static void	apply_move(char **move, t_nu *pile_a, t_mem *graph)
{
	int		i;
	int		j;
	t_nu	*pile_b;
	t_move	*move_struct;

	i = -1;
	init_move(&move_struct);
	pile_b = NULL;
	while (move[++i])
	{
		j = -1;
		while (++j < 11)
		{
			if (!ft_strcmp(move[i], move_struct[j].str))
			{
				move_struct[j].f(&pile_a, &pile_b, 0, graph);
				break ;
			}
		}
	}
	check_well(&pile_a, &pile_b);
	free_move(&move_struct);
	free_list(pile_b);
	free_list(pile_a);
}

void		apply_checker(t_nu *pile_a, t_mem *graph)
{
	char	*line;
	char	*file;
	char	**move;

	file = ft_strdup("");
	while (ft_gnl(0, &line) > 0)
	{
		file = ft_strjoinf1(file, line);
		file = ft_strjoinf1(file, "/");
		ft_strdel(&line);
	}
	move = ft_strsplit(file, '/');
	ft_strdel(&file);
	if (check_move(move))
		apply_move(move, pile_a, graph);
	else
		color("Error", 0);
	free_tab(move);
}

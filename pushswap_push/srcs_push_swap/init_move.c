/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_move.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:36:31 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:44:59 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_move	new_move(char *str, int (*f)(t_nu **pile_a,
			t_nu **pile_b, int aff))
{
	t_move		new;

	new.str = ft_strdup(str);
	new.f = f;
	return (new);
}

void			init_move(t_move **move)
{
	if (!((*move) = (t_move *)malloc(sizeof(t_move) * 11)))
		return ;
	(*move)[0] = new_move("sa", &sa);
	(*move)[1] = new_move("sb", &sb);
	(*move)[2] = new_move("ss", &ss);
	(*move)[3] = new_move("pa", &pa);
	(*move)[4] = new_move("pb", &pb);
	(*move)[5] = new_move("ra", &ra);
	(*move)[6] = new_move("rb", &rb);
	(*move)[7] = new_move("rr", &rr);
	(*move)[8] = new_move("rra", &rra);
	(*move)[9] = new_move("rrb", &rrb);
	(*move)[10] = new_move("rrr", &rrr);
}

void			free_move(t_move **move)
{
	int			i;

	i = 0;
	while (i < 11)
	{
		free((*move)[i].str);
		i++;
	}
	free(*move);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   genius_insert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 17:17:49 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:44:39 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	where_insert_next(int i, int len, t_nu **b)
{
	int		max;
	t_nu	*tmp;

	if (i == len + 1)
	{
		max = get_elem_max(b);
		tmp = *b;
		i = 0;
		while (tmp->number != max)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int			where_insert(t_nu **b, int value)
{
	t_nu		*tmp;
	int			i;
	t_nu		*last;
	int			len;

	if ((len = len_pile(b)) < 2)
		return (0);
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp->next = *b;
	i = 0;
	while (!(tmp->number > value && tmp->next->number < value) && i <= len)
	{
		i++;
		tmp = tmp->next;
	}
	last->next = NULL;
	return (where_insert_next(i, len, b));
}

void		one_insert(t_nu **a, t_nu **b)
{
	t_nu		*tmp;
	int			pos_in_a;
	int			pos_in_b;
	int			min;
	int			save[2];

	pos_in_a = 0;
	min = -1;
	tmp = *a;
	while (tmp)
	{
		pos_in_b = where_insert(b, tmp->number);
		if (min == -1 || min > how_many(a, b, pos_in_a, pos_in_b))
		{
			save[0] = pos_in_a;
			save[1] = pos_in_b;
			min = how_many(a, b, pos_in_a, pos_in_b);
		}
		tmp = tmp->next;
		pos_in_a++;
	}
	do_insert(a, b, save[0], save[1]);
}

static void	genius_sort(t_nu **a, t_nu **b, int move, int len)
{
	if (move > len / 2)
	{
		move = len - move;
		while (move-- > 0)
			rrb(a, b, 1);
	}
	else
		while (move-- > 0)
			rb(a, b, 1);
	len = len_pile(b);
	while (len)
	{
		pa(a, b, 1);
		len--;
	}
}

void		genius_insert(t_nu **a, t_nu **b)
{
	int		len;
	int		move;
	t_nu	*tmp;

	move = 0;
	len = len_pile(a);
	while (len)
	{
		one_insert(a, b);
		len--;
	}
	tmp = *b;
	while (tmp->number != get_elem_max(b))
	{
		tmp = tmp->next;
		move++;
	}
	len = len_pile(b);
	genius_sort(a, b, move, len);
}

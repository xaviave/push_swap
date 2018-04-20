/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simplesort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 13:17:15 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 18:18:20 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	size_calc(t_nu **pile, int move, int *i)
{
	int		size;

	size = len_pile(pile);
	if (move)
		size /= 2;
	*i = -1;
	return (size);
}

static void	do_move(int move, t_nu **pile_a, t_nu **pile_b)
{
	int		i;
	int		m;
	int		size;

	m = 1;
	size = size_calc(pile_a, 0, &i);
	if (move == 1)
	{
		sa(pile_a, pile_b, 1);
		return ;
	}
	if (move > size / 2 - 1)
	{
		m = 0;
		move = size - move;
	}
	while (++i < move)
	{
		if (!m)
			rra(pile_a, pile_b, 1);
		else
			ra(pile_a, pile_b, 1);
	}
}

void		sort_a(t_nu **pile_a, t_nu **pile_b, int *tab)
{
	int		j;
	int		size;
	t_nu	*tmp;

	size = size_calc(pile_a, 0, &j);
	while (size >= 0)
	{
		j = 0;
		tmp = *pile_a;
		while (tmp)
		{
			if (tab[size] == tmp->number)
			{
				do_move(j, pile_a, pile_b);
				break ;
			}
			j++;
			tmp = tmp->next;
		}
		if (size - 1 >= 0 && tab[size - 1] == (*pile_a)->next->number)
			sa(pile_a, pile_b, 1);
		size--;
	}
}

static void	sort_pile(t_nu **pile_a, t_nu **pile_b, int *tab)
{
	int		i;
	int		j;
	int		size;
	t_nu	*tmp;

	size = size_calc(pile_a, 1, &i);
	while (++i < size)
	{
		j = 0;
		tmp = *pile_a;
		while (tmp)
		{
			if (tab[i] == tmp->number)
			{
				do_move(j, pile_a, pile_b);
				pb(pile_a, pile_b, 1);
				break ;
			}
			j++;
			tmp = tmp->next;
		}
	}
}

void		ft_simplesort(t_nu **pile_a, t_nu **pile_b, int *tab)
{
	int		size;

	size = len_pile(pile_a);
	sort_pile(pile_a, pile_b, tab);
	sort_a(pile_a, pile_b, &(tab[size / 2]));
	while (*pile_b)
		pa(pile_a, pile_b, 1);
}

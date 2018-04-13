/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_push_swap.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:58:36 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 11:41:03 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*follow_the_bubble(int *tab, int size)
{
	int		i;
	int		j;
	int		s;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				s = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = s;
			}
		}
	}
	return (tab);
}

static int	*shitty_bubblesort(t_nu *pile_a, int size)
{
	int		i;
	int		*tab;
	t_nu	*tmp_a;

	i = -1;
	tmp_a = pile_a;
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (++i < size)
	{
		tab[i] = tmp_a->number;
		tmp_a = tmp_a->next;
	}
	return (follow_the_bubble(tab, size));
}

int			check_sort(t_nu **pile_a, t_nu **pile_b)
{
	t_nu	*tmp_a;

	tmp_a = *pile_a;
	if (*pile_b)
		return (1);
	while (tmp_a && tmp_a->next)
	{
		if (tmp_a->number > tmp_a->next->number)
			return (1);
		tmp_a = tmp_a->next;
	}
	return (0);
}

int			get_elem_max(t_nu **pile)
{
	int		max;
	t_nu	*tmp;

	tmp = *pile;
	max = tmp->number;
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

void		apply_push_swap(t_nu *pile_a, t_nu *pile_b)
{
	int		size;
	int		*tab;

	size = len_pile(&pile_a);
	if (size == 1 || !size)
		return ;
	tab = shitty_bubblesort(pile_a, size);
	if (!check_sort(&pile_a, &pile_b))
	{
		free_list(pile_a);
		return ;
	}
	if (size < 6)
		ft_simplesort(&pile_a, &pile_b, tab);
	else
		genius_insert(&pile_a, &pile_b);
	free(tab);
	free_list(pile_a);
	free_list(pile_b);
}

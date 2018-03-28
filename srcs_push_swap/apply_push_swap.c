/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_push_swap.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:58:36 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 16:44:24 by xamartin    ###    #+. /#+    ###.fr     */
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

void		apply_push_swap(t_nu *pile_a, t_nu *pile_b)
{
	int		size;
	int		*tab;
	t_nu	*tmp_a;

	size = 0;
	tmp_a = pile_a;
	while (tmp_a)
	{
		size++;
		tmp_a = tmp_a->next;
	}
	if (size == 1 || !size)
		return ;
	tab = shitty_bubblesort(pile_a, size);
	ft_simplesort(&pile_a, &pile_b, size, tab);
	//ft_mergesort(&pile_a, &pile_b, size);
	//ft_quicksort(&pile_a, &pile_b, size);
	if (!check_sort(&pile_a, &pile_b))
		ft_printf("normally, it's sort!\n");
	else
		ft_printf("not sort!\n");
}

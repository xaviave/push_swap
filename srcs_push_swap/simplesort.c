/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   simplesort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 13:17:15 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 17:42:06 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void aff(t_nu **pile_a, t_nu **pile_b)
{
	t_nu	*tmp_a;
	t_nu	*tmp_b;
	int	a;
	int	b;

	a = 0;
	b = 0;
	tmp_a = *pile_a;
	tmp_b = *pile_b;
	if (tmp_a)
		a = 1;
	if (tmp_b)
		b = 1;
	ft_printf("pile a\t\tpile b\n------------------------\n");
	while (tmp_a || tmp_b)
	{
		if (a && b)
			ft_printf("%i\t\t%i\n", tmp_a->number, tmp_b->number);
		else if (a)
			ft_printf("%i\n", tmp_a->number);
		else if (b)
			ft_printf("\t\t%i\n", tmp_b->number);
		if ((tmp_a && tmp_a->next) && (tmp_b && tmp_b->next))
		{
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_a->next)
		{
			tmp_a = tmp_a->next;
			b = 0;
		}
		else if (tmp_b && tmp_b->next)
		{
			tmp_b = tmp_b->next;
			a = 0;
		}
		else
			break ;
	}
	ft_printf("------------------------\n");
}


/**/


static void	do_move_ra(int size, int move, t_nu **pile_a, t_nu **pile_b)
{
	int		i;
	int		m;

	i = -1;
	m = 1;
	if (move > size / 2 + 1)
	{
		m = 0;
		move = size - move;
		ft_printf("\n\nmove = %i et rra\n\n\n", move);
	}
	else
		ft_printf("\n\nmove = %i et ra\n\n\n", move);
	while (++i < move)
	{
		if (!m)
			rra(pile_a, pile_b, 0);
		else
			ra(pile_a, pile_b, 0);
	}

}

void		ft_simplesort(t_nu **pile_a, t_nu **pile_b, int size, int *tab)
{
	int		i;
	int		j;
	t_nu	*tmp_a;
	t_nu	*tmp_b;

	i = -1;
	j = 0;
	tmp_a = *pile_a;
	tmp_b = *pile_b;
	ft_printf("debut du tri\n");
	aff(pile_a, pile_b);
	while (++i < size)
		ft_printf("%i index = %i | ", tab[i], i);
	i = -1;
	while (++i < size / 2 + 1)
	{
		tmp_a = *pile_a;
		j = 0;
		while (tmp_a)
		{
			if (tab[i] == tmp_a->number)
			{
				do_move_ra(size, j, pile_a, pile_b);
				pb(pile_a, pile_b, 0);
				aff(pile_a, pile_b);
				break ;
			}
			j++;
			tmp_a = tmp_a->next;	
		}
	}
	ft_printf("fin du tri\n");
	aff(pile_a, pile_b);
}

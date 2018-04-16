/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   genius_insert2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:27:06 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:44:48 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_insert_1(t_nu **a, t_nu **b, int *dist_a, int *dist_b)
{
	int		max;

	max = (*dist_a) > (*dist_b) ? (*dist_a) : (*dist_b);
	while (max)
	{
		if (*dist_a && *dist_b)
		{
			rr(a, b, 1);
			(*dist_a)--;
			(*dist_b)--;
		}
		else if (*dist_a)
			ra(a, b, 1);
		else if (*dist_b)
			rb(a, b, 1);
		max--;
	}
}

static void	do_insert_2(t_nu **a, t_nu **b, int *dist_a, int *dist_b)
{
	int		max;

	max = (*dist_a) < (*dist_b) ? -(*dist_a) : -(*dist_b);
	while (max)
	{
		if (*dist_a && *dist_b)
		{
			rrr(a, b, 1);
			(*dist_a)++;
			(*dist_b)++;
		}
		else if (*dist_a)
			rra(a, b, 1);
		else if (*dist_b)
			rrb(a, b, 1);
		max--;
	}
}

static void	do_insert_3(t_nu **a, t_nu **b, int *dist_a, int *dist_b)
{
	while (*dist_a)
	{
		(*dist_a) > 0 ? ra(a, b, 1) : rra(a, b, 1);
		(*dist_a) > 0 ? (*dist_a)-- : (*dist_a)++;
	}
	while (*dist_b)
	{
		(*dist_b) > 0 ? rb(a, b, 1) : rrb(a, b, 1);
		(*dist_b) > 0 ? (*dist_b)-- : (*dist_b)++;
	}
}

int			do_insert(t_nu **a, t_nu **b, int pos_in_a, int pos_in_b)
{
	int		dist_a;
	int		dist_b;

	dist_a = pos_in_a > len_pile(a) / 2 ? pos_in_a - len_pile(a) : pos_in_a;
	dist_b = pos_in_b > len_pile(b) / 2 ? pos_in_b - len_pile(b) : pos_in_b;
	if (dist_a >= 0 && dist_b >= 0)
		do_insert_1(a, b, &dist_a, &dist_b);
	else if (dist_a < 0 && dist_b < 0)
		do_insert_2(a, b, &dist_a, &dist_b);
	else
		do_insert_3(a, b, &dist_a, &dist_b);
	pb(a, b, 1);
	return (dist_a > dist_b ? dist_a : dist_b);
}

int			how_many(t_nu **a, t_nu **b, int pos_in_a, int pos_in_b)
{
	int		dist_a;
	int		dist_b;
	int		ret;

	dist_a = pos_in_a > len_pile(a) / 2 ? pos_in_a - len_pile(a) : pos_in_a;
	dist_b = pos_in_b > len_pile(b) / 2 ? pos_in_b - len_pile(b) : pos_in_b;
	if (dist_a >= 0 && dist_b >= 0)
		ret = dist_a > dist_b ? dist_a : dist_b;
	else if (dist_a < 0 && dist_b < 0)
		ret = dist_a < dist_b ? -dist_a : -dist_b;
	else
	{
		dist_a = dist_a > 0 ? dist_a : -dist_a;
		dist_b = dist_b > 0 ? dist_b : -dist_b;
		ret = dist_a + dist_b;
	}
	return (ret);
}

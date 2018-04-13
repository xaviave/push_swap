/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 17:48:35 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 11:39:24 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_nu		*create_list(int nu)
{
	t_nu	*lst;

	if (!(lst = malloc(sizeof(t_nu))))
		return (NULL);
	lst->number = nu;
	lst->next = NULL;
	return (lst);
}

t_nu		*new_list(int max, int *tab)
{
	int		i;
	t_nu	*lst;
	t_nu	*first;

	i = 0;
	if (!(first = create_list(tab[i])))
		return (NULL);
	lst = first;
	while (++i < max)
	{
		if (!(lst->next = create_list(tab[i])))
			return (NULL);
		lst = lst->next;
	}
	return (first);
}

void		free_list(t_nu *list)
{
	t_nu	*tmp1;
	t_nu	*tmp2;

	tmp1 = list;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	list = NULL;
}

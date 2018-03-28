/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 13:26:59 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 16:30:54 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_nu
{
	int				number;
	struct s_nu		*next;
}					t_nu;

typedef struct		s_move
{
	char			*str;
	int				(*f)(t_nu **pile_a, t_nu **pile_b, int aff);
}					t_move;

int					color(char *str, int color);
t_nu				*new_list(int max, int *tab);
t_nu				*create_list(int nu);
void				free_list(t_nu *list);
void				init_move(t_move **move);
void				free_move(t_move **move);

void aff(t_nu **pile_a, t_nu **pile_b);

/*
** Possible moves
*/

int					sa(t_nu **pile_a, t_nu **pile_b, int aff);
int					sb(t_nu **pile_a, t_nu **pile_b, int aff);
int					ss(t_nu **pile_a, t_nu **pile_b, int aff);
int					pa(t_nu **pile_a, t_nu **pile_b, int aff);
int					pb(t_nu **pile_a, t_nu **pile_b, int aff);
int					ra(t_nu **pile_a, t_nu **pile_b, int aff);
int					rb(t_nu **pile_a, t_nu **pile_b, int aff);
int					rr(t_nu **pile_a, t_nu **pile_b, int aff);
int					rra(t_nu **pile_a, t_nu **pile_b, int aff);
int					rrb(t_nu **pile_a, t_nu **pile_b, int aff);
int					rrr(t_nu **pile_a, t_nu **pile_b, int aff);

/*
** Checker files
*/

int					parse_checker(int ac, char **av, t_nu **pile_a);
void				apply_checker(t_nu *pile_a);

/*
** Push swap files
*/

int					parse_push_swap(int ac, char **av, t_nu **pile_a);
void				apply_push_swap(t_nu *pile_a, t_nu *pile_b);
void				ft_simplesort(t_nu **pile_a, t_nu **pile_b, int size, int *tab);
void				ft_mergesort(t_nu **pile_a, t_nu **pile_b, int size);
void				ft_quicksort(t_nu **pile_a, t_nu **pile_b, int size);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 13:26:59 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 15:12:43 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
#include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_nu
{
	int				number;
	struct s_nu		*next;
}					t_nu;

typedef struct		s_move
{
	char			*str;
	int				(*f)(t_nu **pile_a, t_nu **pile_b);
}					t_move;

int					color(char *str, int color);
t_nu				*new_list(int max, int *tab);
t_nu				*create_list(int nu);
void				free_list(t_nu *list);
void				init_move(t_move **move);
void				free_move(t_move **move);
void				aff(t_nu *pile_a, t_nu *pile_b);

/*
** Possibke moves
*/

int					sa(t_nu **pile_a, t_nu **pile_b);
int					sb(t_nu **pile_a, t_nu **pile_b);
int					ss(t_nu **pile_a, t_nu **pile_b);
int					pa(t_nu **pile_a, t_nu **pile_b);
int					pb(t_nu **pile_a, t_nu **pile_b);
int					ra(t_nu **pile_a, t_nu **pile_b);
int					rb(t_nu **pile_a, t_nu **pile_b);
int					rr(t_nu **pile_a, t_nu **pile_b);
int					rra(t_nu **pile_a, t_nu **pile_b);
int					rrb(t_nu **pile_a, t_nu **pile_b);
int					rrr(t_nu **pile_a, t_nu **pile_b);

/*
** Checker files
*/

int					parse_checker(int ac, char **av, t_nu **pile_a);
void				apply_checker(t_nu *pile_a);

#endif

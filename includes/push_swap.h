/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 13:26:59 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 16:00:58 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_nu
{
	int				number;
	struct s_nu		*next;
}					t_nu;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mem
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				heigth;
	int				speed;
	int				pause;
	int				aff;
	t_img			img;
	t_img			background[1];
}					t_mem;

typedef struct		s_move
{
	char			*str;
	int				(*f)(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
}					t_move;

int					color(char *str, int color);
t_nu				*new_list(int max, int *tab);
t_nu				*create_list(int nu);
void				free_list(t_nu *list);
void				free_tab(char **tab_nu);
void				init_move(t_move **move);
void				free_move(t_move **move);

/*
 ** Possible moves
 */

int					sa(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					sb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					ss(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					pa(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					pb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					ra(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					rb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					rr(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					rra(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					rrb(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);
int					rrr(t_nu **pile_a, t_nu **pile_b, int aff, t_mem *graph);

/*
 ** Checker files
 */

int					check_graph(char *str, t_mem *graph);
int					parse_checker(int ac, char **av, t_nu **pile_a, t_mem *graph);
void				apply_checker(t_nu *pile_a, t_mem *graph);
void				init_visu(t_mem *graph, t_nu **pile_a);
void				visu(t_mem *graph, t_nu **pile_a, t_nu **pile_b, char *move);

/*
 ** Push swap files
 */

int					len_pile(t_nu **pile);
int					get_elem_max(t_nu **pile);
int					parse_push_swap(int ac, char **av, t_nu **pile_a);
int					how_many(t_nu **a, t_nu **b, int pos_in_a, int pos_in_b);
int					do_insert(t_nu **a, t_nu **b, int pos_in_a, int pos_in_b);
void				genius_insert(t_nu **a, t_nu **b);
void				apply_push_swap(t_nu *pile_a, t_nu *pile_b);
void				ft_simplesort(t_nu **pile_a, t_nu **pile_b, int *tab);

#endif

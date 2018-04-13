/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 19:02:53 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 16:47:46 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_create_xpm_to_img(void *mlx_ptr, t_img *background, char *str)
{
	int		i;
	int		j;

	i = 1220;
	j = 610;
	background->ptr = mlx_xpm_file_to_image(mlx_ptr, str, &i, &j);
	background->data = mlx_get_data_addr(background->ptr,
			&background->bpp, &background->sizeline,
			&background->endian);
}

void		visu(t_mem *graph, t_nu **pile_a, t_nu **pile_b, char *move)
{
	ft_create_xpm_to_img(graph->mlx_ptr, &graph->background[0], "background/gramophone-vinyl.xpm");
	mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, graph->background[0].ptr, 0, 0);
	if (graph || pile_a || pile_b || move)
		return ;
}

void		init_visu(t_mem *graph, t_nu **pile_a)
{
	graph->width = 1220;
	graph->heigth = 660;
	graph->speed = 1;
	graph->pause = (graph->aff == 2) ? 1 : 0;
	graph->mlx_ptr = mlx_init();
	graph->win_ptr = mlx_new_window(graph->mlx_ptr, graph->width,
			graph->heigth, "push_scratch");
	visu(graph, pile_a, NULL, NULL);
	mlx_loop(graph->mlx_ptr);
	if (pile_a)
		return ;
}

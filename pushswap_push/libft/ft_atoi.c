/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:30:27 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 17:57:16 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi(const char *nptr)
{
	size_t	i;
	char	n;
	long	out;

	i = 0;
	out = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		n = nptr[i++];
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = out * 10 + nptr[i] - 48;
		i++;
	}
	if (n == '-')
		out = -out;
	return (out);
}

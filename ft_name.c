/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:54:18 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/03 20:11:45 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_name_map(char *argv)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(argv) - 1;
	if (argv[k] == 'r')
		i++;
	if (argv[k - 1] == 'e')
		i++;
	if (argv[k - 2] == 'b')
		i++;
	if (argv[k - 3] == '.')
		i++;
	if (i != 4)
	{
		write(1, "Erorr'\n Wrong File\n", 18);
		exit (0);
	}
	return (1);
}

void	ft_close_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->game_map.array[i])
	{
		free(game->game_map.array[i]);
		i++;
	}
	exit (0);
}

void	ft_close(char **game)
{
	int	i;

	i = 0;
	while (game[i])
	{
		free(game[i]);
		i++;
	}
	exit (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:27:26 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/04 16:31:54 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_rectangle(char **game, int height)
{
	int		i;
	int		width;

	width = ft_strlen_map(game[0]);
	i = 0;
	while (i < height)
	{
		if (ft_strlen_map(game[i]) != width)
		{	
			ft_errors(2);
			exit (0);
		}
		i++;
	}
	return (1);
}

int	ft_valid_wall(char **game, int height, int k)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	k = 0;
	width = ft_strlen_map(game[0]);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game[i][j] != '1' && i == 0)
				k = 3;
			else if (game[i][j] != '1' && (j == 0 || j == (width - 1)))
				k = 3;
			else if (game[i][j] != '1' && i == (height - 1))
				k = 3;
			j++;
		}
		i++;
	}
	if (ft_errors(k) == 0)
		ft_close(game);
	return (1);
}

int	ft_valid_tile(t_game *game)
{
	if (game->game_map.player != 1 || game->game_map.exit < 1
		|| game->game_map.coin < 1)
	{
		write(1, "Error\n Wrong character", 23);
	}
	ft_for_enemy(game);
	return (1);
}

int	ft_valid_character(t_game *game, int i, int j)
{
	i = 0;
	game->game_map.width = ft_strlen_map(game->game_map.array[0]);
	while (i < game->game_map.height)
	{
		j = 0;
		while (j < game->game_map.width)
		{
			if (game->game_map.array[i][j] != 'W' && game->game_map.array[i][j]
				!= 'V' && game->game_map.array[i][j] != '1' &&
					game->game_map.array[i][j] != 'E' &&
					game->game_map.array[i][j] != '0' && game->game_map.array[i]
						[j] != 'C' && game->game_map.array[i][j] != 'P')
			{
				write(1, "Error\n WRONG MAP", 17);
				ft_close_game(game);
			}
			j++;
		}
		i++;
	}
	i = ft_valid_tile(game);
	return (i);
}

int	ft_valid_count_tile(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->game_map.exit = 0;
	game->game_map.coin = 0;
	game->game_map.player = 0;
	game->game_map.width = ft_strlen(game->game_map.array[0]);
	while (i < game->game_map.height)
	{
		j = 0;
		while (j < game->game_map.width)
		{	
			if (game->game_map.array[i][j] == 'P')
				ft_check_pos(game, i, j);
			else if (game->game_map.array[i][j] == 'C')
				game->game_map.coin++;
			else if (game->game_map.array[i][j] == 'E')
				game->game_map.exit++;
			j++;
		}
		i++;
	}
	i = ft_valid_character(game, i, j);
	return (i);
}

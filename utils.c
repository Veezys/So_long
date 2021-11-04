/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:45:44 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/04 16:29:54 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_errors(int num)
{
	char	*str;
	int		i;

	i = 0;
	str = (NULL);
	if (num == 2)
		str = "Error\n NET BLINA, KRUG";
	else if (num == 3)
		str = "Error\n Dirka v karte";
	else
		return (1);
	ft_putstr(str);
	return (0);
}

int	ft_strlen_map(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_load_img(t_game *game)
{
	game->size = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->game_map.width * game->size,
			game->game_map.height * game->size, "so_long");
	game->images.wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&game->size, &game->size);
	game->images.chrono = mlx_xpm_file_to_image(game->mlx, "img/chrono.xpm",
			&game->size, &game->size);
	game->images.player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			&game->size, &game->size);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
			&game->size, &game->size);
	game->images.coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm",
			&game->size, &game->size);
	game->images.enemy = mlx_xpm_file_to_image(game->mlx, "img/enemy.xpm",
			&game->size, &game->size);
	game->images.enemy_action = mlx_xpm_file_to_image(game->mlx,
			"img/enemy1.xpm", &game->size, &game->size);
	game->images.player_action = mlx_xpm_file_to_image(game->mlx,
			"img/player1.xpm",
			&game->size, &game->size);
	game->images.wenemy = mlx_xpm_file_to_image(game->mlx, "img/wenemy.xpm",
			&game->size, &game->size);
	game->images.wenemy_action = mlx_xpm_file_to_image(game->mlx,
			"img/wenemy1.xpm", &game->size, &game->size);
}

void	ft_draw_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->images.wenemy_action1 = mlx_xpm_file_to_image(game->mlx,
			"img/wenemy2.xpm", &game->size, &game->size);
	while (y < game->game_map.height)
	{
		x = 0;
		while (x < game->game_map.width)
		{
			if (game->game_map.array[y][x] == 'V')
				ft_draw_tile_2(game, game->images.enemy, y, x);
			else if (game->game_map.array[y][x] == 'W')
				ft_draw_tile_2(game, game->images.wenemy_action1, y, x);
			x++;
		}
		y++;
	}
}

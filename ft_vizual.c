/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vizual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:42:54 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/03 17:33:08 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_game *game, int y, int x)
{
	if (game->game_map.array[game->player_y - y][game->player_x - x] == '1')
		return ;
	if (game->game_map.array[game->player_y - y][game->player_x - x] == 'C')
	{
		game->game_map.array[game->player_y - y][game->player_x - x] = '0';
		game->score++;
	}
	if (game->game_map.array[game->player_y - y][game->player_x - x] == 'E')
	{
		if (game->score == game->game_map.coin)
			exit (0);
		else
			return ;
	}
	if (game->game_map.array[game->player_y - y][game->player_x - x] == 'W')
		exit (0);
	ft_draw_tile_2(game, game->images.chrono, game->player_y, game->player_x);
	game->player_x -= x;
	game->player_y -= y;
	ft_draw_tile_2(game, game->images.player, game->player_y, game->player_x);
}

int	ft_hooks(int key, t_game *game)
{
	if (key == 13)
		ft_move_player(game, 1, 0);
	if (key == 1)
		ft_move_player(game, -1, 0);
	if (key == 0)
		ft_move_player(game, 0, 1);
	if (key == 2)
		ft_move_player(game, 0, -1);
	if (key == 53)
		exit(0);
	ft_print_steps(game);
	return (0);
}

void	ft_draw_tile(t_game *game, void *tile, int y, int x)
{
	y = y * game->size;
	x = x * game->size;
	mlx_put_image_to_window(game->mlx, game->mlx_win, tile, x, y);
}

void	ft_draw_tile_2(t_game *game, void *tile2, int y, int x)
{
	y = y * game->size;
	x = x * game->size;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->images.chrono, x, y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, tile2, x, y);
}

void	ft_draw_map(t_game *game, int x, int y)
{
	game->flag = 0;
	y = 0;
	while (y < game->game_map.height)
	{
		x = 0;
		while (x < game->game_map.width)
		{
			if (game->game_map.array[y][x] == '1')
				ft_draw_tile(game, game->images.wall, y, x);
			else if (game->game_map.array[y][x] == '0')
				ft_draw_tile(game, game->images.chrono, y, x);
			else if (game->game_map.array[y][x] == 'P')
				ft_draw_tile_2(game, game->images.player, y, x);
			else if (game->game_map.array[y][x] == 'E')
				ft_draw_tile(game, game->images.exit, y, x);
			else if (game->game_map.array[y][x] == 'C')
				ft_draw_tile_2(game, game->images.coin, y, x);
			x++;
		}
		y++;
	}
	ft_draw_enemy(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:18:02 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/03 16:33:16 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_anime(t_game *game)
{
	if (game->images.frame == 6000)
	{
		ft_draw_tile_2(game, game->images.player_action, game->player_y,
			game->player_x);
		game->images.frame = 0;
	}
	else if (game->images.frame == 2500)
	{
		ft_draw_tile_2(game, game->images.player, game->player_y,
			game->player_x);
	}
	game->images.frame += 1;
}

void	ft_enemy_anime(t_game *game)
{
	if (game->images.e_frame == 10000)
	{
		ft_draw_tile_2(game, game->images.enemy_action, game->enemy_y,
			game->enemy_x);
		game->images.e_frame = 0;
	}
	else if (game->images.e_frame == 5000)
	{
		ft_draw_tile_2(game, game->images.enemy, game->enemy_y, game->enemy_x);
	}
	game->images.e_frame += 1;
}

void	ft_wenemy_anime(t_game *game)
{
	if (game->images.w_frame == 15000)
	{
		ft_draw_tile_2(game, game->images.wenemy_action1, game->wenemy_y,
			game->wenemy_x);
		game->images.w_frame = 0;
	}
	else if (game->images.w_frame == 10000)
	{
		ft_draw_tile_2(game, game->images.wenemy_action, game->wenemy_y,
			game->wenemy_x);
	}
	else if (game->images.w_frame == 5000)
	{
		ft_draw_tile_2(game, game->images.wenemy, game->wenemy_y,
			game->wenemy_x);
	}
	game->images.w_frame += 1;
}

void	ft_enemy_move(t_game *game)
{
	if (game->enemy_y == game->player_y && game->enemy_x == game->player_x)
		exit (0);
	if (game->game_map.array[game->enemy_y - 1][game->enemy_x] == '1')
		game->flag = 0;
	if (game->game_map.array[game->enemy_y + 1][game->enemy_x] == '1')
		game->flag = 1;
	if (game->images.enemy_step == 3000 && game->flag == 0)
	{
		ft_draw_tile_2(game, game->images.chrono, game->enemy_y,
			game->enemy_x);
		ft_draw_tile_2(game, game->images.enemy_action, game->enemy_y + 1,
			game->enemy_x);
		game->enemy_y += 1;
		game->images.enemy_step = 0;
	}
	if (game->images.enemy_step == 3000 && game->flag == 1)
	{
		ft_draw_tile_2(game, game->images.chrono, game->enemy_y,
			game->enemy_x);
		ft_draw_tile_2(game, game->images.enemy_action, game->enemy_y - 1,
			game->enemy_x);
		game->enemy_y -= 1;
		game->images.enemy_step = 0;
	}
	game->images.enemy_step += 1;
}

int	ft_render(t_game *game)
{
	ft_player_anime(game);
	ft_enemy_anime(game);
	ft_wenemy_anime(game);
	ft_enemy_move(game);
	return (0);
}

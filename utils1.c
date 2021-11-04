/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:36:24 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/03 18:35:11 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_pos(t_game *game, int i, int j)
{
	game->game_map.player++;
	game->player_x = j;
	game->player_y = i;
}

void	ft_check_pos_enemy(t_game *game, int i, int j)
{
	game->game_map.enemy++;
	game->enemy_x = j;
	game->enemy_y = i;
}

void	ft_check_pos_wenemy(t_game *game, int i, int j)
{
	game->game_map.wenemy++;
	game->wenemy_x = j;
	game->wenemy_y = i;
}

void	ft_for_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->game_map.height)
	{
		j = 0;
		while (j < game->game_map.width)
		{	
			if (game->game_map.array[i][j] == 'V')
				ft_check_pos_enemy(game, i, j);
			else if (game->game_map.array[i][j] == 'W')
				ft_check_pos_wenemy(game, i, j);
			j++;
		}
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

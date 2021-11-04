/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:53:48 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/04 16:17:38 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_steps(t_game *game)
{
	int	count;

	count = game->images.step;
	game->images.step += 1;
	ft_putstr("numbers of steps");
	ft_putnbr(count);
	ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_free_map(t_game *game, char *argv)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = 1;
	while (i)
	{
		line = get_next_line(fd);
		if (line)
		{
			game->game_map.height++;
			free(line);
		}
		else
			i = 0;
	}
	close(fd);
}

void	ft_read_map(char *argv, t_game *game)
{
	int		fd;
	int		i;

	i = 0;
	ft_name_map(argv);
	game->game_map.height = 0;
	ft_free_map(game, argv);
	fd = open(argv, O_RDONLY);
	game->game_map.array = malloc(sizeof(char **) * game->game_map.height + 1);
	if (!game->game_map.array)
		return ;
	game->game_map.array[game->game_map.height] = NULL; 
	while (i < game->game_map.height)
	{
		game->game_map.array[i] = get_next_line(fd);
		i++;
	}
	if (ft_valid_rectangle(game->game_map.array, game->game_map.height))
		i = ft_valid_wall(game->game_map.array, game->game_map.height, 0);
	if (i == 1)
		i = ft_valid_count_tile(game);
	ft_load_img(game);
	if (i == 1)
		ft_draw_map(game, i, 0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (argc > 1)
		ft_read_map(argv[1], game);
	else
	{
		write(1, "Error\n No args", 15);
		exit (0);
	}
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_hooks, game);
	game->images.frame = 0;
	mlx_loop_hook(game->mlx, ft_render, game);
	mlx_loop(game->mlx);
}

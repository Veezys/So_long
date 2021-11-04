/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:00:36 by breadyma          #+#    #+#             */
/*   Updated: 2021/11/04 16:27:15 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define BUFFER_SIZE 42

typedef struct s_map
{
	int		height;
	int		width;
	int		player;
	int		coin;
	int		exit;
	int		wall;
	int		chrono;
	int		enemy;
	int		wenemy;
	char	**array;
}	t_map;

typedef struct s_img
{
	void	*(player);
	void	*(coin);
	void	*(exit);
	void	*(chrono);
	void	*(wall);
	void	*(enemy);
	void	*(wenemy);
	int		frame;
	int		e_frame;
	int		w_frame;
	int		enemy_step;
	int		step;
	void	*(player_action);
	void	*(enemy_action);
	void	*(wenemy_action);
	void	*(wenemy_action1);
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		size;
	int		flag;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		wenemy_x;
	int		wenemy_y;
	int		score;
	t_map	game_map;
	t_img	images;
}	t_game;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_sp(char	*st_str);
char	*ft_substr(char *s, unsigned int start, size_t len);

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_load_img(t_game *game);
void	ft_draw_map(t_game *game, int x, int y);
void	ft_draw_enemy(t_game *game);
void	ft_draw_tile_2(t_game *game, void *tile2, int y, int x);
void	ft_draw_tile(t_game *game, void *tile, int y, int x);
int		ft_render(t_game *game);
void	ft_free_map(t_game *game, char *argv);
void	ft_print_steps(t_game *game);

size_t	ft_strlen(const char *s);

int		ft_hooks(int key, t_game *game);
int		ft_errors(int num);
int		ft_strlen_map(const char *s);
int		ft_valid_wall(char **game, int height, int k);
int		ft_valid_rectangle(char **game, int height);
int		ft_valid_count_tile(t_game *game);
int		ft_valid_character(t_game *game, int i, int j);
int		ft_valid_tile(t_game *game);
int		ft_name_map(char *argv);

void	ft_check_pos(t_game *game, int i, int j);
void	ft_check_pos_enemy(t_game *game, int i, int j);
void	ft_check_pos_wenemy(t_game *game, int i, int j);
void	ft_for_enemy(t_game *game);
void	ft_close_game(t_game *game);
void	ft_close(char **game);

#endif

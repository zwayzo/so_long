/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:34:56 by moazzedd          #+#    #+#             */
/*   Updated: 2022/12/20 17:38:33 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <stdarg.h>
# include <limits.h>

# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"

typedef struct s_long
{
	void	*mlx;
	void	*mlx_win;
	void	*win_ptr;
	void	*background ;
	void	*pac;
	void	*wall ;
	void	*coin ;
	void	*door ;
	void	*door_open ;
	void	*pac_down;
	void	*pac_up;
	void	*pac_left;
	int		j;
	int		door_number;
	int		n;
	int		pos_horizen;
	int		pos_vertic;
	char	**maps_tab;
	int		longeur;
	int		largeur;
	int		door_horiz;
	int		door_verti;
	int		coin_number;
	int		count_coin;
	int		i;
	int		x;
	int		move;
	char	**maps_backup;
}	t_long;

int		ft_putchar(char c);
void	to_loop(t_long *so_long);
int		extentions(char *map);
int		ft_putstr(const char *s);
int		ft_putnbr(int nb);
int		ft_hexadecimale(unsigned int decimal, const char *hexaset);
int		ft_unsigne_value(unsigned int c);
int		ft_pointe(long decimal );
int		ft_printf(const char *s, ...);
int		ft_strlen(char *str);
int		hexa(unsigned long long dec, int i, int flag);
void	init_struct(t_long *so_long);
int		check_letters(t_long *so_long);
int		exit_function(void *out);
void	windows_setup(char *map, t_long *so_long);
void	windows_paint(int i, t_long *so_long, int fd);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
int		check_maps(t_long *so_long);
int		toul_door(t_long *so_long);
int		player_counter(t_long *so_long, char **maps);
int		ord_door(t_long *so_long);
char	**map_stock(char *map, t_long *so_long);
int		count_lines(char *map);
int		evnts_handel(int key, t_long *so_long);
int		first_not_1_horizental(void);
int		first_not_1_vertical(void);
int		player_position(char **maps);
int		player_position2(char **maps);
int		map_verify_right(int i, int j, t_long *so_long);
int		map_verify_left(int i, int j, t_long *so_long);
int		map_verify_up(int i, int j, t_long *so_long);
int		map_verify_down(int i, int j, t_long *so_long);
int		coin_verify_right(int i, int j, t_long *so_long);
int		door_counter(t_long *so_long, char **maps);
int		coin_verify_up(int i, int j, t_long *so_long);
int		coin_verify_down(int i, int j, t_long *so_long);
int		coin_verify_left(int i, int j, t_long *so_long);
int		coin_counter(t_long *so_long, char **maps);
int		door_verification(char *maps);
int		player_verification(char *maps);
void	move_down(t_long *so_long);
void	move_right(t_long *so_long);
void	move_left(t_long *so_long);
void	move_up(t_long *so_long);
int		check_wall(char *s);
void	conditions(int fd, char *s, t_long *so_long);
int		struct_fixe(t_long *so_long, int *i);
void	image_setup(t_long *so_long);
void	checker1(char **plan, int largeur, int longeur);
void	checker_1(char **plan, int largeur, int longeur);
void	checker2(char **plan, int largeur, int longeur);
void	checker_2(char **plan, int largeur, int longeur);
int		valide_path(t_long *so_long, int pos_horizen, int pos_vertic);
void	copy(t_long *so_long, char **maps);
int		door_env(t_long *so_long, char **maps);

#endif

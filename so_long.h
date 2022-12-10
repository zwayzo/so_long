#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
#include<mlx.h>


typedef struct s_long
{
	void	*mlx;
	void	*mlx_win;
	void *win_ptr;
	void *background ;
	void *img2;
	void *img3 ;
	void *img5 ;
	void *img6 ;
	void *door_open;
	void *pac_down;
	void *pac_up;
	void *pac_left;
	int j ;
	int n ;
	int pos_horizen;
	int pos_vertic;
	char **maps_tab;
	int longeur;
	int largeur;
	int door_horiz;
	int door_verti;
	int coin_number;
} t_long;


char	*get_next_line(int fd);
int	    ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
int     check_maps(void);
int toul_door();
int ord_door();
char **map_stock();
int count_lines();
int evnts_handel();
int player_position();
int player_position2();
int map_verify_right(int i, int j,t_long *so_long);
int map_verify_left(int i, int j,t_long *so_long);
int map_verify_up(int i, int j,t_long *so_long);
int map_verify_down(int i, int j,t_long *so_long);
int coin_verify_right(int i, int j, t_long *so_long);
int coin_verify_up(int i, int j, t_long *so_long);
int coin_verify_down(int i, int j, t_long *so_long);
int coin_verify_left(int i, int j, t_long *so_long);
int salam();
int door_verification(t_long *so_long, char *maps);
int player_verification(t_long *so_long, char *maps);

# endif

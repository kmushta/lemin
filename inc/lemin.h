/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:27:47 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/17 17:27:49 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define MAX_WAYS 4096
# define MAX_STEPS 4096
# define RES_W 1920
# define RES_H 1080
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define COLOR_RED 16711680
# define COLOR_GREEN 32768
# define COLOR_BLUE 255
# define COLOR_WHITE 16777215
# define KEY_SPACE 49
# define KEY_PLUS 24
# define KEY_MINUS 27

typedef struct		s_circle
{
	int				x;
	int				y;
	int				r;
	int				c;
}					t_circle;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				links;
	struct s_room	**link;
	int				lemin;
	int				step;
	int				way;
	char			start;
	char			end;
	char			visited;
}					t_room;

typedef struct		s_way
{
	struct s_room	**step;
	int				length;
	int				min;
	int				last;
}					t_way;

typedef struct		s_as
{
	int				*key;
	t_room			**value;
	int				length;
}					t_as;

typedef struct		s_point
{
	float			x;
	float			y;
}					t_point;

typedef struct		s_line
{
	struct s_point	*p0;
	struct s_point	*p1;
}					t_line;

typedef struct		s_lemin
{
	int				lemins;
	int				current;
	char			**text;
	struct s_room	**room;
	int				rooms;
	char			start;
	char			end;
	struct s_way	**way;
	int				ways;
}					t_lemin;

typedef struct		s_move
{
	char			*line;
	struct s_move	*next;
}					t_move;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	struct s_image	*img;
	struct s_lemin	*lemin;
	struct s_line	*line;
	struct s_circle	*c;
	float			d;
	int				x;
	int				y;
	struct s_move	*move;
}					t_mlx;

void				ft_input_error(char *text);
void				ft_malloc_error(void);
int					ft_nwords(const char *s, char c);
void				ft_read_rooms(t_lemin *lemin, char **line);
void				ft_read_links(t_lemin *lemin, char **line);
char				**ft_read_lemin(t_lemin *lemin);
t_as				*new_as(int size);
void				push_as(t_as *arr, t_lemin *lemin);
void				sort_as(t_as *arr);
void				del_as(t_as **arr);
void				print_as(t_as *arr);
int					ft_chroom(char *str);
int					ft_is_room(char *str);
t_room				*new_room(char *name, int x, int y);
void				add_link(t_room *room, t_room *link);
int					ft_add_link(t_lemin *lemin, char *line);
void				lemin_add_room(t_lemin *lemin, char *name, int x, int y);
void				ft_add_room(t_lemin *lemin, char *line);
t_way				*new_way(int size);
void				way_rev(t_way *way);
void				ways_rev(t_lemin *lemin);
t_lemin				*create_lemin(void);
int					count_lem(t_lemin *lemin);
void				lem_shift(t_lemin *lemin, t_way *way);
int					calculate(t_way *way, t_room *room, int a);
void				ft_run(t_lemin *lemin);
void				proceed(t_lemin *lemin);
void				calc_n(t_lemin *lemin);
void				push_step(t_way *way, t_room *room);
void				pop_step(t_way *way);
void				ft_push(t_lemin *lemin, char *line);
t_room				*ft_select_room(t_lemin *lemin, char *name);
t_room				*ft_select_start(t_lemin *lemin);
void				set_start(t_lemin *lemin);
void				set_end(t_lemin *lemin);
int					nb_len(int n);
void				draw_line_low(t_mlx *mlx);
void				draw_line_high(t_mlx *mlx);
t_mlx				*rev_line(t_mlx *mlx);
void				draw_line(t_mlx *mlx);
void				draw_wires(t_mlx *mlx);
t_image				*new_image(t_mlx *mlx);
void				image_set_pixel(t_mlx *mlx, int x, int y, int c);
void				clear_image(t_mlx *mlx);
void				draw_circle(t_mlx *mlx, t_circle *c);
void				draw_circles(t_mlx *mlx);
void				put_text(t_mlx *mlx, t_room *room);
void				put_texts(t_mlx *mlx);
void				text_add(t_mlx *mlx, char *str);
int					pass_move(t_mlx *mlx);
void				fill_room(t_lemin *lemin, char *str);
void				fill_rooms(t_mlx *mlx);
t_mlx				*create_mlx(t_lemin *lemin);
void				go_read(t_mlx *mlx, char **line);
void				refresh(t_mlx *mlx);
int					key_hook(int key, t_mlx *mlx);

#endif

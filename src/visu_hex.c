/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:36:46 by kmushta           #+#    #+#             */
/*   Updated: 2018/05/26 16:36:47 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	go_read(t_mlx *mlx, char **line)
{
	while (get_next_line(0, line) == 1 && ft_strncmp(*line, "L", 1))
	{
		if (ft_strcmp(*line, ""))
			ft_input_error("Cannot read");
		free(*line);
	}
	if (!*line)
		ft_input_error("Cannot read");
	text_add(mlx, *line);
	while (get_next_line(0, line) == 1 && !ft_strncmp(*line, "L", 1))
	{
		text_add(mlx, *line);
	}
}

void	refresh(t_mlx *mlx)
{
	clear_image(mlx);
	draw_wires(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->image, 0, 0);
	put_texts(mlx);
}

int		key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_SPACE)
		fill_rooms(mlx);
	if (key == KEY_PLUS)
		mlx->d /= 1.618;
	if (key == KEY_MINUS)
		mlx->d *= 1.618;
	if (key == KEY_A)
		mlx->x += RES_H / 4;
	if (key == KEY_D)
		mlx->x -= RES_H / 4;
	if (key == KEY_W)
		mlx->y += RES_H / 4;
	if (key == KEY_S)
		mlx->y -= RES_H / 4;
	refresh(mlx);
	return (0);
}

int		main(void)
{
	char	**text;
	t_lemin	*lemin;
	t_mlx	*mlx;
	char	*line;

	lemin = create_lemin();
	ft_read_lemin(lemin);
	mlx = create_mlx(lemin);
	text = lemin->text;
	while (*text)
		ft_printf("%s\n", *text++);
	ft_printf("\n");
	go_read(mlx, &line);
	refresh(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

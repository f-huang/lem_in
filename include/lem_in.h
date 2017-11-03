/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:49:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 19:32:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stddef.h>

# define LEM_IN_ERROR "ERROR"

# define PREFIX_ANT "L"
# define PREFIX_COMMENT "#"
# define PREFIX_COMMAND "##"

# define COMMAND_START "start"
# define COMMAND_END "end"

# define ROOM_SEPARATOR ' '
# define TUBE_SEPARATOR '-'

# define OUTPUT_DELIMITER '-'

enum	e_game_step
{
	READ_NB_ANTS = 0,
	READ_ROOMS,
	READ_TUBES
};

typedef struct	s_room
{
	char				*name;
	int					x;
	int					y;
	struct s_room		*next;
}				t_room;

typedef struct	s_tube
{
	t_room				*gate1;
	t_room				*gate2;
	struct s_tube		*next;
}				t_tube;

typedef struct	s_ant
{
	int					index;
	t_room				position;
}				t_ant;

typedef struct	s_game
{
	t_ant				*ants;
	size_t				nb_ants;
	t_tube				*tubes;
	t_room				*rooms;
	t_room				*entry;
	t_room				*exit;
	enum e_game_step	step;
}				t_game;

/*
**	ROOM
*/

void			room_add(t_room **rooms, const char *name, int x, int y);
void			room_delete_all(t_room **rooms);

/*
**	TUBE
*/
void			tube_add(t_tube **tubes, t_room *gate1, t_room *gate2);
void			tube_delete_all(t_tube **tubes);

/*
**	GAME
*/
int				handle_line(t_game *game, const char *line);

int				is_comment(const char *line);
int				is_command(const char *line);
int				is_room(t_game *game, const char *line);

int				read_nb_ants(t_game *game, const char *line);

#endif

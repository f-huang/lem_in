/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:49:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/11 19:05:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stddef.h>

# define LEM_IN_ERROR "ERROR"

# define PREFIX_ANT "L"
# define PREFIX_COMMENT "#"
# define PREFIX_COMMAND "##"
# define INVALID_PREFIX_ROOM "L"

# define NB_COMMANDS 2

# define COMMAND_START "start"
# define COMMAND_END "end"

# define ROOM_SEPARATOR ' '
# define TUBE_SEPARATOR '-'

# define OUTPUT_DELIMITER '-'

# define ACTION_START			(1 << 1)
# define ACTION_END				(1 << 2)

enum				e_game_command
{
	START = 0,
	END
};

typedef struct		s_room
{
	char				*name;
	int					x;
	int					y;
	int					is_occupied;
	struct s_room		*destinations;
	struct s_room		*next_destination;
	struct s_room		*next;
}					t_room;

typedef struct		s_ant
{
	t_room				*position;
	t_room				*coming_from;
	int					has_played;
}					t_ant;

typedef struct		s_tube
{
	t_room				*gate1;
	t_room				*gate2;
	struct s_tube		*next;
}					t_tube;

typedef struct		s_game
{
	t_ant				*ants;
	t_tube				*tubes;
	t_room				*rooms;
	t_room				*entry;
	t_room				*exit;
	size_t				nb_ants;
	size_t				nb_rooms;
	size_t				nb_tubes;
	int					next_action;
}					t_game;

/*
**	ROOM
*/

void				room_add(t_room **rooms, size_t *size, const char *name, int x, int y);
void				room_delete_all(t_room **rooms);
t_room				*room_find(t_room *rooms, const char *name);
t_room				*room_find_with_coordinates(t_room *rooms, int x, int y);
void				room_add_destination(t_room **rooms, t_room *gate1, t_room *gate2);

/*
**	TUBE
*/
void				tube_add(t_tube **tubes, size_t *size, t_room *gate1, t_room *gate2);
void				tube_delete_all(t_tube **tubes);
t_tube				*tube_find(t_tube *tubes, t_room *needle1, t_room *needle2);

/*
**	GAME
*/

int					init_game(t_game *game);
void				clear_game(t_game *game);

enum e_game_command	get_command_enum(const char *str);
const char			*get_command_name(enum e_game_command command);

int					handle_line(t_game *game, const char *line);

int					read_nb_ants(t_game *game, const char *line);

int					is_comment(const char *line);
int					is_command(int *action, const char *line);
int					is_room(t_game *game, const char *line);
int					is_tube(t_game *game, const char *line);

int					is_game_ready(t_game game);

#endif

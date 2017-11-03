/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:49:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 18:39:45 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define LEM_IN_ERROR "ERROR"

# define PREFIX_ANT "L"
# define PREFIX_COMMENT "#"
# define PREFIX_COMMAND "##"

# define COMMAND_START "start"
# define COMMAND_END "end"

# define TUBE_SEPARATOR "-"

# define OUTPUT_DELIMITER "-"

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
	t_tube				*tubes;
	t_room				*rooms;
	t_room				*entry;
	t_room				*exit;
	enum e_game_step	step;
}				t_game;

#endif

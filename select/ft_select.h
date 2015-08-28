/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 03:14:53 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 17:51:09 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <sys/ioctl.h>	/* struct winsize */
# include <termios.h>	/* struct termios */

# define NB_KEY 9
# define K_ARROW_UP "\033\133\101\0"
# define K_ARROW_DOWN "\033\133\102\0"
# define K_ARROW_RIGHT "\033\133\103\0"
# define K_ARROW_LEFT "\033\133\104\0"
# define K_BACKSPACE "\177\0\0\0"
# define K_ESCAPE "\033\0\0\0"
# define K_DELETE "\033\133\053\176"
# define K_RETURN "\012\0\0\0"
# define K_SPACE "\040\0\0\0"

typedef struct s_env	t_env;

typedef struct		s_key
{
	char			key[4];
	void			(*f)(t_env *);
}					t_key;

struct				s_env
{
	int				cursor;
	char			**wrd_tab;
	int				*len_tab;
	int				*mod_tab;
	t_key			*key_tab;
	int				wrd_max_len;
	int				nb_wrd;
	struct winsize	*ws;
	struct termios	*term;
};

/*
** Display
*/
int		display(t_env *e);

/*
** Env
*/
int		env_init(t_env **e, struct termios *term, int nb_wrd, char **wrd_tab);
void	env_free(t_env **e);
int		ft_iputchar(int c);

/*
** Key processing
*/
int		key_tab_init(t_key **key_tab);
void	key_tab_free(t_key **key_tab);
int		process_key(t_env *e, char *cbuf);

void	f_return(t_env *e);
void	f_delete(t_env *e);
void	f_escape(t_env *e);
void	f_select(t_env *e);
void	f_move_up(t_env *e);
void	f_move_down(t_env *e);
void	f_move_right(t_env *e);
void	f_move_left(t_env *e);

/*
** Signals
*/
void	signal_handlers_init(t_env *e);
void	fs_resize(int sigint);

#endif /* !FT_SELECT_H */


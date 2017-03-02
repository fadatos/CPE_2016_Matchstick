/*
** navy.h for  in /home/fadatos/B2_Modules/Unix_system_programmation/include
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Tue Jan 31 01:47:23 2017 albouy titouan
** Last update Mon Feb 27 14:36:53 2017 albouy titouan
*/

#ifndef MASTICK_H_
# define MASTICK_H_
# define READ_SIZE (500)

typedef struct	s_value
{
  int		line;
  int		sub_stick;
  int		error;
  int		rest_bat;
  int		player;
}		t_value;

typedef struct  s_get_curs
{
  int		i;
  int		j;
  int		check_read;
}		t_get_curs;

int		more(char **av);
int		good_int(char *s);
int		disp_ret(char *s);
char		*sum_bin(char *sum, char **tab_allum);
int		*fill_tab();
int		my_strlen(char *str);
int		my_strcmp(char *s1, char *s2, int x);
int		error_game(int ac, char **av);
int		my_atoi(char *str);
int		round_player(int player);
int		run_game(char **av, char **maps, int end_game, t_value *info);
int		input_value(t_value *info, char **maps, char **av);
int             stick_ok(t_value *info, char **maps);
char		**input_value_ia(t_value *info, char **maps, char **av);
int		win_player(int player, char **maps);
void		usage(void);
void		aff_tab(char **tab);
void		my_putstr(char *str);
void		my_putstr_error(char *str);
void		my_putchar(char c);
void		aff_message(t_value *info, int player);
int		my_putnbr(int nb);
char		**init_tab(int line);
char		**modif_map(t_value *info, char **maps);
char		*my_memset(char *buf, char c, int j, int i);
char		*my_strcat(char *s1,char *s2);
char		*get_next_line(const int fd, int a);

#endif /* !MASTICK_H_ */

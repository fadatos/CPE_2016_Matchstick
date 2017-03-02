/*
** main.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Mon Feb 13 15:13:23 2017 albouy titouan
** Last update Mon Feb 27 12:19:21 2017 albouy titouan
*/

#include <stdlib.h>
#include "mastick.h"

int		main(int ac, char **av)
{
  char		**maps;
  t_value	*info;

  if ((info = malloc(sizeof(t_value))) == NULL)
    return (84);
  if (error_game(ac, av) != 0)
    return (84);
  else if ((maps = init_tab(my_atoi(av[1]))) == NULL)
    return (84);
  info->player = 1;
  return (run_game(av, maps, 0, info));
}

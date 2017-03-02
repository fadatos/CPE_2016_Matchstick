/*
** gestion_error.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Tue Feb 14 16:20:36 2017 albouy titouan
** Last update Thu Feb 23 14:12:47 2017 albouy titouan
*/

#include <stdlib.h>
#include "mastick.h"

int		check_number(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (84);
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (84);
      i++;
    }
  return (0);
}

int		error_game(int ac, char **av)
{
  if (ac != 3)
    return (84);
  else if (check_number(av[1]) != 0 || check_number(av[2]) != 0)
    return (84);
  else if (my_atoi(av[1]) > 100 || my_atoi(av[1]) <= 0)
    return (84);
  return (0);
}

/*
** value.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Wed Feb 15 01:02:31 2017 albouy titouan
** Last update Mon Feb 27 14:34:05 2017 albouy titouan
*/

#include <stdlib.h>
#include <stdio.h>
#include "mastick.h"

int		stick_ok(t_value *info, char **maps)
{
  int		i;
  int		match;

  i = 0;
  match = 0;
  while (maps[info->line][i] != '\0')
    {
      if (maps[info->line][i] == '|')
	match++;
      i++;
    }
  if (info->sub_stick > match)
    return (84);
  return (0);
}

char		*cut_one(char *str)
{
  int		i;
  char		*new_str;

  if ((new_str = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\n')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

int		lol(t_value *info, char **maps, char **av)
{
  if (info->sub_stick == 0)
    return (disp_ret("Error: you have to remove at least one match"));
  if (stick_ok(info, maps) != 0)
    return (disp_ret("Error: not enough matches on this line\n"));
  if (info->sub_stick > my_atoi(av[2]))
    return (more(av));
  aff_message(info, 0);
  return (0);
}

int		input_value(t_value *info, char **maps, char **av)
{
  char		*temp;

  if ((temp = malloc(sizeof(char) * 500)) == NULL)
    return (-84);
  my_putstr("Line: ");
  if ((temp = get_next_line(0, 0)) == NULL)
    return (-1);
  if (my_strlen(temp) < 2)
    return (-84);
  if (good_int(temp = cut_one(temp)) != 0)
    return (disp_ret("Error: invalid input (positive number expected)\n"));
  info->line = my_atoi(temp);
  if (info->line < 1 || info->line > my_atoi(av[1]))
    return (disp_ret("Error: this line is out of range\n"));
  my_putstr("Matches: ");
  if ((temp = get_next_line(0, 0)) == NULL)
    return (-1);
  if (my_strlen(temp) < 2)
    return (-84);
  info->sub_stick = my_atoi(cut_one(temp));
  return (lol(info, maps, av));
}


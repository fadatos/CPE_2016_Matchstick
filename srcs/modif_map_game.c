/*
** modif_map_game.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Wed Feb 15 05:42:36 2017 albouy titouan
** Last update Thu Feb 23 14:13:58 2017 albouy titouan
*/

#include <stdio.h>
#include "mastick.h"

int		find_sticks(char *str)
{
  int		l;

  l = my_strlen(str);
  while (str[l] != '|')
    l--;
  return (l);
}

char		**modif_map(t_value *info, char **maps)
{
  int		count;
  int		begin;

  begin = find_sticks(maps[info->line]);
  count = 0;
  while (count < info->sub_stick)
    {
      maps[info->line][begin] = ' ';
      begin --;
      count++;
    }
  return (maps);
}

/*
** win_player.c for  in /home/fadatos/B2_Modules/CPE_part_1/Matchstick/version1/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Mon Feb 20 08:30:35 2017 albouy titouan
** Last update Thu Feb 23 14:14:58 2017 albouy titouan
*/

#include <stdlib.h>
#include "mastick.h"

int		win_player(int player, char **maps)
{
  int		i;
  int		y;

  i = 0;
  while (maps[i] != NULL)
    {
      y = 0;
      while (maps[i][y] != '\0')
	{
	  if (maps[i][y] == '|')
	    return (0);
	  y++;
	}
      i++;
    }
  return (1);
}

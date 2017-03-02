/*
** loop_game.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1
**
** Made by albouy titouan
** Login   <fadatos@epitech.net>
**
** Started on  Tue Feb 14 14:00:15 2017 albouy titouan
** Last update Sun Feb 26 22:14:41 2017 albouy titouan
*/

#include <stdlib.h>
#include "mastick.h"

int		game_end(char **maps,int player)
{
  aff_tab(maps);
  if (player == 2)
    my_putstr("You lost, too bad... \n");
  else
    my_putstr("I lost... snif... but I'll get you next time!!\n");
  return (player);
}

void		disp_map(char **maps)
{
  aff_tab(maps);
  my_putstr("\n");
}

int		run_game(char **av, char **maps, int end_game, t_value *info)
{
  info->rest_bat = 2 * my_atoi(av[1]) + 1;
  while (end_game == 0)
    {
      disp_map(maps);
      if (info->player == 1)
	{
	  my_putstr("Your turn:\n");
	  info->error = 42;
	  while (info->error != 0)
	    {
	      info->error = input_value(info, maps, av);
	      if (info->error == -1)
		return (0);
	    }
	  maps = modif_map(info, maps);
	}
      else
	maps = input_value_ia(info, maps, av);
      info->player = round_player(info->player);
      end_game = win_player(info->player, maps);
    }
  return (game_end(maps, info->player));
}

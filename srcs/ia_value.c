/*
** ia_value.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Wed Feb 15 05:21:05 2017 albouy titouan
** Last update Sun Feb 26 22:39:49 2017 albouy titouan
*/

#include <stdlib.h>
#include "mastick.h"

char		*binaire_1(unsigned int nb, char *buf, char *base, int o)
{
  int		size;
  int		modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  size = my_strlen(base);
  modulo = nb % size;
  nb = nb / size;
  o++;
  if (nb > 0)
    binaire_1(nb, buf, base, o);
  buf[o - 1] = base[modulo];
  return (buf);
}

char		**maj_tab_allum(char **tab_allum, char **maps, int nb_line)
{
  int		i;
  int		j;
  int		match;

  if ((tab_allum = malloc(sizeof(char **) * (nb_line + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i + 1 <= nb_line)
    {
      j = 0;
      match = 0;
      while (maps[i + 1][j] != '\0')
	{
	  if (maps[i + 1][j] == '|')
	    match++;
	  j++;
	}
      if ((tab_allum[i] = malloc(sizeof(char *) * 9)) == NULL)
	return (NULL);
      my_memset(tab_allum[i], '0', 0, 8);
      tab_allum[i] = binaire_1(match, tab_allum[i], "01", 0);
      i++;
    }
  tab_allum[i] = NULL;
  return (tab_allum);
}

int		bin_to_dec(char *bin)
{
  int		*tab_bin;
  int		dec;
  int		i;

  tab_bin = fill_tab();
  i = 0;
  dec = 0;
  while (tab_bin[i] && bin[i])
    {
      if (bin[i] == '1')
	dec = dec + tab_bin[i];
      i = i + 1;
    }
  return (dec);
}

char		**algo_xor(t_value *info, char **maps, char **av, int sub)
{
  int		i;

  i = 0;
  info->sub_stick = (sub % my_atoi(av[2]));
  if (info->sub_stick < 2)
    info->sub_stick = 1;
  else
    info->sub_stick = info->sub_stick - 1;
  info->line = 1;
  while (42)
    {
      info->line = 1;
      while (info->line <= my_atoi(av[1]) )
	{
	  if (stick_ok(info, maps) == 0)
	    {
	      aff_message(info, 1);
	      return (modif_map(info, maps));
	    }
	  info->line++;
	}
      info->sub_stick--;
    }
  return (modif_map(info, maps));
}

char		**input_value_ia(t_value *info, char **maps, char **av)
{
  char		**tab_allum;
  char		*sum;
  int		trad_sum;

  my_putstr("AI's turn...\n");
  tab_allum = maj_tab_allum(tab_allum, maps, my_atoi(av[1]));
  sum = sum_bin(sum, tab_allum);
  trad_sum = bin_to_dec(sum);
  maps = algo_xor(info, maps, av, trad_sum);
  return (maps);
}

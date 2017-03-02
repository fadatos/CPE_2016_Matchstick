/*
** fonction_lib_4.c for  in /home/fadatos/B2_Modules/CPE/CPE_part_1/Matchstick/version3/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Sun Feb 26 15:24:35 2017 albouy titouan
** Last update Sun Feb 26 23:27:51 2017 albouy titouan
*/

#include <unistd.h>
# include <stdlib.h>
# include "mastick.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		aff_message(t_value *info, int player)
{
  if (player == 1)
    my_putstr("AI removed ");
  else
    my_putstr("Player removed ");
  my_putnbr(info->sub_stick);
  my_putstr(" match(es) from line ");
  my_putnbr(info->line);
  my_putchar('\n');
}

char		*sum_bin(char *sum, char **tab_allum)
{
  int		i;
  int		j;
  int		k;
  int		temp;

  i = 0;
  k = 0;
  if ((sum = malloc(sizeof(char *) * 9)) == NULL)
    return (NULL);
  sum = my_memset(sum, '0', 0, 8);
  while (i < 8)
    {
      temp = 0;
      j = 0;
      while (tab_allum[j] != NULL)
	{
	  temp = temp + tab_allum[j][i] - 48;
	  j++;
	}
      if (temp % 2 == 1)
	sum[i] = '1';
      i++;
    }
  return (sum);
}

int		*fill_tab()
{
  int		*tab;

  if (!(tab = malloc(sizeof(int) * 9)))
    return (NULL);
  tab[0] = 1;
  tab[1] = 2;
  tab[2] = 4;
  tab[3] = 8;
  tab[4] = 16;
  tab[5] = 32;
  tab[6] = 64;
  tab[7] = 128;
  tab[8] = '\0';
  return (tab);
}

int		good_int(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] < '0' || s[i] > '9')
	return (84);
      i++;
    }
  return (0);
}

/*
** init_map.c for  in /home/fadatos/B2_Modules/CPE_part_2/Matchstick/version1
**
** Made by albouy titouan
** Login   <fadatos@epitech.net>
**
** Started on  Tue Feb 14 13:56:56 2017 albouy titouan
** Last update Thu Feb 23 14:13:29 2017 albouy titouan
*/

#include <stdlib.h>
#include <stdio.h>
#include "mastick.h"

char		*init_allum(int size,int j)
{
  static int	ligne = 0;
  int   	lower;
  int   	hight;
  char		*buf;

  lower = size / 2 - ligne;
  hight = size / 2 + ligne;
  if ((buf = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  buf[0] = '*';
  while (j++ <= lower - 3)
    buf[j] = ' ';
  while (j < hight)
    {
      buf[j] = '|';
      j = j + 1;
    }
  ligne++;
  j = j - 1;
  while (j++< size - 4)
    buf[j] = ' ';
  buf[j] = '*';
  buf[j + 1] = '\0';
  return (buf);
}

char		**init_tab(int line)
{
  char		**tab;
  int		size;
  int		i;

  i = 0;
  size = 3 + (2 * line);
  if ((tab = malloc(sizeof(char **) * (line + 3))) == NULL)
    return (NULL);
  if ((tab[i] = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  tab[i] = my_memset(tab[i], '*', 0, size - 2);
  while (i + 1 <= line + 1)
    {
      tab[i + 1] = init_allum(size, 0);
      i++;
    }
  if ((tab[i] = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  tab[i] = my_memset(tab[i], '*', 0, size - 2);
  tab[i + 1] = NULL;
  return (tab);
}

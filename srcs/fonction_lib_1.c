/*
** fonction_lib_1.c for  in /home/fadatos/B1_Modules/B1_Programmation_shell/version2/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Thu Jan 26 10:38:29 2017 albouy titouan
** Last update Sun Feb 26 15:23:51 2017 albouy titouan
*/

#include <unistd.h>
#include "mastick.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void		aff_tab_int(int *tab)
{
  int		i;

  i = 0;
  while (tab[i] != -1)
    {
      my_putnbr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

void		aff_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
}

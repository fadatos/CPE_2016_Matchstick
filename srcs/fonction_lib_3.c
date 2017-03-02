/*
** fonction_lib_3.c for  in /home/fadatos/B2_Modules/CPE_part_1/Matchstick/version1/srcs
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Mon Feb 20 08:59:06 2017 albouy titouan
** Last update Sun Feb 26 23:34:34 2017 albouy titouan
*/

#include "mastick.h"

int		my_putnbr(int nb)
{
  int		modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb > 9)
	{
	  modulo = (nb % 10);
	  nb = (nb - modulo) / 10;
	  my_putnbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	my_putchar(48 + nb);
    }
  return (0);
}

int		more(char **av)
{
  my_putstr("Error: you cannot remove more than ");
  my_putnbr(my_atoi(av[2]));
  my_putstr(" matches per turn\n");
  return (-84);
}

int		disp_ret(char *s)
{
  my_putstr(s);
  return (-84);
}

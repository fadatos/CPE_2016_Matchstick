/*
** fonction_lib_2.c for  in /home/fadatos/B1_Modules/B1_Programmation_shell/version2/srcs
**
** Made by albouy titouan
** Login   <fadatos@epitech.net>
**
** Started on  Thu Jan 26 10:38:29 2017 albouy titouan
** Last update Fri Feb 24 17:15:50 2017 albouy titouan
*/

#include <stdlib.h>
#include "mastick.h"

char		*my_memset(char *buf, char c, int j, int i)
{
  while (j < i)
    {
      buf[j] = c;
      j++;
    }
  buf[j] = '\0';
  return (buf);
}


char		*loop_strcat1(char *buff, char *s1, int i)
{
  while (s1[i] != '\0')
    {
      buff[i] = s1[i];
      i++;
    }
  return (buff);
}

char		*loop_strcat2(char *buff, char *s2, int i)
{
  int		j;

  j = 0;
  while (s2[j] != '\0')
    {
      buff[i] = s2[j];
      i++;
      j++;
    }
  buff[i] = '\0';
  return (buff);
}

char		*my_strcat(char *s1, char *s2)
{
  int		size_s1;
  int		size_s2;
  int		i;
  char		*buff;

  size_s1 = my_strlen(s1);
  size_s2 = my_strlen(s2);
  if ((buff = malloc(sizeof(char) * (size_s1 + size_s2 + 1))) == NULL)
    return (NULL);
  buff = loop_strcat1(buff, s1, 0);
  buff = loop_strcat2(buff, s2, size_s1);
  return (buff);
}

int		my_atoi(char *str)
{
  int		i;
  int		ret;

  ret = 0;
  i = 0;
  while (str[i] != '\0')
    {
      ret = ret * 10 + str[i] - '0';
      i++;
    }
  return (ret);
}


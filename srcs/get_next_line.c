/*
** test_2.1.c for  in /home/fadatos
** 
** Made by albouy titouan
** Login   <fadatos@epitech.net>
** 
** Started on  Thu Jan  5 12:19:46 2017 albouy titouan
** Last update Sun Feb 26 22:44:31 2017 albouy titouan
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mastick.h"

char		*my_memset1(char *buf, int j, int i)
{
  while (j < i)
    {
      buf[j] = '\0';
      j++;
    }
  return (buf);
}

char		*my_strcpy_realloc(char *str2, char *str, int *i,int *a)
{
  char		*str3;
  int		l;

  l = 0;
  while (str[*i] != '\0' && str[*i] != '\n')
    {
      str2[*a] = str[*i];
      *a = *a + 1;
      *i = *i + 1;
    }
  str2[*a++] = '\n';
  l = 0;
  if ((str3 = malloc(sizeof(char) * (my_strlen(str2) + READ_SIZE + 1))) == NULL)
    return (NULL);
  while (str2[l] != '\0')
    {
      str3[l] = str2[l];
      l = l + 1;
    }
  str3 = my_memset1(str3, l, my_strlen(str2) + READ_SIZE + 1);
  free(str2);
  return (str3);
}

t_get_curs		fill_s_get(t_get_curs cursor)
{
  cursor.j = 0;
  cursor.check_read = 1;
  return (cursor);
}

char		*get_next_line(const int fd, int a)
{
  static char	buff[READ_SIZE + 1];
  static int	i = 0;
  t_get_curs	cursor;
  char		*str;

  cursor = fill_s_get(cursor);
  if ((str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL || fd < 0)
    return (NULL);
  str = my_memset1(str, 0, READ_SIZE);
  while (cursor.check_read > 0 && buff[i] != '\n')
      if (buff[i] == '\0')
	{
	  my_memset1(buff, 0, READ_SIZE);
	  if ((cursor.check_read = read(fd, buff, READ_SIZE)) <= 0)
	    return (NULL);
	  i = 0;
	}
      else if (cursor.check_read > 0)
	{
	  if ((str = my_strcpy_realloc(str, buff, &i, &a)) == NULL)
	  return (NULL);
	}
  i++;
  return (str);
}

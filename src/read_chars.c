/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** read_chars - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

bool            std_read_chars(const char       *str,
                               size_t          *index,
                               const char       *token)
{
  size_t	i;
  size_t	j;
  size_t	space;

  i = 0;
  j = 0;
  space = 0;
  std_read_space(&str[*index], &space);
  while (str[*index + space + i] != '\0' && token[j] != '\0')
    {
      if (token[j] == str[*index + space + i])
	{
          j = 0;
          i = i + 1;
	}
      else
        j = j + 1;
    }
  if (i == 0)
    return (false);
  *index = *index + i + space;
  return (true);
}


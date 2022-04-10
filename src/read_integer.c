/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** read_chars - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

bool		std_read_integer(const char	*str,
				 size_t		*index,
				 int		*output)
{
  size_t	i;
  size_t	space;

  i = 0;
  space = 0;
  *output = 0;
  std_read_space(&str[*index], &space);
  while (str[*index + space + i] >= '0' && str[*index + space + i] <= '9')
    {
      *output = *output * 10;
      *output = *output + (str[*index + space + i] - '0');
      i = i + 1; 
    }
  if (i == 0)
    return (false);
  *index = *index + i + space;
  return (true);
}

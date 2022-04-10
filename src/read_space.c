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

bool		std_read_space(const char	*str,
			       size_t		*index)
{
  size_t	i;

  i = *index;
  while (str[*index] == ' ')
    *index = *index + 1;
  return ((*index != i));
}

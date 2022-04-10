/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** find_symbol - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

size_t		std_strlen(const char	*str)
{
  size_t	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

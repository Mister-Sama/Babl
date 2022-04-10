/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** split_size - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

size_t		std_split_size(char	**split)
{
  size_t	i;

  i = 0;
  if (split == NULL)
    return (0);
  while (split[i] != NULL)
    i = i + 1;
  return (i);
}


/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** printf_split - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

void		std_print_split(char	**split)
{
  size_t	i;

  i = 0;
  while (split[i] != NULL)
    {
      std_puts(split[i]);
      write(1, "\n", sizeof(char));
      i = i + 1;
    }
}

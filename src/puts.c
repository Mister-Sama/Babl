/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** puts - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

int		std_puts(const char	*str)
{
  return (write(1, str, std_strlen(str)));
}


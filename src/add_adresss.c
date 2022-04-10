/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** add_adress - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

int		std_add_adress(char		*line,
			       t_symbol_table	*table,
			       size_t		*i,
			       char		*name)
{
  t_adress	*adress;

  adress = malloc(sizeof(t_adress));
  if (adress == NULL)
    return (-1);
  adress->adress = std_get_text(line, i);
  if (adress->adress == NULL)
    {
      free(adress);
      return (-1);
    }
  std_push_symbol(&table, name, ADR, adress);
  return (0);
}

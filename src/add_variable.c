/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** exec_babl - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

int		std_add_variable(char			*line,
				 t_symbol_table		*table,
				 size_t			*i)
{
  int		ret;
  char		*name;

  name = std_find_name(line, i);
  if (std_read_text(line, i, "=") == false)
    return (-1);
  if (std_read_text(line, i, "\""))
    ret = std_add_adress(line, table, i, name);
  else
    ret = std_add_value(line, table, i, name);
  return (ret);
}

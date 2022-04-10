/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** add_value - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

int 		std_add_value(char		*line,
			      t_symbol_table	*table,
			      size_t		*i,
			      char		*name)
{
  t_value	*value;

  value = malloc(sizeof(t_value));
  if (value ==  NULL)
    return (-1);
  if (std_read_integer(line, i, &value->value) == false)
    {
      free(value);
      return (-1);
    }
  std_push_symbol(&table, name, VAL, value);
  return (0);
}

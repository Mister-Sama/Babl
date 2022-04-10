/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** add_function - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

int		std_add_function(char		*line,
				 t_symbol_table	*table,
				 size_t		*i,
				 int		type)
{
  char		*name;
  void		*data;

  name = std_find_name(line, i);
  if (std_strcasecmp(name, "main"))
    {
      free(name);
      return (1);
    }
  data = std_get_func_parameters(line, i, type);
  if (data == NULL)
    return (-1);
  std_push_symbol(&table, name, FUNC, data);
  return (0);
}
				 

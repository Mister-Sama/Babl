/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** read_line - 2022
**
** *****************************************************************************
*/

#include                "babl.h"

int			std_read_line(char		*line,
				      t_symbol_table	*table,
				      int		*result)
{
  size_t		i;
  int			ret;

  i = 0;
  if (std_read_chars(line, &i, "#"))
    ret = std_add_function(line, table, &i, VAL);
  else if (std_read_chars(line, &i, "$"))
    ret = std_add_function(line, table, &i, ADR);
  else
    ret = std_add_variable(line, table, &i);
  if (ret == 1)
    return (std_exec_main(line, table, &i, result));
  if (*result == -1)
    return (-1);
  return (ret);
}
				      

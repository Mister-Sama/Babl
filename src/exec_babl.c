/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** exec_babl - 2022
**
** *****************************************************************************
*/

#include		"babl.h"

int			std_exec_babl(char	**cmd)
{
  size_t		i;
  t_symbol_table	table;
  int			ret;
  int			result;
  
  i = 0;
  table.table = NULL;
  result = 0;
  while (cmd[i] != NULL)
    {
      ret = std_read_line(cmd[i], &table, &result);
      if (ret == 1)
	return (result);
      if (ret == -1)
	return (-1);
      i = i + 1;
    }
  return (-1);
}


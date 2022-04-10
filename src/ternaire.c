/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** ternaire - 2022
**
** *****************************************************************************
*/

#include                "babl.h"

static t_variable	*std_exec_ternaire(char			*str,
					   size_t		*i,
					   t_variable		*var,
					   t_symbol_table	**tab)
{
  if (((t_value *)(var->data))->value == 1)
    {
      std_free_variable(var);
      return (std_compute(str, i, tab));
    }
  else if (((t_value *)(var->data))->value == 0)
    {
      std_free_variable(var);
      while (str[*i] != ':' && str[*i] != '\0')
	*i = *i + 1;
      if (*i == '\0')
	return (NULL);
      std_read_text(str, i, ":");
      return (std_compute(str, i, tab));
    }
  return (NULL);
}

t_variable		*std_ternaire(t_variable	*var,
				      size_t		*index,
				      char		*str,
				      t_symbol_table	**tab)
{
  t_variable		*result;

  if (var == NULL)
    return (NULL);
  result = std_compare(var, index, str, tab);
  if (result == NULL)
    return (NULL);
  if (std_read_text(str, index, "?"))
    return (std_exec_ternaire(str, index, result, tab));
  return (result);
}

/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** compare - 2022
**
** *****************************************************************************
*/

#include		"babl.h"

static int		std_compare_operator(char	*str,
					     size_t	*index)
{
  return (std_read_text(str, index, "==") ? SYM_EQUAL :
	  std_read_text(str, index, "<>") ? SYM_DIFF :
	  std_read_text(str, index, "<=") ? SYM_LOWER :
	  std_read_text(str, index, "<") ? SYM_STRICT_LOWER :
	  std_read_text(str, index, ">=") ? SYM_UPPER :
	  std_read_text(str, index, ">") ? SYM_STRICT_UPPER :
	  SYM_NULL);
}

static t_variable	*std_exec_compare(t_variable	*var1,
					  t_variable	*var2,
					  int		operator)
{
  if (var1->type != var2->type)
    {
      std_free_variable(var1);
      std_free_variable(var2);
      return (NULL);
    }
  if (var1->type == VAL)
    ((t_value *)(var1->data))->value =
      (operator == SYM_EQUAL) ? ((t_value *)(var1->data))->value == ((t_value *)(var2->data))->value :
      (operator == SYM_DIFF) ? ((t_value *)(var1->data))->value != ((t_value *)(var2->data))->value :
      (operator == SYM_LOWER) ? ((t_value *)(var1->data))->value <= ((t_value *)(var2->data))->value :
      (operator == SYM_STRICT_LOWER) ? ((t_value *)(var1->data))->value < ((t_value *)(var2->data))->value :
      (operator == SYM_UPPER) ? ((t_value *)(var1->data))->value >= ((t_value *)(var2->data))->value :
      ((t_value *)(var1->data))->value > ((t_value *)(var2->data))->value;
  std_free_variable(var2);
  return (var1);
}

t_variable		*std_compare(t_variable		*var,
				     size_t		*index,
				     char		*str,
				     t_symbol_table	**tab)
{
  t_variable	*nvar;
  t_variable	*result;
  int		operator;

  if (var == NULL)
    return (NULL);
  result = std_sum(var, index, str, tab);
  operator = std_compare_operator(str, index);
  nvar = std_get_variable(str, index, tab);
  if (operator != SYM_NULL)
    {
      if (nvar == NULL)
	return (NULL);
      return (std_compare(std_exec_compare(result, std_sum(nvar, index, str, tab), operator), index, str, tab));
    }
  return (result);
}


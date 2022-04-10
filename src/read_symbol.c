/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** read_symbol - 2022
**
** *****************************************************************************
*/

#include	"babl.h"

bool		std_read_symbol(const char	*str,
				size_t		*index,
				char		*output,
				size_t		output_len)
{
  size_t	i;
  size_t	space;

  i = 0;
  space = 0;
  std_read_space(&str[*index], &space);
  while (std_is_char_symbol(str[*index + i + space]) && i != output_len &&
	 str[*index + i + space] != '\0')
    {
      if (output != NULL)
	output[i] = str[*index + i + space];
      i = i + 1;
    }
  if (output != NULL)
    output[i] = '\0';
  if (i != output_len)
    return (false);
  *index = *index + i + space;
  return (true);
}

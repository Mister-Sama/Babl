/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** get_text - 2022
**
** *****************************************************************************
*/

#include                "babl.h"

char			*std_get_text(char	*str,
				      size_t	*i)
{
  char			*text;
  size_t		j;

  j = 0;
  while ((&str[*i])[j] != '\0' && (&str[*i])[j] != '"')
    j = j + 1;
  text = malloc((j + 1) * sizeof(char));
  if (text == NULL)
    return (NULL);
  j = 0;
  while (str[*i] != '\0' && str[*i] != '"')
    {
      text[j] = str[*i];
      *i = *i + 1;
      j = j + 1;
    }
  if (str[*i] == '\0')
    {
      free(text);
      return (NULL);
    }
  text[j] = '\0';
  return (text);
}
				      

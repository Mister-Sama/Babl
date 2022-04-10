/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** split - 2022
**
** *****************************************************************************
*/

#include        "babl.h"

static char	*std_copy_str(const char	*str,
			      size_t		*len,
			      char		token)
{
  size_t	i;
  char		*nstr;

  i = 0;
  nstr = NULL;
  while (str[*len] != '\0' && str[*len] != token)
    {
      nstr = std_realloc(nstr, (i + 2) * sizeof(char));
      if (nstr == NULL)
	return (NULL);
      nstr[i] = str[*len];
      i = i + 1;
      *len = *len + 1;
    }
  return (nstr);
}

char		**std_split(const char		*str,
			    char		token)
{
  size_t	i;
  size_t	j;
  char		**split;

  i = 0;
  j = 0;
  split = NULL;
  while (str[i] != '\0')
    {
      split = std_realloc(split, (j + 2) * sizeof(char *));
      split[j] = NULL;
      split[j + 1] = NULL;
      if (split == NULL)
	return (0);
      split[j] = std_copy_str(str, &i, token);
      while (str[i] == token)
	i = i + 1;
      j = j + 1;
    }
  return (split);
}

#include <stdlib.h>
#include <stdio.h>

void strcopy(char *dest, char *src)
{
  int i = 0;
  while (*(src + i))
  {
    *(dest + i) = *(src + i);
    ++i;
  }
  *(dest + ++i) = '\0';
}

long strlength(char *src)
{
  long i = 0;
  while (*(src + i))
  {
    i++;
  }
  return i;
}

long strcompare(char *str1, char *str2)
{
  long str1len = strlength(str1);
  long str2len = strlength(str2);
  for (long i = 0; i < str1len && i < str2len; ++i)
  {
    if (*(str1 + i) != *(str2 + i))
    {
      return *(str1 + i) - *(str2 + i);
    }
  }
  return str1len - str2len;
}

int main()
{
  char *wele = "Hello World!";
  char *dest;
  long len = strlength(wele);
  dest = (char *)malloc(sizeof(len + 1));
  strcopy(dest, wele);
  printf("%d\n", strlength(dest));
  printf("%s\n", dest);
}

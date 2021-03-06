#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CharReader
{
  int at;
  char *input;
  long length;
} CharReader;

CharReader *createCharReader(char *input)
{
  CharReader *cr = (CharReader *)malloc(sizeof(CharReader));
  cr->at = 0;
  cr->length = strlen(input);
  cr->input = (char *)malloc(cr->length * sizeof(char));
  strcpy(cr->input, input);
  return cr;
}

char readChar(CharReader *cr)
{
  char ch = *(cr->input + cr->at);
  ++cr->at;
  return ch;
}

char peekChar(CharReader *cr)
{
  return *(cr->input + cr->at);
}

int isEOF(CharReader *cr);
int parse_expr(CharReader *cr);

void parseParen(CharReader *cr)
{
  readChar(cr);
  while (isEOF(cr) != 1 && peekChar(cr) != ')')
  {
    parse_expr(cr);
  }
  readChar(cr);
}

int parse_expr(CharReader *cr)
{
  char ch = peekChar(cr);
  if (ch == '(')
  {
    parseParen(cr);
  }
  else if (ch != ')')
  {
    readChar(cr);
  }

  if (cr->at != cr->length)
  {
    return 0;
  }
  return 1;
}

int isEOF(CharReader *cr)
{
  return cr->at == cr->length;
}

int main()
{
  CharReader *cr = createCharReader("(as(d)f)");
  int is = parse_expr(cr);
  printf("%d\n", is);
}
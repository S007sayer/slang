#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define KEYWORD_FUNC "func"
#define KEYWORD_LET "let"
#define KEYWORD_RET "ret"
#define KEYWORD_EXT "ext"
#define KEYWORD_IF "if"

static char* code = NULL;
static char cur = ' ';
static int pos = 0;

static char* ident = NULL;
static int number = 0;

static void next() {
  cur = code[pos++];
}
void skip_spaces() {
  while(isspace(cur))
    next();
}

token_t next_word() {
  char* word = calloc(sizeof(char), 50);

  for(int i = 0; i < sizeof(word) && isalnum(cur); i++) {
    word[i] = cur;
    next();
  }

  if (strcmp(word, KEYWORD_FUNC) == 0)
    return TOKEN_FUNC;
  else if (strcmp(word, KEYWORD_LET) == 0) 
    return TOKEN_LET;
  else if (strcmp(word, KEYWORD_RET) == 0) 
    return TOKEN_RET;
  else if (strcmp(word, KEYWORD_EXT) == 0) 
    return TOKEN_EXT;
  else if (strcmp(word, KEYWORD_IF) == 0) 
    return TOKEN_IF;
  else {
    ident = word;
    return TOKEN_IDENT;
  }
}

token_t next_number() {
  number = 0;
  while(isdigit(cur)) {
    number = number * 10 + (cur - '0');
    next();
  }
  return TOKEN_NUMBER;
}

token_t next_symbolic() {
  char prev = cur;
  next();
  if (prev == ':')
    return TOKEN_COLON;
  else if (prev == ';')
    return TOKEN_SEMI;
  else if (prev == '.')
    return TOKEN_DOT;
  else if (prev == ',')
    return TOKEN_COMMA;
  else if (prev == '(')
    return TOKEN_LPAREN;
  else if (prev == ')')
    return TOKEN_RPAREN;
  else if (prev == '[')
    return TOKEN_LBRACKET;
  else if (prev == ']')
    return TOKEN_RBRACKET;
  else if (prev == '{')
    return TOKEN_LBLOCK;
  else if (prev == '}')
    return TOKEN_RBLOCK;
  else if (prev == '+')
    return TOKEN_ADD;
  else if (prev == '-')
    return TOKEN_SUB;
  else if (prev == '*')
    return TOKEN_MUL;
  else if (prev == '/')
    return TOKEN_DIV;
  else if (prev == '=') {
    if (cur == '=') {
      next();
      return TOKEN_EQ;
    } else {
      return TOKEN_ASSIGN;
    }
  } else if (prev == '<') {
    if (cur == '=') {
      next();
      return TOKEN_LE;
    } else {
      return TOKEN_LESS;
    }
  } else if (prev == '>') {
    if (cur == '=') {
      next();
      return TOKEN_GE;
    } else {
      return TOKEN_GRTR;
    }
  } else if (prev == '!') {
    if (cur == '=') {
      next();
      return TOKEN_NE;
    } else {
      return TOKEN_NOT;
    }
  }else if (prev == '&') {
    if (cur == '&') {
      next();
      return TOKEN_AND;
    } else {
      return TOKEN_BWAND;
    }
  } else if (prev == '|') {
    if (cur == '|') {
      next();
      return TOKEN_OR;
    } else {
      return TOKEN_BWOR;
    }
  } else if (prev == EOF)
    return TOKEN_EOF;
  else 
    return TOKEN_UNKNOWN;
}
void seek_to_zero() {
  cur = ' ';
  pos = 0;
}


void lexer_set_code(char* val) {
  seek_to_zero();
  code = val;
}
token_t lexer_next_token() {
  skip_spaces();

  if (isalpha(cur)) {
    return next_word();
  } else if (isdigit(cur)) {
    return next_number();
  } else {
    return next_symbolic();
  }
}

char* lexer_get_ident() {
  return ident;
}
int lexer_get_number() {
  return number;
}
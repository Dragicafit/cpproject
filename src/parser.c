#include "parser.h"

#include "constantes.h"
#include "main.h"

char isInteger(char* name) {
  int i = 0;
  if (name[0] == '-') i++;
  for (; i < strlen(name); i++) {
    if (!isdigit(name[i])) {
      return 0;
    }
  }
  return 1;
}

char isNumber(char* name) {
  for (int i = 0; i < strlen(name); i++) {
    if (!isdigit(name[i])) {
      return 0;
    }
  }
  return 1;
}

char isOperator(char name) {
  if (name == '+') return 1;
  if (name == '-') return 1;
  if (name == '*') return 1;
  if (name == '/') return 1;
  if (name == '%') return 1;
  return 0;
}

char isComparaison(char* name) {
  if (strcmp(name, "<") == 0) return 1;
  if (strcmp(name, "<=") == 0) return 1;
  if (strcmp(name, "=") == 0) return 1;
  if (strcmp(name, "<>") == 0) return 1;
  if (strcmp(name, ">=") == 0) return 1;
  if (strcmp(name, ">") == 0) return 1;
  return 0;
}

char isExpression(FILE* f, char* name) {
  char* buff;
  int i = 0;
  if (isInteger(name)) return 1;
  if (name[i++] == '(') {
    if (!isExpression(f, name + i)) return 0;
    int rewind = -fscanf(f, "%s ", buff);
    if (!isOperator(buff)) {
      fseek(f, rewind, SEEK_CUR);
      return 0;
    }
    rewind -= fscanf(f, "%s ", buff);
    if (buff[strlen(buff) - 1] != ')') {
      fseek(f, rewind, SEEK_CUR);
      return 0;
    }
    buff[strlen(buff) - 1] = '\0';
    if (!isExpression(f, buff)) {
      fseek(f, rewind, SEEK_CUR);
      return 0;
    }
    return 1;
  }
  if (strcmp(name, "CARDINAL") == 0 || strcmp(name, "SELF") == 0 ||
      strcmp(name, "SPEED") == 0)
    return 1;
  if (strcmp(name, "PEEK") == 0 || strcmp(name, "RAND") == 0 ||
      strcmp(name, "STATE") == 0 || strcmp(name, "GPSX") == 0 ||
      strcmp(name, "GPSY") == 0) {
    int rewind = -fscanf(f, "%s ", buff);
    if (!isExpression(f, buff)) {
      fseek(f, rewind, SEEK_CUR);
      return 0;
    }
    return 1;
  }
  if (strcmp(name, "TARGETX") == 0 || strcmp(name, "TARGETY") == 0) {
    int rewind = 0;
    for (int i = 0; i < 3; i++) {
      rewind -= fscanf(f, "%s ", buff);
      if (!isExpression(f, buff)) {
        fseek(f, rewind, SEEK_CUR);
        return 0;
      }
    }
    return 1;
  }
  if (strcmp(name, "ANGLE") == 0 || strcmp(name, "DISTANCE") == 0) {
    int rewind = 0;
    for (int i = 0; i < 4; i++) {
      rewind -= fscanf(f, "%s ", buff);
      if (!isExpression(f, buff)) {
        fseek(f, rewind, SEEK_CUR);
        return 0;
      }
    }
    return 1;
  }
}

void parser(int argc, char* argv[]) {
  for (int i = 1; i < argc + 1; i++) {
    FILE* f = fopen(argv[i], "r");
    if (f == NULL) handle_error("fopen");

    for (char* buff; fscanf(f, "%s ", buff) > 0;) {
      if (!isNumber(buff)) handle_error("not number");
    }
  }
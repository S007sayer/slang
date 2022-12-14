#include "func_ast.h"

#include <stdlib.h>

ast_t* create_func_ast(ast_t* decl, ast_t* body) {
  func_ast_t* func_ast = malloc(sizeof(func_ast_t));

  func_ast->type = AST_FUNC;
  func_ast->decl = decl;
  func_ast->body = body;

  return (ast_t*) func_ast;
}
void destroy_func_ast(func_ast_t* func_ast) {
  destroy_ast(func_ast->decl);
  destroy_ast(func_ast->body);
  free(func_ast);
}
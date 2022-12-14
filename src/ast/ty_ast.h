#pragma once

#include "ast.h"
#include "ast_type.h"


typedef struct {
  ast_type_t type;
  
  char* name;
} ty_ast_t;

ast_t* create_ty_ast(char* name);
void destroy_ty_ast(ty_ast_t* ty_ast);


typedef struct {
  ast_type_t type;
  
  ast_t* ty;
} ptr_ty_ast_t;

ast_t* create_ptr_ty_ast(ast_t* ty);
void destroy_ptr_ty_ast(ptr_ty_ast_t* ty_ast);


typedef struct {
  ast_type_t type;
  
  ast_t* ty;
  int size;
} arr_ty_ast_t;

ast_t* create_arr_ty_ast(ast_t* ty, int size);
void destroy_arr_ty_ast(arr_ty_ast_t* ty_ast);


typedef struct {
  ast_type_t type;
  
  ast_t* ty;
} uptr_ty_ast_t;

ast_t* create_uptr_ty_ast(ast_t* ty);
void destroy_uptr_ty_ast(uptr_ty_ast_t* ty_ast);


typedef struct {
  ast_type_t type;
  
  ast_t* ty;
} sptr_ty_ast_t;

ast_t* create_sptr_ty_ast(ast_t* ty);
void destroy_sptr_ty_ast(sptr_ty_ast_t* ty_ast);


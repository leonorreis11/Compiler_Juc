//
// Created by ricgo on 06/11/2022.
//

#ifndef JUCOMPILER_SYNTAX_TREE_H
#define JUCOMPILER_SYNTAX_TREE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct token{
    char *value;
    int num_linha;
    int num_coluna;
}token;

typedef struct node ast_tree;
struct node{
    token *token;
    char *type;
    ast_tree* filho;
    ast_tree* irmao;
    ast_tree* pai;
    char *anot;
};


token *gen_token(char *value, int num_linha, int num_coluna);
ast_tree *create_node(char * type,  token *token1);
void adicionar_filho(ast_tree *raiz,ast_tree *novo);
void adicionar_irmao(ast_tree *raiz,ast_tree *irmao);
int block_count(ast_tree *node);
void print_tree(ast_tree *root,int nivel);             //árvore - análise sintática
void print_tree_anotada(ast_tree *root,int nivel); //árvore anotada - análise semântica
void free_tree(ast_tree* root);
#endif //JUCOMPILER_SYNTAX_TREE_H

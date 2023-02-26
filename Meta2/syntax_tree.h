//
// Created by ricgo on 06/11/2022.
//

#ifndef JUCOMPILER_SYNTAX_TREE_H
#define JUCOMPILER_SYNTAX_TREE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node ast_tree;
struct node{
    char *value;
    char *type;
    ast_tree* filho;
    ast_tree* irmao;
    ast_tree* pai;
};



ast_tree *create_node(char *value,char * type);
void adicionar_filho(ast_tree *raiz,ast_tree *novo);
void adicionar_irmao(ast_tree *raiz,ast_tree *irmao);
int block_count(ast_tree *node);
void print_tree(ast_tree *root,int nivel);
void free_tree(ast_tree* root);
#endif //JUCOMPILER_SYNTAX_TREE_H

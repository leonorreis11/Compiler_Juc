//
// Created by ricgo on 06/11/2022.
//

#include "syntax_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
token *gen_token(char *value, int num_linha, int num_coluna){

    token *new= (token *)malloc(sizeof(token));
    new->value = (char *)strdup(value);
    new->num_linha = num_linha;
    new->num_coluna = num_coluna;
    return new;
}


ast_tree *create_node(char * type,  token *token1){

    ast_tree *new =malloc(sizeof(ast_tree));

    new->type = (char *)malloc(1 + strlen(type) * sizeof(char));
    strcpy(new->type, type);

    //criar token

    new->filho=NULL;
    new->irmao=NULL;
    new->pai=NULL;

    new->token = token1;

    return new;
}


void adicionar_filho(ast_tree *raiz,ast_tree *novo){
    if(novo==NULL){
        return;
    }
    if(raiz->filho==NULL){
        raiz->filho=novo;
        novo->pai=raiz;
    }else{
        ast_tree *temp;
        temp=raiz->filho;
        while(temp->irmao != NULL){
            temp = temp->irmao;
        }
        temp->irmao=novo;
        if(temp->pai != NULL){
            novo->pai = temp->pai;
        }
    }

}

void adicionar_irmao(ast_tree *raiz,ast_tree *irmao){
    if(raiz == NULL | irmao == NULL){
        return;
    }
    ast_tree *temp;
    temp = raiz;
    while(temp->irmao!=NULL){
        temp=temp->irmao;
    }
    temp->irmao = irmao;
    if(raiz->pai!=NULL){
        irmao->pai = raiz->pai;
    }
}

int block_count(ast_tree *node){
    int count=0;
    ast_tree *temp;
    temp = node;
    while(temp!=NULL){
        temp=temp->irmao;
        count++;
    }
    return count;
}

void print_tree(ast_tree *root,int nivel){
    for (int i = 0; i < nivel; i++){
        printf("..");
    }

    if (strcmp(root->token->value,"") )
    {
        printf("%s(%s)\n", root->type, root->token->value);
    }
    else{
        printf("%s\n", root->type);
    }

    if (root->filho)
        print_tree(root->filho, nivel + 1);
    if (root->irmao)
        print_tree(root->irmao, nivel);   
}

void print_tree_anotada(ast_tree *root,int nivel){
    for (int i = 0; i < nivel; i++){
        printf("..");
    }

    if (strcmp(root->token->value,"") )
            if(root->anot!= NULL)
                 printf("%s(%s) - %s\n",root->type,root->token->value, root->anot);
            else
                printf("%s(%s)\n", root->type, root->token->value);
    else{
        if(root->anot!= NULL)
            printf("%s - %s\n",root->type, root->anot);
        else
            printf("%s\n", root->type);
    }

    if (root->filho)
        print_tree_anotada(root->filho, nivel + 1);
    if (root->irmao)
        print_tree_anotada(root->irmao, nivel);   
}

void free_tree(ast_tree* root) {
    if (root != NULL) {
        if (root->filho != NULL) {
            free_tree(root->filho);
        }
        if (root->irmao != NULL) {
            free_tree(root->irmao);
        }


        
        free(root);
    }
}
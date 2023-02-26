//
// Created by ricgo on 06/11/2022.
//

#include "syntax_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

ast_tree *create_node(char *value,char * type){
    ast_tree *new =malloc(sizeof(ast_tree));

    new->type = (char *)malloc(1 + strlen(type) * sizeof(char));
    strcpy(new->type, type);

    new->value = (char *)malloc(1 + strlen(value) * sizeof(char));
    strcpy(new->value, value);


    new->filho=NULL;
    new->irmao=NULL;
    new->pai=NULL;
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

    if (strcmp(root->value,"") )
    {
        printf("%s(%s)\n", root->type, root->value);
    }
    else{
        printf("%s\n", root->type);
    }

    if (root->filho)
        print_tree(root->filho, nivel + 1);
    if (root->irmao)
        print_tree(root->irmao, nivel);

    
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
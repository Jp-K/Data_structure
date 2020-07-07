#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <algorithm>    // std::swap
#include<bits/stdc++.h>

using namespace std;

template<typename TIPO>
struct TElementoE
{
    TIPO dado;
    TElementoE<TIPO> *proximo;
};

template<typename TIPO>
struct TlistaE
{
    TElementoE<TIPO> * inicio;
};

template<typename TIPO>
bool inicializa_lista_enc(TlistaE<TIPO> &lista)
{
    lista.inicio = NULL;
}

template <typename TIPO>
int quantidade_lista (TlistaE<TIPO> lista)
{
    if (lista.inicio != NULL)           //1
    {
        int i=0;                        //1
        TElementoE<TIPO> * nav = lista.inicio; //1
        while(nav!=NULL) //n+1
        {
            nav=nav->proximo; //n
            i++;              //n
        }
        return i;             //1
    }
    else
    {
        return 0;             //1  = 3n+6
    }
}

template<typename TIPO>
bool insere_final_lista_enc(TlistaE<TIPO> &lista, TIPO dado)
{
    TElementoE <TIPO> *nav = lista.inicio;  //1
    if(lista.inicio != NULL)                //1
    {
        while(nav->proximo != NULL)         //n+1
        {
            nav = nav->proximo;             //n
        }
        TElementoE<TIPO> *novo = new TElementoE<TIPO>; //1
        novo->dado = dado;                             //1
        novo->proximo = NULL;                          //1
        nav->proximo = novo;                           //1
        return true;                                   //1
    }
    else
    {
        TElementoE<TIPO> *novo = new TElementoE<TIPO>; //1
        novo->dado = dado;                             //1
        novo->proximo = NULL;                          //1
        lista.inicio = novo;                           //1
        return true;                                   //1 = 2n+13
    }
}

template <typename TIPO>
bool remove_final (TlistaE<TIPO> &lista){
    if(lista.inicio == NULL)
    {
        return false;
    }

    else
    {
        TElementoE<TIPO> * nav = lista.inicio;
        if(nav->proximo == NULL)
        {
            lista.inicio = nav->proximo;
            delete nav;
            return true;
        }
        else
        {
            TElementoE<TIPO> * p = lista.inicio->proximo;
            while(p->proximo != NULL)
            {
                nav = nav->proximo;
                p = p->proximo;
            }
            nav->proximo = NULL;
            delete p;
            return true;
        }
    }
}

template <typename TIPO>
bool insere_inicio(TlistaE<TIPO> &lista, TIPO dado){
  TElementoE<TIPO> *novo = new TElementoE<TIPO>;  //1
  novo->dado = dado;                              //1
  novo->proximo = lista.inicio;                   //1
  lista.inicio = novo;                            //1
  return true;                                    //1 = 5
}

template <typename TIPO>
bool remove_inicio (TlistaE<TIPO> &lista){
if (lista.inicio != NULL){
    TElementoE<TIPO> * deletado = lista.inicio;
    lista.inicio=deletado->proximo;
    delete deletado;
    return true;
}
else {
    return false;
}

}
template<typename TIPO>
bool insere_posicao(TlistaE<TIPO> &lista, TIPO dado, int posicao)
{
    int quantidade=quantidade_lista(lista);
    if(quantidade<posicao)
    {
        return false;
    }
    if(quantidade==0)
    {
        TElementoE<TIPO> *novo = new TElementoE<TIPO>;
        novo->dado = dado;
        novo->proximo = NULL;
        lista.inicio = novo;
        return true;
    }
    else
    {
        TElementoE <TIPO> *nav = lista.inicio;
        TElementoE <TIPO> *aux = lista.inicio;
        for(int i=0;i!=posicao-1;i++)
        {
            nav = nav->proximo;
        }

        TElementoE<TIPO> *novo = new TElementoE<TIPO>;
        novo->dado = dado;
        novo->proximo = NULL;
        aux=nav->proximo;
        nav->proximo=novo;
        novo->proximo=aux;
        return true;
    }
}

template <typename TIPO>
bool remove_posicao(TlistaE<TIPO> &lista, int i)
{
    if (i < 0)
    {
        return false;
    }
    else if (quantidade_lista(lista) == i)
    {
        remove_final(lista);
    }
    else if (lista.inicio == NULL)
    {
        return false;
    }
    else if (quantidade_lista(lista)>i)
    {
        TElementoE <TIPO> *del = lista.inicio;
        TElementoE <TIPO> *aux = lista.inicio;
        TElementoE <TIPO> *ant = lista.inicio;
        for(int cont = 0; cont!=i-1; cont++)
        {
            ant = del;
            del = del->proximo;
        }
        aux = del->proximo;
        delete del;
        ant->proximo = aux;
    }
}

template<typename TIPO>
TElementoE<TIPO>* elem_na_posi(TlistaE<TIPO> &lista,int p){
  if(lista.inicio == NULL){
    return 0;
  }
  else{
    int contador = 0;
    TElementoE<TIPO> *navega = lista.inicio;
    while(navega->proximo != NULL && contador<p-1){
      contador++;
      navega = navega->proximo;
    }
    return navega;
  }
}

template <typename TIPO>
void ordenar_bubble(TlistaE<TIPO> &lista){
    int i,j;
    int qtd_lista = quantidade_lista(lista); //3n+7
    TElementoE<TIPO> *nave1 = lista.inicio;  // 1
    TElementoE<TIPO> *nave2 = lista.inicio;  // 1
    for(i=0;i<qtd_lista;i++){                // (n+1)*(
        for(j=0;j<qtd_lista;j++){            // n+1
            if(nave1->dado < nave2->dado){   // n
                swap(nave1->dado,nave2->dado); // 3n
            }
            nave2=nave2->proximo;              //n
        }                                      // )
        nave2 = lista.inicio;                  //n
        nave1 = nave1->proximo;                //n = 5n+9+(n+1)*(n+1+n+3n+n) = 6n^2+n+6n+1+5n+9 = 6n^2+12n+10
    }
}

template <typename TIPO>
void ordenar_cartas_quick(TlistaE<TIPO> &lista,int first, int last){
    int i, j, pivot;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        TElementoE<TIPO> *Ele_p = elem_na_posi(lista,pivot);
        TElementoE<TIPO> *Ele_i = elem_na_posi(lista,i);
        TElementoE<TIPO> *Ele_j = elem_na_posi(lista,j);
        while(i<j){
            while(Ele_i->dado<=Ele_p->dado&&i<last){
                i++;
                Ele_i = elem_na_posi(lista,i);
            }
            while(Ele_j->dado>Ele_p->dado){
                j--;
                Ele_j = elem_na_posi(lista,j);
            }
            if(i<j){
                swap(Ele_i->dado,Ele_j->dado);
            }
        }
        swap(Ele_p->dado,Ele_j->dado);
        ordenar_cartas_quick(lista,first,j-1);
        ordenar_cartas_quick(lista,j+1,last);
    }
}





#endif // LISTA_H_INCLUDED

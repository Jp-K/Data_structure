#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED
#include <algorithm> //biblioteca para o std::swap
using namespace std; //

template <typename TIPO>
struct TElementoDE{
    TIPO dado;
    TElementoDE<TIPO> *prox;
    TElementoDE<TIPO> *ant;
};

template <typename TIPO>
struct TListaDE{
    TElementoDE<TIPO> *inicio;
    TElementoDE<TIPO> *fim;
};


template <typename TIPO>
void inicializa_lista(TListaDE<TIPO> &lista){
    lista.inicio = NULL;
    lista.fim = NULL;
}

template <typename TIPO>
int qtd_lista(TListaDE<TIPO> &lista){
    if(lista.inicio == NULL){         //1
        return 0;                     //1
    }
    else{
        TElementoDE <TIPO> *busca;    //1
        busca = lista.inicio;         //1
        int contador = 1;             //1
        while(busca->prox != NULL){   //n
        contador++;                   //n
        busca=busca->prox;            //n  = 3n+1
        }
    return contador;
  }
}

template <typename TIPO>
TElementoDE<TIPO> * novo_elemento_lista(TIPO dado){
    TElementoDE<TIPO> * novo = new TElementoDE<TIPO>; //1
    novo->dado = dado;                                //1
    novo->prox = NULL;                                //1
    novo->ant = NULL;                                 //1
    return novo;                                      //1 = 5
}

template <typename TIPO>
bool insere_inicio_de(TListaDE<TIPO> &lista, TIPO dado){
    TElementoDE<TIPO> * novo = novo_elemento_lista(dado); //5 + 1
    novo->prox = lista.inicio;                            //1
    lista.inicio = novo;                                  //1
    if(novo->prox != NULL){                               //1
        TElementoDE<TIPO> * posterior = novo->prox;       //1
        posterior->ant = novo;                            //1
    }else{
        lista.fim = novo;                                 //1
    }
    return true;                                          //1 = 13
}

template <typename TIPO>
bool insere_fim_de(TListaDE<TIPO> &lista, TIPO dado){
    TElementoDE<TIPO> * novo = novo_elemento_lista(dado); // 5 + 1
    novo->ant = lista.fim;                                // 1
    lista.fim = novo;                                     // 1
    if (novo->ant != NULL){                               // 1
        TElementoDE<TIPO> * anterior = novo->ant;         // 1
        anterior->prox = novo;                            // 1
    }else{
        lista.inicio = novo;                              // 1
    }
    return true;                                          // 1
}
template <typename TIPO>
bool remove_inicio_de (TListaDE<TIPO> &lista){
    if(lista.inicio == NULL){
        return false;
    }
    TElementoDE<TIPO> * apagado = lista.inicio;
    lista.inicio = apagado->prox;
    if (lista.inicio!=NULL){
        lista.inicio->ant = NULL;
        if (lista.inicio->prox == NULL){
            lista.fim=lista.inicio;
        }
    }
    delete apagado;
    return true;
}

template <typename TIPO>
bool remove_fim_de(TListaDE<TIPO> &lista){
    if(lista.inicio == NULL){
        return false;
    }
    else if(lista.inicio == lista.fim){
        delete lista.inicio;
        lista.inicio = NULL;
        lista.fim = NULL;
        return true;
    }
    else{
        TElementoDE <TIPO> *aux = lista.fim->ant;
        delete lista.fim;
        lista.fim = aux;
        aux->prox = NULL;
        return true;
    }
}

template <typename TIPO>
bool insere_position_de (TListaDE<TIPO> &lista, TIPO dado, int posicao){
    if(posicao == 0){
        insere_inicio_de(lista, dado);
    }else{
        TElementoDE <TIPO> * nav = lista.inicio;
        for(int i=0; i<posicao-1 && nav != NULL; i++){
            nav=nav->prox;
        }
        if (nav != NULL){
            TElementoDE<TIPO> * novo = novo_elemento_lista(dado);
            novo->prox = nav->prox;
            novo->ant = nav;
            TElementoDE<TIPO> * posterior = novo->prox;
            if (posterior != NULL){
                posterior->ant = novo;
            }
            nav->prox = novo;
            return true;
        }else{
            return false;
        }
    }
}

template <typename TIPO>
bool remove_position_de (TListaDE<TIPO> &lista, int posicao){
    if (lista.inicio == NULL){
        return false;
    }
    if (posicao==0){
        remove_inicio_de(lista);
    }else{
        TElementoDE <TIPO> * nav = lista.inicio;
        for (int i=0; i<posicao-1 && nav!=NULL; i++){
            nav = nav->prox;
        }
        if (nav != NULL){
            TElementoDE<TIPO> *apagado = nav->prox;
        if (apagado != NULL){
            nav->prox = apagado->prox;
            if(apagado->prox != NULL){
                TElementoDE<TIPO> * posterior = apagado->prox;
                posterior->ant = nav;
            }else{
                lista.fim=nav;
            }
            delete apagado;
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
}

template <typename TIPO>
void bubblesort(TListaDE<TIPO> &lista){
    int i,j;
    int qtd = qtd_lista(lista);             // 3n+1+1
    TElementoDE<TIPO> *nav1 = lista.inicio; // 1
    TElementoDE<TIPO> *nav2 = lista.inicio; // 1
    for(i=0;i<qtd;i++){                     // n*
        for(j=0;j<qtd;j++){                 // (n+1
            if(nav1->dado < nav2->dado){    // n
                swap(nav1->dado,nav2->dado); // 3n
            }
            nav2=nav2->prox;                 //n)
        }
        nav2 = lista.inicio;                 //n
        nav1 = nav1->prox;                   //n = 5n+4+n*(5n+1) = 5n^2+6n+4
    }
}

template<typename TIPO>
TElementoDE<TIPO>* elem_pos_de(TListaDE<TIPO> &lista, int p){
  if(lista.inicio == NULL){
    return 0;
  }
  else{
    int contador = 0;
    TElementoDE<TIPO> *nav = lista.inicio;
    while(nav->prox != NULL && contador<p-1){
      contador++;
      nav = nav->prox;
    }
    return nav;
  }
}


template <typename TIPO>
void quicksort (TListaDE<TIPO> &lista,int first, int last){
    int i, j, pivot;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        TElementoDE<TIPO> *Ele_p = elem_pos_de(lista,pivot);
        TElementoDE<TIPO> *Ele_i = elem_pos_de(lista,i);
        TElementoDE<TIPO> *Ele_j = elem_pos_de(lista,j);
        while(i<j){
            while(Ele_i->dado<=Ele_p->dado&&i<last){
                i++;
                Ele_i = Ele_i->prox;
            }
            while(Ele_j->dado>Ele_p->dado){
                j--;
                Ele_j = Ele_j->ant;
            }
            if(i<j){
                swap(Ele_i->dado,Ele_j->dado);
            }
        }
        swap(Ele_p->dado,Ele_j->dado);
        quicksort(lista,first,j-1);
        quicksort(lista,j+1,last);
    }
}




#endif // LISTADE_H_INCLUDED

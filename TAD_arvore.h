#ifndef TAD_ARVORE_H_INCLUDED
#define TAD_ARVORE_H_INCLUDED

template <typename TIPO>
struct TElemento {
    TIPO dado;
    int chave;
    TElemento<TIPO> *direita;
    TElemento<TIPO> *esquerda;
};

template <typename TIPO>
struct Troot {
    TElemento<TIPO> *inicio;
};

template <typename TIPO>
bool inicializa_arvore (Troot<TIPO> &raiz){
    raiz.inicio = NULL;
}

template <typename TIPO>
void insere(TElemento<TIPO> *&no, TIPO dado, int chave){
    if (no == NULL){
    no = new TElemento<TIPO>;
    no->dado = dado;
    no->chave = chave;
    no->direita = NULL;
    no->esquerda = NULL;
    }else{
        if (chave > no->chave){
            insere (no->direita, dado, chave);
            }else{
                if (chave < no->chave){
                    insere (no->esquerda, dado, chave);
                }
            }
    }
    }

template <typename TIPO>
TIPO busca(TElemento<TIPO> *&no, int chave){
    if (no->chave == chave){
    return no->dado;
    }else{
        if (chave > no->chave){
            busca (no->direita, chave);
            }else{
                if (chave < no->chave){
                    busca (no->esquerda, chave);
                }
            }
    }
    }

template <typename TIPO>
void procura_remove(TElemento<TIPO> *&no, int chave){
    if(no != NULL){
        if(no->chave == chave){
            remover(no);
    }else{
        if(chave > no->chave){
            procura_remove(no->direita, chave);
        }else{
        procura_remove(no->esquerda, chave);
        }
    }
    }
}

template <typename TIPO>
void remover(TElemento<TIPO> *&no){
    TElemento<TIPO> * apagar;
    TElemento<TIPO> * maior = no->esquerda;
    if(maior == NULL){
        apagar = no;
        no = no->direita;
        delete apagar;
        return;
    }
    TElemento<TIPO> * pai = NULL;
    while (maior->direita !=NULL){
        pai = maior;
        maior = maior->direita;
    }
    maior->direita = no->direita;
    if (pai != NULL){
        pai->direita = maior->esquerda;
        maior->esquerda = no->esquerda;
    }
    apagar = no;
    no = maior;
    delete apagar;
}





#endif // TAD_ARVORE_H_INCLUDED

#ifndef ARVORE_SBB_H_INCLUDED
#define ARVORE_SBB_H_INCLUDED

const char VERTICAL = 'v';
const char HORIZONTAL = 'h';
template <typename TIPO>
struct TNo{
    int chave;
    TIPO dado;
    TNo<TIPO> * dir;
    char orientD;
    TNo<TIPO> * esq;
    char orientE;
};

template <typename TIPO>
void inicializa_arvore(TNo<TIPO>* &no){
    no->dir = NULL;
    no->esq = NULL;
}

template <typename TIPO>
void LL(TNo<TIPO> *&ap){
    TNo<TIPO> *ap1 = ap->esq;
    ap->esq = ap1->dir;
    ap1->dir = ap;
    ap1->orientE = VERTICAL;
    ap1->orientE = VERTICAL;
    ap = ap1;
}

template <typename TIPO>
void RR(TNo<TIPO> *&ap){
    TNo<TIPO> *ap1 = ap->dir;
    ap->dir = ap1->esq;
    ap1->esq = ap;
    ap1->orientD = VERTICAL;
    ap->orientD = VERTICAL;
    ap = ap1;
}

template <typename TIPO>
void LR(TNo<TIPO> *&ap){
    TNo<TIPO> *ap1 = ap;
    TNo<TIPO> *ap2 = ap1->esq;
    TNo<TIPO> *ap3 = ap2->dir;
    ap2->dir = ap3->esq;
    ap1->esq = ap3->dir;
    ap3->esq = ap2;
    ap3->dir = ap1;
    ap2->orientD = VERTICAL;
    ap1->orientE = VERTICAL;
    ap = ap3;
}

template <typename TIPO>
void RL(TNo<TIPO> *&ap){
    TNo<TIPO> *ap1 = ap->dir;
    TNo<TIPO> *ap2 = ap1->esq;
    ap1->orientE = VERTICAL;
    ap->orientD = VERTICAL;
    ap1->esq = ap2->dir;
    ap2->dir=ap1;
    ap->dir = ap2->esq;
    ap2->esq= ap;
    ap = ap2;
}

template <typename TIPO>
int inserir(TNo<TIPO> *&no,int chave, TIPO dado){
int n =0;
    if(no==NULL){
        no = new TNo<TIPO>;
        no->chave = chave;
        no->dado = dado;
        no->esq = NULL;
        no->dir = NULL;
        return 1;
    } else {
        if(chave > no->chave){
            n = inserir(no->dir, chave, dado);
            if (n==1){
                no->orientD = HORIZONTAL;
                n++;
            } else {
                if(n==2 && no->orientD == HORIZONTAL){
                    n=1;
                    if(no->dir->orientD==HORIZONTAL){
                        RR(no);
                    }else{
                        RL(no);
                    }
                } else {
                    n=0;
                }
            }
        }else {
            if(chave < no->chave){
                n = inserir(no->esq, chave, dado);
                if(n == 1){
                    no->orientE = HORIZONTAL;
                    n++;
                }else{
                    if((n==2) && (no->orientE == HORIZONTAL)){
                        n = 1;
                        if(no->esq->orientE == HORIZONTAL){
                            LL(no);
                        }else{
                            LR(no);
                        }
                    }
                }
            }
        }

    }
    return 0;
}

template <typename TIPO>
TIPO busca(TNo<TIPO> *&no, int chave){
    if (no->chave == chave){
    return no->dado;
    }else{
        if (chave > no->chave){
            busca (no->dir, chave);
            }else{
                if (chave < no->chave){
                    busca (no->esq, chave);
                }
            }
    }
}

template <typename TIPO>
void procura_remove(TNo<TIPO> *&no, int chave){
    if(no != NULL){
        if(no->chave == chave){
            remover(no);
    }else{
        if(chave > no->chave){
            procura_remove(no->dir, chave);
        }else{
        procura_remove(no->esq, chave);
        }
    }
    }
}

template <typename TIPO>
void remover(TNo<TIPO> *&no){
    TNo<TIPO> * apagar;
    TNo<TIPO> * maior = no->esq;
    if(maior == NULL){
        apagar = no;
        no = no->dir;
        delete apagar;
        return;
    }
    TNo<TIPO> * pai = NULL;
    while (maior->dir !=NULL){
        pai = maior;
        maior = maior->dir;
    }
    maior->dir = no->dir;
    if (pai != NULL){
        pai->dir = maior->esq;
        maior->esq = no->esq;
    }
    apagar = no;
    no = maior;
    delete apagar;
}

#endif // ARVORE_SBB_H_INCLUDED

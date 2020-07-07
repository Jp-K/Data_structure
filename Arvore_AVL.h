#ifndef ARVORE_AVL_H_INCLUDED
#define ARVORE_AVL_H_INCLUDED

template <typename TIPO>
struct TNo {
    TIPO dado;
    int chave;
    int bal;
    TNo<TIPO> *dir;
    TNo<TIPO> *esq;
};

template <typename TIPO>
struct Troot {
    TNo<TIPO> *inicio;
};

template <typename TIPO>
bool inicializa_arvore(Troot<TIPO> &no){
    no.inicio = NULL;
    return true;
}

template <typename TIPO>
int inserir(TNo<TIPO> *&no, int chave, TIPO dado){
    if(no==NULL){
        no = new TNo<TIPO>;
        no->chave = chave;
        no->dado = dado;
        no->esq = NULL;
        no->dir = NULL;
        return 1;
    }else{
        if(chave > no->chave){
            int n = inserir(no->dir, chave, dado);
            no->bal = no->bal + n;
            if(no->bal > 1){
                if(no->dir->chave > chave){
                    RL(no);
                }else{
                    RR(no);
                }
                return 0;
            }else{
                if(no->bal == 0){
                    return 0;
                }else{
                    return 1;
            }
        }
    }else{
        if(chave < no->chave){
            int n = inserir(no->esq, chave, dado);
            no->bal = no->bal - n;
            if(no->bal < -1){
                if(no->esq->chave > chave){
                    LL(no);
                }else{
                    LR(no);
                }
                return 0;
            }else{
                if(no->bal == 0){
                    return 0;
                }else{
                    return 1;
                }
            }
        }else{
            return 0;
        }
    }
}
}


template <typename TIPO>
void RR(TNo<TIPO> *&no) {
  TNo<TIPO>* a = no;
  TNo<TIPO>* b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  a->bal = 0;
  b->bal = 0;
  no = b;
}

template <typename TIPO>
void LL(TNo<TIPO> *&no) {
  TNo<TIPO>* b = no;
  TNo<TIPO>* a = b->esq;
  b->esq = a->dir;
  a->dir = b;
  a->bal = 0;
  b->bal = 0;
  no = a;
}

template <typename TIPO>
void LR(TNo<TIPO> *&no) {
  TNo<TIPO> *c= no;
  TNo<TIPO> *a= c->esq;
  TNo<TIPO> *b= a->dir;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  a->bal = 0;
  b->bal = 0;
  c->bal = 0;
  no = b;
}

template <typename TIPO>
void RL(TNo<TIPO> *&no) {
  TNo<TIPO> *a = no;
  TNo<TIPO> *c = a->dir;
  TNo<TIPO> *b = c->esq;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  a->bal = 0;
  b->bal = 0;
  c->bal = 0;
  no = b;
}




#endif // ARVORE_AVL_H_INCLUDED

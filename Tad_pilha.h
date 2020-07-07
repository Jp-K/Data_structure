#ifndef TAD_PILHA_H_INCLUDED
#define TAD_PILHA_H_INCLUDED

template<typename TIPO>
struct TElementoP
{
    TIPO dado;
    TElementoP<TIPO> *proximo;
};

template<typename TIPO>
struct TPilha
{
    TElementoP<TIPO> * inicio;
};

template<typename TIPO>
bool inicializa_pilha(TPilha<TIPO> &lista)
{
    lista.inicio = NULL;
}

template <typename TIPO>
bool push_pilha(TPilha<TIPO> &lista, TIPO dado){
  TElementoP<TIPO> *novo = new TElementoP<TIPO>;
  novo->dado = dado;
  novo->proximo = lista.inicio;
  lista.inicio = novo;
  return true;
}

template <typename TIPO>
TIPO pop_pilha(TPilha<TIPO> &lista){
    TIPO dado;
if (lista.inicio != NULL){
    TElementoP<TIPO> * deletado = lista.inicio;
    lista.inicio=deletado->proximo;
    dado = deletado->dado;
    delete deletado;
    return dado;
}
else {
    return false;
}

}


#endif // TAD_PILHA_H_INCLUDED

#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

template <typename TIPO, int MAX>
struct TElemento{
TIPO dado;
};

template <typename TIPO, int MAX>
struct TLista {
TElemento<TIPO, MAX> dados[MAX];
int quant;
};

template <typename TIPO, int MAX>
bool inicializa_baralho (TLista<TIPO, MAX> &lista){
    lista.quant = 0;
    return true;
}

template <typename TIPO, int MAX>
bool insere_final (TLista<TIPO, MAX> &lista, TIPO dado){

   if (lista.quant < MAX){
       lista.dados[lista.quant].dado=dado;
       lista.quant++;
       return true;
   } else {
      return false;
   }
}

template <typename TIPO, int MAX>
bool remove_final (TLista<TIPO, MAX> &lista){

if (lista.quant > 0){
    lista.quant--;
    return true;
} else {
    return false;
}
}

template <typename TIPO, int MAX>
bool qntd_cartas (TLista<TIPO, MAX> &lista){
    int a;
    a = lista.quant;
    return a;
}

template <typename TIPO, int MAX>
bool remove_inicio (TLista<TIPO, MAX> &lista){

if (lista.quant <= 0){
    return false;
} else {
    for (int i=0; i < lista.quant-1; i++){
        lista.dados[i]=lista.dados[i+1];
    }
    lista.quant--;
    return true;
}
}

template <typename TIPO, int MAX>
bool insere_inicio (TLista<TIPO, MAX> &lista, TIPO dado){

if (lista.quant >= 52){
    return false;
} else {

    for (int i = lista.quant-1; i > 0; i--){
        lista.dados[i]= lista.dados[i-1];
    }
    lista.dados[0]=dado;
    lista.quant++;
return true;
}
}

template <typename TIPO, int MAX>
bool insere_position (TLista<TIPO, MAX> &lista , TIPO dado, int position){

if (lista.quant >= MAX and position <= MAX){
    return false;
} else {

    for (int i = position; i > 0; i--){
        lista.dados[i]= lista.dados[i+1];
    }
    lista.dados[position]=dado;
    lista.quant++;
return true;
}
}

template <typename TIPO, int MAX>
bool remove_position (TLista<TIPO, MAX> &lista, int position){

if (lista.quant <= 0 and position > 0){
    return false;
} else {
    for (int i=position; i < lista.quant-1; i++){
        lista.dados[i]=lista.dados[i+1];
    }
    lista.quant--;
    return true;
}
}

template <typename TIPO, int MAX>
void bubblesort (TLista<TIPO, MAX> &lista){

int i, j, cond;
TElemento<TIPO, MAX> temp;
cond = 1;
for (i=lista.quant-1; (i >= 1) && (cond == 1); i--){
    cond = 0;
    for (j=0; j < i; j++){
        if (lista.dados[j+1] < lista.dados[j]){
            temp = lista.dados[j];
            lista.dados[j] = lista.dados[j+1];
            lista.dados[j+1] = temp;
            cond = 1;
        }
    }
}

}


#endif // LISTA_ESTATICA_H_INCLUDED

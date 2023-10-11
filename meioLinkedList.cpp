#include <iostream>
using namespace std;

struct No {
    int data;
    No* next;
};

void inserir(No* &head, int valor){
    No* novoNo = new No;
    novoNo->data = valor;
    novoNo->next=NULL;

    if(head == NULL){
        head = novoNo;
        return ;
    }

    No *aux = head;
    while (aux->next != NULL) {
        aux = aux -> next;
    }
    aux->next = novoNo;
}

void encontrarMeio(No *head){
    if(head == NULL){
        cout << "Lista vazia";
        return;
    }

    No *meio = head;
    No *atual = head;
    int cont = 0;

    while (atual != NULL){
        if(cont/2 == 1){
            meio = meio->next;
        }
        atual = atual->next;
        cont++;
    }
    cout << meio->data;
}

void printList(No *head) {
    No *atual = head;
    while (atual != NULL) {
        cout << atual->data << endl;
        atual = atual->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    No *lista = NULL;

    inserir(lista, 1);
    inserir(lista, 2);
    inserir(lista, 3);
    inserir(lista, 4);
    inserir(lista, 5);

    printList(lista);

    encontrarMeio(lista);

    while (lista != NULL) {
        No* temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
#include <iostream>
using namespace std;

struct No{
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

void circular(No* &head){
    if(head == NULL){
        cout << "Lista vazia" << endl;
        return;
    }

    No* atual = head;
    while(atual->next != NULL){
        atual = atual->next;
    }
    atual->next = head;
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

    cout << "\nLISTA ORIGINAL\n";
    printList(lista);

    cout << "\nLISTA CIRCULAR\n";
    circular(lista);
    printList(lista);

    while (lista != nullptr) {
        No* temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}

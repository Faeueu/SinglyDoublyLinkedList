#include <iostream>
using namespace std;

struct No{
    int data;
    No* anterior;
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

void maiorNo(No* &head){
    if(head == NULL){
        cout << "Lista vazia" << endl;
        return ;
    }

    No* atual = head;
    No* maior = head;

    while(atual != NULL){
        if(atual->data > maior->data){
            maior = atual;
        }
        atual = atual->next;
    }
    cout<< maior->data << " e o maior" << endl;
}

void printList(No *head) {
    No *atual = head;
    while (atual != NULL) {
        cout << atual->data << " -> ";
        atual = atual->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    No* lista = NULL;

    inserir(lista, 10);
    inserir(lista, 53);
    inserir(lista, 5);
    inserir(lista, 12);

    cout << "\nLISTA\n";
    printList(lista);

    maiorNo(lista);

    while (lista != nullptr) {
        No* temp = lista;
        lista = lista->next;
        delete temp;
    }
    return 0;
}

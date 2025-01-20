// Struttura nodo
struct nodo {
    int data;
    struct nodo* link;
} typedef nodo;

// Funzione per eliminare un nodo selezionato
nodo* EliminaSelezionato(nodo* head, nodo* particolare) {
    if (!head || !particolare) return head;  // Se la lista o il nodo selezionato sono NULL, non fare nulla

    // Caso in cui il nodo da eliminare è la testa della lista
    if (head == particolare) {
        head = head->link;  // Sposta la testa al nodo successivo
        free(particolare);  // Libera la memoria del nodo eliminato
        return head;
    }

    // Scorrere la lista per trovare il nodo da eliminare
    nodo* current = head;
    while (current != NULL) {
        if (current->link == particolare) {
            current->link = particolare->link;  // Salta il nodo da eliminare
            free(particolare);  // Libera la memoria del nodo eliminato
            return head;
        }
        current = current->link;  // Passa al nodo successivo
    }

    return head;  // Restituisce la lista aggiornata
}

// chiamata nel main 
//head = EliminaSelezionato(head, particolare);  // Elimina il nodo selezionato dalla lista

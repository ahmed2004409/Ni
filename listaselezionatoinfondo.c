// Funzione per spostare un nodo selezionato alla fine della lista
nodo* SelezionatoInFondo(nodo* head, nodo* particolare) {
    if (!head) return NULL;  // Se la lista è vuota, restituisci NULL
    else if (!particolare || !head->link) return head;  // Se il nodo da spostare è NULL o la lista ha solo un nodo, non fare nulla

    nodo* current = head;  // Puntatore per scorrere la lista
    nodo* lastnode = head; // Puntatore per trovare l'ultimo nodo

    // Trova l'ultimo nodo della lista
    while (lastnode->link) {
        lastnode = lastnode->link;
    }

    // Se il nodo da spostare è già l'ultimo, non fare nulla
    if (lastnode == particolare) return head;

    // Se il nodo da spostare è la testa della lista
    if (head == particolare) {
        head = head->link;  // Sposta la testa della lista al nodo successivo
        lastnode->link = particolare;  // Collega l'ultimo nodo al nodo da spostare
        particolare->link = NULL;  // Il nodo da spostare ora è l'ultimo
        return head;
    }

    // Scorri la lista per trovare il nodo da spostare
    while (current) {
        if (current->link == particolare) {
            current->link = particolare->link;  // Salta il nodo da spostare
            lastnode->link = particolare;  // Collega l'ultimo nodo al nodo da spostare
            particolare->link = NULL;  // Il nodo da spostare ora è l'ultimo
            break;
        }
        current = current->link;  // Passa al nodo successivo
    }

    return head;  // Restituisci la lista aggiornata
}

// chimata nel main:
head = SelezionatoInFondo(head, particolare);  // Sposta il nodo selezionato alla fine della lista

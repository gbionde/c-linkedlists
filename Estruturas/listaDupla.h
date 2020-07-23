struct tpNode{
	char info[20];
	tpPont *ant, *prox;
};

/*Cria e retorna um novo node.*/
tpNode* criarNode(char info[]){
	tpNode *caixa = new tpNode;
	
	strcpy(caixa->info, info); 
	caixa->ant = caixa->prox = NULL;

	return caixa;
}

/*Cria e insere um novo node de forma ordenada.*/
void inserir(tpNode **head, char info[]){
	tpNode *novo = criarNode(info), *local;
	tpNode *ant;

	if(*head == NULL){
		*head = novo;
	}else{
		ant = local = *head;
		
		while(local != NULL && stricmp(info, local->info) > 0){
			ant = local;
			local = local->prox;
		}

		novo->ant = ant;
		novo->prox = local;
		
		ant->prox = novo;
		local->ant = novo;
	}
}

/*Busca, remove e retorna um elemento da lista.*/
tpNode* retirar(tpNode **head, char info[]){
	tpNode *local, *ant, *aux;
	
	aux = local = *head;
	if(stricmp(local->info, info) == 0){
		local->prox->ant = NULL;
		*head = (*head)->prox;
	}else{
		ant = local;
		
		while(local != NULL && stricmp(local->info, info) != 0){
			ant = local;
			local = local->prox;
		}

		if(local != NULL){
			aux = local;
			ant->prox = local->prox;
			local->prox->ant = ant;
		}
	}

	delete(local);
	return aux;
}

/*Exibe o conteudo da lista.*/
void exibir(tpNode *head){
	while(head != NULL){
		printf("\n  Endereco: %x | Info: %s | Prox.: %8x | Anterior: %x", head, head->info, head->prox, head->ant);
		head = head->prox;
	}
}

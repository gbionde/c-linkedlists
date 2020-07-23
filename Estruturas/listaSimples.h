struct tpNode{
	char info[20];
	struct tpNode *prox;
};

typedef struct tpNode tpNode;

/*Aloca e retorna um novo node.*/
tpNode* criarNode(char info[]){
	tpNode *novo = (tpNode*)malloc(sizeof(tpNode));
	
	strcpy(novo->nome, info);
	novo->prox = NULL;

	return novo;
}

/*Cria e insere um novo node na lista, de forma ordenada.*/
void inserir(tpNode **head, char info[]){
	tpNode *novo = criarNode(info);
	tpNode *local, *ant;

	if(*head == NULL){
		*head = novo;
	}else{
		ant = local = *head;

		while(local != NULL && stricmp(info, local->info) > 0){
			ant = local;
			local = local->prox;
		}

		ant->prox = novo;
		novo->prox = local;
	}
}

/*Busca e remove um elemento da lista. Retorna o removido.*/
tpNode* retirar(tpNode **head, char info[]){
	tpNode *local, *ant, *aux;

	local = *head;
	if(stricmp(local->info, info) == 0){
		*head = local->prox;
	}else{
		ant = local;

		while(local != NULL && stricmp(local->info, info) != 0){
			ant = local;
			local = local->prox;
		}

		ant->prox = local->prox;
	}

	aux = local;
	
	free(local);
	local = NULL;

	return aux;
}

/*Exibe a lista.*/
void exibir(tpNode *head){
	while(head != NULL){
		printf("\nEndereco: %x | Info: %s | Prox.: %8x", head, head->info, head->prox);
		head = head -> prox;
	}	
}

struct tpPilha{
	char info[20];
	struct tpPilha *prox;
};

typedef struct tpPilha tpPilha;

/*Cria e retorna um node.*/
tpPilha* criarNode(char info[]){
	tpPilha *nova = (tpPilha*)malloc(sizeof(tpPilha));

	nova->prox = NULL;
	strcpy(nova->nome, info);

	return nova;
}

/*Cria e insere um novo node na pilha.*/
void push(tpPilha **head, char info[]){
	tpPilha *nova = criarNode(info);
	
	if(*head == NULL){
		*head = nova;
	}else{
		nova->prox = *head;
		*head = nova;
	}
}

/*Retira e retorna o elemento do topo da pilha.*/
tpPilha* pop(tpPilha **head){
	tpPilha *aux, *local;

	aux = local = *head;
	*head = (*head)->prox;

	free(local);
	local = NULL;

	return aux;
}

/*Verifica e retorna se a pilha esta vazia ou nao.*/
char isVazia(tpPilha *head){
	return head == NULL;
}

/*Exibe o conteudo da pilha.*/
void exibir(tpPilha *head){
	while(!isVazia(head)){
		printf("  Endereco: %x | Topo: %s | Prox. %x\n", head, head->info, head->prox);
		head = pop(head);
	}
}

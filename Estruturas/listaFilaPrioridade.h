struct tpNode{
	char info[20];
	int prioridade;
	tpNode *ant, *prox;	
};

struct tpDesc{
	int qtd;
	tpNode *inicio, *fim;
};

/*Inicializa a lista tornando-a pronta para uso.*/
void inicializar(tpDesc &desc){
	desc.qtd = 0;
	desc.inicio = desc.fim = NULL;
}

/*Cria um novo node para a fila.*/
tpNode* criarNode(char info[], int prioridade){
	tpNode *caixa = new tpNode;
	
	strcpy(caixa->info, info);
	caixa->prioridade = prioridade;
	caixa->ant = caixa->prox = NULL;
	
	return caixa;
}

/*Cria e insere um novo node na fila.*/
void enqueue(tpDesc &desc, char info[],  int prioridade){
	tpNode *nova = criarNode(info, prioridade);
	tpNode *local, *ant;
	
	if(desc.inicio == NULL){
		desc.inicio = desc.fim = nova;
	}else{
		if(prioridade >= desc.inicio->prioridade){	
			nova->prox = desc.inicio;
			desc.inicio->ant = nova;
			desc.inicio = nova;
		}else{
			if(prioridade <= desc.fim->prioridade){	
				nova->ant = desc.fim;
				desc.fim->prox = nova;
				desc.fim = nova;
			}else{
				ant = local = desc.inicio;

				while(local->prox != NULL && prioridade < local->prioridade){
					ant = local;
					local = local->prox;
				}
				
				nova->ant = ant;
				nova->prox = local;
		
				ant->prox = nova;
				local->ant = nova;
			}
		}
	}
	
	desc.qtd++;
}

/*Remove e retorna um elemento da fila.*/
tpNode* dequeue(tpDesc &desc){
	tpNode *local, *aux;
	
	aux = local = desc.inicio;
	desc.inicio = desc.inicio->prox;

	delete(local);
	desc.qtd--;
	
	return aux;
}

/*Exibe o conteudo da fila.*/
void exibir(tpDesc desc){
	while(desc.inicio != NULL){
		printf("Endereco: %x | Informacao: %s | Proximo: %8x | Anterior: %x\n", 
			desc.inicio, desc.inicio->info, desc.inicio->prox, desc.inicio->ant);

		desc.inicio = desc.inicio->prox;
	}
}

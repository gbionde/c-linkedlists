struct tpNode{
	char info[20];
	tpNode *ant, *prox;
};

struct tpDesc{
	int qtd;
	tpNode *inicio, *fim;
};

/*Inicializa a lista deixando-a pronta para uso.*/
void inicializar(tpDesc &desc){
	desc.qtd = 0;
	desc.inicio = desc.fim = NULL;
}

/*Cria um node duplamente encadeado.*/
tpNode* criarNode(char info[]){
	tpNode *caixa = new tpNode;
	
	strcpy(caixa->info, info); 
	caixa->ant = NULL;
	caixa->prox = NULL;

	return caixa;
}

/*Cria e insere uma novo node na lista dupla.*/
void inserir(tpDesc &desc, char info[]){
	tpNode *nova = criarNode(info);
	tpNode *local, *ant;
	
	if(desc.inicio == NULL){
		desc.inicio = desc.fim = nova;
	}else{
		if(stricmp(info, desc.inicio->info) <= 0){
			nova->prox = desc.inicio;
			desc.inicio->ant = nova;
			desc.inicio = nova;
		}else{
			if(stricmp(info, desc.fim->info) >= 0){
				nova->ant = desc.fim;
				desc.fim->prox = nova;
				desc.fim = nova;
			}else{
				
				ant = local = desc.inicio;
				while(local->prox != NULL && stricmp(info, local->info) > 0){
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

/*Procura, retira e retorna um elemento da lista.*/
tpNode* retirar(tpDesc &desc, char info[]){
	tpNode *local, *ant, *aux;
	
	if(stricmp(desc.inicio->info, info) == 0){
		aux = local = desc.inicio;

		desc.inicio->prox->ant = NULL;
		desc.inicio = desc.inicio->prox;
	}else{
		if(stricmp(desc.fim->info, info) == 0){
			aux = local = desc.fim;
		
			desc.fim->ant->prox = NULL;
		}else{
			ant = local = desc.inicio;

			while(local != NULL && stricmp(info, local->info) != 0){
				ant = local;
				local = local->prox;
			}

			if(local != NULL){
				aux = local;
				ant->prox = local->prox;
			}	
		}
	}

	delete(local);
	desc.qtd--;
	
	return aux;
}

/*Exibe o conteudo da lista.*/
void exibir(tpDesc desc){
	while(desc.inicio != NULL){
		printf("\n  Endereco: %x | Informacao: %s | Proximo: %8x | Anterior: %x", 
			desc.inicio, desc.inicio->info, desc.inicio->prox, desc.inicio->ant);

		desc.inicio = desc.inicio -> prox;
	}
}

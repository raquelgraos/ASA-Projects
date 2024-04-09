# ASA_p2
Pretende-se encontrar o maior número de saltos possível num grafo dirigido, considerando que as pessoas que se conhecem mutuamente são, imediatamente, contagiadas. 

Deste modo, após obter as listas de adjacências do grafo original e do transposto, aplica-se uma DFS iterativa no original, que verifica o estado de um nó: 
    - ainda não foi visitado (0);
    - já foi visitado (1);
    - já fechou (2);
    
que preenche uma dada stack com a ordem topológica inversa. 

Depois, itera por essa ordem e executa para cada nó uma DFS no grafo transposto, guardando as SCCs, novamente, numa dada stack ‘result’.

Por fim, itera outra vez pela ordem topológica inversa, guardando em cada nó o valor do maior salto entre si e a source do grafo. 
Para isto, explora os nós adjacentes e, caso pertençam a SCCs diferentes, atualiza o comprimento do salto do nó, com base no máximo entre o 
comprimento atual e o comprimento do salto do nó adjacente incrementado em 1. Se pertencerem à mesma SCC, sincroniza os nós para o máximo valor.

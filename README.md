# ASA_p1

Pretende calcular qual o lucro máximo que se pode obter cortando uma chapa sucessivamente na horizontal ou vertical.

Seguindo o método de programação dinâmica, é criada uma tabela inicializada a 0 com as dimensões da chapa (+1 para permitir indexação baseada em 1), que guarda o preço das peças dadas pelo input, nas posições da tabela correspondentes à dimensão das peças.
Depois, a tabela é preenchida por linhas, guardando, em cada célula, o valor máximo que se pode obter cortando a subchapa, ou seja, a chapa até à posição atual da tabela. Esse valor é determinado, comparando todos os cortes possíveis, verticais e horizontais, e escolhendo o que permite maior lucro. Assim, o lucro máximo que se pode obter cortando a chapa dada é dado pela última posição da tabela.

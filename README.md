# Reconhecimento Inteligente de Locutores na Modalidade Independente do Discurso

1º Objetivo: Importar um audio, extrair seu header e copiá-lo inteiramente para um segundo arquivo

2º Objetivo: Fazer o audio tocar de tras para frente

3º Objetivo: "Vamos extrair os formantes dos sinais. Primeiramente, precisamos de um algoritmo pra percorrer o sinal sob análise, dividindo-o em frames ou janelas, e selecionar só as janelas vozeadas. Para cada janela vozeada, extrairemos os formantes F1, F2, F3 e F4. Vc consegue implementar o seletor de janelas?"

Taxa de amostragem do sinal original, divide por 30 ms
Pegar uma quantidade de amostras na janela que seja potencia de 2 (nao necessariamente)

Implementação de Cepstron

Pegar os 4 maiores picos de amostra do início do sinal e depois, no meio, pegar um pico
Extrair as características (pitch e os 4 formantes)

Formantes: frequencia de ressonancia do trato vocal, particulares para cada locutor

Confecção do poster:
Logo abaixo do resumo, colocar o objetivo, depois enfatizar a metodologia (separando em passos), depois mostrar os testes e resultados, com conclusões.

Conseguir no mínimo 10 locutores gravando diferentes discursos (ex: 1 - um, 2 - dois, 3 - tres...)

O que mandar: 
@mainpage SIR
# Simulação Epidemiológica (SIR) 🧟‍♂

## ⚡ Autor

**Djalma Antony Lemos Rodrigues**


## 🌵 Sobre

O SIR é um projeto do final da disciplina Introdução às Técnicas de Programação do curso de Tecnologia da Informação - UFRN/IMD lecionada por [André Maurício Cunha Campos](https://github.com/amccampos).


## ✅ Checkpoints

**CP1:**

- [x] Implementação do modelo SIR e saída no terminal;
- [x] Leitura dos parâmetros iniciais de simulação à partir de um arquivo de texto;
- [x] Implementação do modelo SIR com saída em arquivo de texto csv;

**CP2:**

- [x] Plotagem dos gráficos de SIR após saída utilizando ferramente externa;
- [x] Implementação da simulação dos dois cenários de contenção;
- [x] Uso de Modularização, Ponteiros, Alocação Dinâmica, Structs e Manipulação de arquivos;


## 🤖 Como executar?

⚠️ **Os comandos a seguir irão utilizar o OS Linux como referência.**

⚠️ **O programa necessita de um arquivo contendo as entradas de dados, deste modo, você poderá utilizar o arquivo "data.txt".**

Antes de executar a aplicação, execute o seguinte comando:

```bash
  # Criar pasta onde ficarão os arquivos de saída
  $ mkdir out
```

Para executar a aplicação em sua máquina, execute os seguintes comandos:

```bash
  # Gerar o arquivo binário
  $ gcc main.c simulation.c -o simulation

  # Executar o arquivo
  $ ./simulation
```

Após a execução, serão gerados três arquivos com o formato **CSV** contendo os dados obtidos.


## 📈 Como plotar os gráficos?

Para plotar os gráficos, acesse o [link](https://repl.it/@lemosantony/graphic).

Nele você encontrará um script que irá gerar os gráficos a partir dos arquivos. Para inserir os arquivos clique no botão de opções (três pontos na vertical) e clique em _Upload file_, ou arraste os arquivos diretamente na raíz do site.

Altere a linha
```python
content = [line.split(',') for line in open("results_[number].csv", "r").readlines()]
```
e no lugar de `[number]` insira o número presente no arquivo escolhido.


## ☹ Limitações

O nome do arquivo de entrada de dados pecisa ser obrigatoriamente `data.txt`. Além disso, a apresentação atual dos valores (separados por um espaço) também precisará ser mantida.

---

Desenvolvido com 💜 por Antony Lemos 🧑🏽‍🚀
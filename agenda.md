# Estrutura de dado linear: uma revisão baseada em projeto.

Nesta primeira atividade você precisa implementar e testar as estruturas de dados básicas (vetor, lista encadeadas) que usaremos para implementar os algoritmos estudados ao longo do curso. 

Para isso, usaremos uma tarefa que precisa ser implementada de forma individual. Em caso de dúvida sobre este enunciado ou como implementar as estruturas faça contato com o professor.

## Estrutura de dado linear

Uma estrutura dado linear permite que os seus elementos sejam dispostos de forma sequencial. Cada elemento apresenta uma relação com o anterior e próximo. Em geral as operações realizadas são posicionais, e.g., inserir e remover do inicio. Nesses casos essas estruturas são eficientes na manipulação dos dados.

- Lista encadeada
- Vetor
- Fila
- Pilhas


## A tarefa
Sua primeira tarefa será a construção de um programa em C que implementa o conceito de uma agenda de atividades. A agenda deve registrar eventos que são descritos como segue:

- a data do evento, na forma dia/mes/ano hora:minuto
- a descricao do evento, um texto com até 140 caracteres
- a prioridade do evento, um texto com até 10 caracteres

## A interface da Agenda.
A agenda deve ser manipulada através de um conjunto de operações, chamada de interface. Essas operações devem permiter que eventos sejam inseridos e consultados.

A operação de inserção de um evento ocorrer sempre a partir de informação completa dos dados associados a um evento.

A operação de consulta de eventos na agenda deve sempre retornar qual é o próximo evento que irá acontecer conforme ordem estabelecida pela data dos eventos.

Uma operação que precisa ser implementada é uma que determina a quantidade de eventos ainda agendados.

## Como nomear as operações da agenda

1. criar_agenda(): essa operação deve criar uma agenda capaz de comportar um número ilimitado de eventos

2. agendar_evento(): essa operação deve agendar um evento em uma agenda previamente criada

3. proximo_evento(): essa operação deve retornar o evento que está na eminência de acontecer (o primeiro evento da agenda);

4. finalizar_evento(): essa operação deve remover o primeiro evento da agenda.

## Como a sua implementação será testada.



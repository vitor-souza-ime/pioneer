# Pioneer 3-AT Controle com Webots

Este repositório contém uma implementação de controle reativo para o robô quadrúpede **Pioneer 3-AT** utilizando o simulador **Webots**. O código em `main.c` exemplifica uma arquitetura simples baseada em sensores ultrassônicos, capaz de detectar obstáculos e reagir com manobras básicas de evasão.

##  Repositório
https://github.com/vitor-souza-ime/pioneer

---

##  Estrutura do Projeto

- `main.c`: implementa o controle do robô Pioneer 3-AT, incluindo leitura de sensores, lógica de navegação reativa e controle de motores.
- (Opcional) Outros arquivos de configuração ou simulação podem estar presentes conforme a organização do projeto.

---

##  Funcionamento

O controlador foi desenvolvido em linguagem C utilizando as bibliotecas do Webots:
- Inicializa o robô e suas rodas (configuradas em posição `INFINITY` para modo de velocidade).
- Ativa 16 sensores ultrassônicos (`so0` a `so15`) com tempo de amostragem baseado na constante `TIME_STEP` (32 ms).
- Lê continuamente os valores dos sensores e imprime suas leituras no console.
- Implementa uma simples lógica de evitação de obstáculos:
  - Se um obstáculo for detectado atrás (sensor `so11`) com valor menor que 150, o robô recua e gira à esquerda.
  - Se um obstáculo for detectado à frente (sensor `so3`) com valor menor que 150, o robô avança e gira à direita.
  - Caso contrário, continua movendo-se para frente a velocidade constante.


##  Como Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/vitor-souza-ime/pioneer.git
````

2. Abra o projeto no **Webots** e carregue o mundo contendo o robô **Pioneer 3-AT**.

3. Configure o controlador robótico para usar o arquivo `main.c`.

4. Execute a simulação e observe o comportamento do robô em resposta aos obstáculos.

---

## Dependência

* **Webots** (versão compatível com o Pioneer 3-AT)
* (Se aplicável) Mundo de simulação personalizado contendo o robô e sensores.

---

## Licença

Discutir o tipo de licença do código aqui. Se for um exemplo educacional, mencione "para uso educacional" ou "sem licença específica". Caso contrário, especifique conforme aplicável (por exemplo, Apache-2.0).


## Possíveis Extensões Futuras

* Adicionar comportamentos de navegação mais avançados (como parede lateral).
* Integrar algoritmos de planejamento (ATO, SLAM, visão computacional).
* Implementar controle mais suave ou adaptativo usando feedback de sensores adicionais.

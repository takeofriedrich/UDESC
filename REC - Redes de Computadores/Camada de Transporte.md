# Camada de Transporte

É o meio lógico para transferir dados entre dois pontos da internet

É responsável por prestar serviços a camada de aplicação. Recebe da camada de rede e fornece a camada de aplicação.

## Endereçamento

Forma mais comum de se comunicar processo a processo é através do paradigma cliente-servidor. Ambos os processos no cliente e no servidor possuem o mesmo nome.

- **Endereço de IP**: define a estação
- **Porta**: define o processo nessa estação

O ICAANN dividiu:

- 0 até 1023: portas bem conhecidas (no UNIX /etc/services)
- 1024 até 49152: portas registradas
- 49152 até 65535: portas dinâmicas ou privadas

Para listas essas portas no Linux:

```bash
cat /etc/services
```

## Endereço de Socket

É a combinação entre um endereço de IP e uma porta.

Ex.: 200.23.56.8:69

## Enviando mensagens entre dois processos

Para fazer isso, o protocolo da camada de transporte encapsula e desencapsula a mensagem.

- **Multiplexação**: na origem (muitos para um)
- **Demultiplexação**: no destino (um para muitos)

## Controle de fluxo

Entidades envolvidas:

- Processo emissor
- Camada de transporte do emissor
- Camada de transporte do receptor
- Processo receptor

Uma das implementações possíveis utiliza buffers para armazenar as mensagens trocadas entre o processo emissor e o processo receptor

## Controle de erros

Responsabilidades:

- Detectar e se livrar de pacotes corrompidos
- Reconhecer pacotes que foram recebidos mais de uma vez
- Perceber pacotes que não foram recebidos e os requisitar novamente
- Deixar os pacotes no buffer fora de ordem até que todos os faltantes cheguem

Entidades envolvidas:

- Camada de transporte emissora
- Camada de transporte receptora

A camada de transporte emissora precisa saber qual pacote deve reenviar e a receptora, quais vieram duplicados e quais estão fora de ordem.

Receptor pode enviar um ACK (acknowledgment) confirmando que recebeu o pacote. É utilizado um timer para que o emissor saiba que o pacote foi recebido com sucesso.

## Combinação entre o controle de erros e o de fluxo

### No emissor:

- a próxima posição livre do buffer é usado como número de sequência do pacote.
- quando o pacote é enviado, uma cópia dele fica no lugar aguardando a confimação do recebimento.
- quando a confimação chega, a cópia é eliminada e a posição de memória fica livre

### No receptor:

- quando um pacote com número de sequência y chega, ele fica aguardando até que a camada de aplicação o utilize.
- uma confirmação é enviada ao emissor de que o pacote foi recebido

### Janela deslizante:

O buffer é representado como um pedaço do circulo.

### Controle de congestionamento:

Mecanismos e técnicas que evitam com que os buffers fiquem sobrecarregados. Esse congestionamento pode acabar sendo transmitido para as outras camadas (aplicação e rede).

### Protocolos de controle de fluxo e erro

#### Stop and wait: **(Slide 40)**

Apenas um pacote é enviado por vez, caso um pacote ou o ACK seja perdido o pacote é reenviado. Esse "perdido" é controlado por um timer no receptor e no emissor. O ACK é enviado junto com o número de sequência do próximo pacote que deve ser enviado.

Considerações:

- é ineficiente se o canal for largo(elevada taxa de transferencia de dados) e comprido(atraso relativo no tempo de ida e volta).
- desvantegem: o emissor precisa aguardar que o receptor receba para poder enviar o próximo.

#### Go-Back-N: **(Slide 46)**

Múltiplos pacotes podem ser enviados ao mesmo tempo antes de se receber uma confirmação. O receptor só pode manter um no buffer. Mantém uma cópia dos pacotes enviados até que as confirmações cheguem.

Considerações:

- cada vez que um pacote é perdido ou corrompido o emissor reenvia todos os pendentes, podendo congestionar a rede;
- pode colapsar a rede pois se houver congestionamento devido a perda de pacotes, esse protocolo começa a reenviar os pendentes e gerar mais congestionamento.

#### Repetição seletiva: **(Slide 50)**

Reenvia apenas pacotes selecionados

#### Sobre esses protocolos:

Eles são unidirecionais, isto é, o fluxo dos pacotes se da em uma direção e as confirmações na outra. Normalmente os pacotes precisam fluir em ambos os sentidos (cliente para servidor e servidor para cliente).

## Procolos da Camada de Transporte:

### UDP: User Datagram Protocol (não confiável)

- simplicidade e eficiência
- tratamento de erro pode ser realizado direto na camada de aplicação

### TCP: Transmission Control Protocol (orientado a conexão)

- utilizado onde a confiabilidade é um fator importante

### SCTP: Stream Control Transmission Protocol

- utilizado para streams: netflix, amazon prime video, tv ao vivo, etc.

## UDP: **(slide 60)**

Uso mínimo de recursos, utilizado pelo DNS na maioria dos casos. 

- **Cabeçalho**: tamanho fixo de 8 bytes constituido de 4 campos de 2 bytes:
    - Número da porta de origem
    - Número da porta de destino
    - Comprimento total
    - Soma de verificação

No UDP não há controle de congestionamento, ele considera que os pacotes são pequenos de mais para causar congestionamentos na rede.

## TCP:

É um protocolo orientado a fluxo. O TCP permite que o emissor e o receptor "conversem" como se fosse por um tubo, trocando fluxo de bytes de uma ponta com a outra (ver slide 62). A comunicação é full-duplex. Esse é o protocolo que acontece a Multiplexação e a Demultiplexação.

### Buffers de envio e recepção:

Tanto emissor quanto receptor precisam ter um buffer para armazenamento temporário (ver slide 64).

### Fases do TCP:

- Estabelecimento da conexão
- Transmissão de dados
- Fechamento da conexão

### Segmento (ver slide 71):

#### Cabeçalho:

- Endereçamento de porta de origem (16 bits);
- Endereçamento de porta de destino (16 bits);
- Número de sequência (32 bits);
- Número de confirmação (32 bits);
- HLEN (4 bits);
- Reservado (6 bits);
- Confirmações (12 bits):
    - URG: ponteiro de urgência é válido
    - ACK: confirmação de recebimento
    - PSH: pedido de push
    - RST: reiniciar conexão
    - SYN: sincronizar números de sequência
    - FIN: finalizar a conexão
- Tamanho da janela (16 bits);
- Soma de verificação (16 bits);
- Ponteiro de urgência (16 bits);
- Opções de preenchimento (padding) (até 40 bytes)

### Características:

- **three-way handshaking**: estabelecimento de conexão no TCP. Três "hand-shaking's" (slide 75).






















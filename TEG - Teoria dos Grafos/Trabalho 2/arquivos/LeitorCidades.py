from modelos.Grafo import Grafo
from modelos.Estado import Estado


class LeitorCidades:

    def __init__(self, caminho='files/cidades.txt', direcionado=True):
        self.__caminho = caminho
        self.__direcionado = direcionado

    def setCaminho(self, caminho):
        self.__caminho = caminho

    def getCaminho(self):
        return self.__caminho

    def setNaoDirecionado(self):
        self.__direcionado = False

    def setDirecionado(self):
        self.__direcionado = True

    def leCidades(self):
        f = open(self.__caminho, 'r')
        arquivo = f.readlines()
        if(len(arquivo) > 1):
            grafo = Grafo()
            estado = Estado()
            if not self.__direcionado:
                grafo.setNaoDirecionado()
            try:
                nomeEstado = arquivo[0].replace('\n', '')
                estado.setNome(nomeEstado)
            except Exception as e:
                raise Exception('Erro durante a leitura do nome do estado')
            for i in range(2, len(arquivo), 4):
                try:
                    cidade1 = arquivo[i].replace('\n', '')
                    cidade2 = arquivo[i+1].replace('\n', '')
                    distancia = int(arquivo[i+2])
                    a = int(estado.addCidade(cidade1))
                    b = int(estado.addCidade(cidade2))
                    nos = grafo.getNumeroNos()
                    if a >= nos:
                        qnt = a - nos
                        for aux in range(qnt + 1):
                            grafo.insereNo()
                    nos = grafo.getNumeroNos()
                    if b >= nos:
                        qnt = b - nos
                        for aux in range(qnt + 1):
                            grafo.insereNo()
                    grafo.insereArco(a, b, distancia)
                except Exception as e:
                    raise Exception('Erro durante a leitura do arquivo')
            estado.setGrafo(grafo)
            return estado
        else:
            raise Exception('Erro ao ler o grafo - Não nada no arquivo')

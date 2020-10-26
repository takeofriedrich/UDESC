from modelos.Grafo import Grafo


class LeitorGrafo:

    def __init__(self, caminho='files/grafo.txt'):
        self.__caminho = caminho

    def setCaminho(self, caminho='files/grafo.txt'):
        self.__caminho = caminho

    def getCaminho(self):
        return self.__caminho

    def lerArquivo(self):
        f = open(self.__caminho, 'r')
        for i in f.readlines():
            print(i)

    def leGrafo(self):
        f = open(self.__caminho, 'r')
        arquivo = f.readlines()
        if(len(arquivo) > 1):
            grafo = Grafo()
            for i in range(len(arquivo)):
                grafo.insereNo()
            for i in range(len(arquivo)):
                if len(arquivo[i]) > 0:
                    arcos = arquivo[i].split(
                        ':')[1].replace('\n', '').split(' ')
                    max = len(arcos)
                    arcos = arcos[1:max]
                    for aresta in arcos:
                        if len(aresta) > 0:
                            grafo.insereArco(i, int(aresta))
            return grafo
        else:
            raise Exception('Erro ao ler o grafo - Não nada no arquivo')

    def salvaGrafo(self, grafo):
        f = open(self.__caminho, 'a')
        matriz = grafo.getMatrizAdjacente()
        for chave in matriz.keys():
            s = ''
            s += str(chave)
            s += ': '
            for no in range(len(matriz[chave])):
                if(matriz[chave][no] != 0):
                    s += str(no) + ' '
            s += '\n'
            f.write(s)

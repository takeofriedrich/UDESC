from modelos.Grafo import Grafo


class LeitorGrafo:

    def __init__(self, caminho='files/grafo.txt', direcionado=True):
        self.__caminho = caminho
        self.__direcionado = direcionado

    def setCaminho(self, caminho='files/grafo.txt'):
        self.__caminho = caminho

    def getCaminho(self):
        return self.__caminho

    def setNaoDirecionado(self):
        self.__direcionado = False

    def setDirecionado(self):
        self.__direcionado = True

    def leGrafo(self):
        f = open(self.__caminho, 'r')
        arquivo = f.readlines()
        if(len(arquivo) > 1):
            grafo = Grafo()
            if not self.__direcionado:
                grafo.setNaoDirecionado()
            for i in range(len(arquivo)):
                if len(arquivo[i]) > 0:
                    arcos = arquivo[i].replace('\n', '').split(' ')
                    a = int(arcos[0])
                    b = int(arcos[1])
                    c = int(arcos[2])
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
                    grafo.insereArco(a, b, c)
            return grafo

        else:
            raise Exception('Erro ao ler o grafo - Não nada no arquivo')

    def __salvaDirecionado(self, grafo):
        f = open(self.__caminho, 'a')
        matriz = grafo.getMatrizAdjacente()
        for i in matriz.keys():
            for j in range(len(matriz[i])):
                if matriz[i][j] == 1:
                    s = ''
                    s += str(i)
                    s += ' '
                    s += str(j)
                    s += ' '
                    s += str(grafo.getMatrizPesos()[i][j])
                    s += '\n'
                    f.write(s)

    def __salvaNaoDirecionado(self, grafo):
        f = open(self.__caminho, 'a')
        matriz = grafo.getMatrizAdjacente()
        for i in matriz.keys():
            for j in range(i, len(matriz[i])):
                if i == j:
                    pass
                if matriz[i][j] == 1:
                    s = ''
                    s += str(i)
                    s += ' '
                    s += str(j)
                    s += ' '
                    s += str(grafo.getMatrizPesos()[i][j])
                    s += '\n'
                    f.write(s)

    def salvaGrafo(self, grafo):
        if self.__direcionado:
            self.__salvaDirecionado(grafo)
        else:
            self.__salvaNaoDirecionado(grafo)

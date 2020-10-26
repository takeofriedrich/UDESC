from graphviz import Graph
import os
import imageio

class Grafo:

    caminho = "imagens/"
    i = 0

    def __init__(self, direcionado=True):
        self.__matrizAdjacente = {}
        self.__direcionado = direcionado
        self._dot = None
        self.__images = []

    def setDirecionado(self):
        self.__direcionado = True

    def setNaoDirecionado(self):
        self.__direcionado = False

    def isDirecionado(self):
        return self.__direcionado

    def getNumeroNos(self):
        return len(self.__matrizAdjacente)

    def __novaLinha(self):
        lista = []
        for i in range(self.getNumeroNos()):
            lista.append(0)
        return lista

    def getMatrizAdjacente(self):
        return self.__matrizAdjacente

    def insereNo(self):
        self.__matrizAdjacente[self.getNumeroNos()] = self.__novaLinha()
        if(self.getNumeroNos() > 0):
            for no in self.__matrizAdjacente:
                self.__matrizAdjacente[no].append(0)

    def removerNo(self, no):
        for i in self.__matrizAdjacente.keys():
            self.__matrizAdjacente[i].pop(self.procuraIndex(no))

        self.__matrizAdjacente.pop(no)

    def procuraIndex(self, no):
        cont = 0
        for i in self.__matrizAdjacente.keys():
            if i == no:
                return cont
            else:
                cont += 1
        raise Exception('No não existe')

    def insereArco(self, a1, a2):
        if(a1 < self.getNumeroNos() and a2 < self.getNumeroNos()):
            self.__matrizAdjacente.get(a1)[a2] = 1
            if not self.isDirecionado():
                self.__matrizAdjacente[a2][a1] = 1
        else:
            return False

    def transformaEmNaoDirecionado(self):
        max = len(self.__matrizAdjacente)
        for i in range(0, max):
            for j in range(0, max):
                if self.__matrizAdjacente[i][j] == 1:
                    self.__matrizAdjacente[j][i] = 1
        self.setNaoDirecionado()

    def removeArco(self, no1, no2):
        if no1 > self.getNumeroNos() or no2 > self.getNumeroNos():
            raise Exception('Arco não existe')
        else:
            self.__matrizAdjacente[no1][no2] = 0
            if not self.isDirecionado:
                self.__matrizAdjacente[no2][no1] = 0

    def grau(self, no):
        return sum(self.__matrizAdjacente[no])

    def __criaArrayVisitados(self, numerico=False):
        visitados = []
        tipo = None
        if(not numerico):
            tipo = False
        else:
            tipo = 0
        for i in range(self.getNumeroNos()):
            visitados.append(tipo)
        return visitados

    # aoVisitar e aoSair são as funções passadas como parâmetro, a serem criadas depois
    def dfs(self, origem, aoVisitar, aoSair):
        self.__resursaoDFS(
            origem, self.__criaArrayVisitados(), aoVisitar, aoSair)

    def __resursaoDFS(self, no, visitados, aoVisitar, aoSair):
        visitados[no] = True
        aoVisitar(no)
        for i in range(self.getNumeroNos()):
            if i != no and visitados[i] == False:
                if self.__matrizAdjacente[no][i] == 1:
                    self.__resursaoDFS(i, visitados, aoVisitar, aoSair)
                    aoSair(no)

    # aoVisitar e aoSair são as funções passadas como parâmetro, a serem criadas depois
    def buscaLargura(self, origem, aoVisitar):
        niveis = self.__criaArrayVisitados(numerico=True)
        visitador = self.__criaArrayVisitados()

    def __str__(self):
        grafo = 'X '
        for no in self.__matrizAdjacente.keys():
            grafo += str(no) + ' '
        grafo += "\n"
        i = 0
        for no in self.__matrizAdjacente.keys():
            grafo += str(no) + ' '
            for elemento in self.__matrizAdjacente[no]:
                grafo += str(elemento)
                grafo += str(" ")
            i += 1
            grafo += '(' + str(self.grau(no)) + ')'
            grafo += "\n"
        return grafo

    def todosN(self, n):
        for i in range(self.getNumeroNos()):
            if self.grau(i) != n:
                return False
        return True

    def __renderiza(self):
        s = Grafo.caminho+'grafo'+str(Grafo.i)
        self.__dot.render(s, view=False, format='jpg')
        Grafo.i += 1
        #os.remove(s)
        self.__images.append(imageio.imread(s+'.jpg'))

    def toGraphviz(self):
        self.__dot = Graph(engine='neato')
        for no in self.__matrizAdjacente.keys():
            self.__dot.node(str(no))
        if self.__direcionado:
            for i in range(self.getNumeroNos()):
                for j in range(self.getNumeroNos()):
                    if(self.__matrizAdjacente[i][j] == 1):
                        self.__dot.edge(str(i), str(j), constraint='false')
        else:
            for i in range(self.getNumeroNos()):
                for j in range(i, self.getNumeroNos()):
                    if(self.__matrizAdjacente[i][j] == 1):
                        self.__dot.edge(str(i), str(j), constraint='false')

    def pinta(self,no, cor):
        self.__dot.node(str(no), _attributes={'style': 'filled', 'color': cor})

    def aoVisitar(self,no):
        self.pinta(no,'#825287')
        self.__renderiza()

    def aoSair(self,no):
        self.pinta(no,'#D8BDDC')
        self.__renderiza()

    def reinicia(self):
        Grafo.i = 0

    def gif(self):
        imageio.mimsave('gif.gif', self.__images)
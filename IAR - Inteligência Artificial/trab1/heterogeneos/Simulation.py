from copy import copy, deepcopy
import sys
import time as timee
from typing import Any
from datetime import datetime
import math

from Ant import Ant
from Grid import Grid
from Data import Data
import random


class Simulation:

    alpha = None
    k1 = None
    k2 = None
    ray = 1
    stop = False
    ocios = 0
    limiter = 1

    def __init__(self, era, dados=None, n=50, m=50) -> None:

        self.__era = era
        # if n == m:
        #     m = m - 1
        self.__grid = Grid(n=n, m=m)
        self.__generateDatas(datas=dados)
        self.__ants = {}
        self.__generateAnt()
        self.__miopenyze = 0
        if dados is None:
            self.__hasLabels = False
        else:
            self.__hasLabels = True
        self.calculateAlpha()

    def getEra(self) -> int:
        return self.__era

    def hasLabels(self) -> bool:
        return self.__hasLabels

    def get(self, i, j) -> Any:
        return self.__grid.get(i, j)

    def getDataAtributes(self, i, j) -> list:
        return self.__grid.get(i, j).getDatas()

    def getDataAtributesFromAnts(self, i, j) -> list:
        return self.getAntInPoint(i, j).getData()

    # 0 se formiga 1 se dado e 2 se None
    def getTypeInGrid(self, i: int, j: int) -> Any:
        tipo = self.__grid.getTypeInGrid(i, j)
        return 0 if self.__hasAntInPoint(i, j) else 1 if tipo == 1 else 2

    def getN(self) -> int:
        return self.__grid.getN()

    def getM(self) -> int:
        return self.__grid.getM()
    # Para cada 10 casas da matriz, 1 vai conter um data

    def getNumberOfData(self) -> int:
        return self.__numberOfDatas

    def getNumberOfAnts(self) -> int:
        return len(self.__ants)

    def getAntsPositions(self) -> list:
        return list(self.__ants.values())

    def getAntInPoint(self, i, j) -> Ant:
        for ant in self.__ants:
            if self.__ants[ant] == [i, j]:
                return ant
        return None

    def miopes(self, signal) -> None:
        for ant in self.__ants:
            ant.miope(signal)

    def __generateDatas(self, datas=None) -> None:

        maxi = None
        if datas is None:
            self.__numberOfDatas = int(
                (self.__grid.getN() * self.__grid.getM())/10)
            maxi = self.__numberOfDatas + 1
        else:
            self.__numberOfDatas = len(datas)
            maxi = self.__numberOfDatas
        for data in range(maxi):
            posI = random.randint(0, self.__grid.getN()-1)
            posJ = random.randint(0, self.__grid.getM()-1)
            maxTrys = 0
            while(self.__grid.isOcupated(posI, posJ)):
                posI = posI - 1
                posJ = posJ - 1
                if posI < 0:
                    posI = self.__grid.getN() - 1
                if posJ < 0:
                    posJ = self.__grid.getM() - 1
                maxTrys += 1
                if maxTrys == self.__grid.getN() * self.__grid.getM():
                    maxTrys = 0
                    posI = random.randint(0, self.__grid.getN()-1)
                    posJ = random.randint(0, self.__grid.getM()-1)
            random.seed(timee.time())
            propriedades = None
            if datas is None:
                tamanho = random.randint(1, 15)
                peso = random.randint(1, 15)
                propriedades = Data(datas=[tamanho, peso])
                dado = Data(datas=propriedades)
            else:
                tamanho = datas[data][0]
                peso = datas[data][1]
                label = datas[data][2]
                propriedades = Data(
                    datas=[tamanho, peso, label], hasLabel=True)
                dado = Data(datas=propriedades)
            self.__grid.put(propriedades, posI, posJ)

    def __generateAnt(self) -> None:
        self.__nroAnts = int((self.__numberOfDatas/10)+1)
        for i in range(self.__nroAnts):
            posI = random.randint(0, self.__grid.getN()-1)
            posJ = random.randint(0, self.__grid.getM()-1)
            maxTrys = 0
            while(self.__grid.isOcupated(posI, posJ)):
                posI = posI - 1
                posJ = posJ - 1
                if posI < 0:
                    posI = self.__grid.getN() - 1
                if posJ < 0:
                    posJ = self.__grid.getM() - 1
                maxTrys += 1
                if maxTrys == self.__grid.getN() * self.__grid.getM():
                    maxTrys = 0
                    posI = random.randint(0, self.__grid.getN()-1)
                    posJ = random.randint(0, self.__grid.getM()-1)
            # Raio de visão vai ser sempre a raiz 7a de nxm
            ant = Ant(rayOfVision=Simulation.ray)
            # open('formiga.txt', 'a').write('{}\n'.format(int((self.__grid.getN()
            #                                                  * self.__grid.getM())**(1/8))))
            self.__ants[ant] = [posI, posJ]

    def __f(self, data: Data, near) -> float:
        if len(near) == 0:
            return 0
        summ = 0
        for point in near:
            other = self.__grid.get(point[0], point[1])
            # print(isinstance(data, Data), isinstance(other, Data))
            distance = data.euclidianDistance(
                another=other)
            # print('distance: ', distance)
            summ += 1 - (distance/Simulation.alpha)
        ret = summ/(len(near)**2)
        # print(ret if ret > 0 else 0)
        return ret if ret > 0 else 0

    def __grab(self, i: int, j: int, rayOfVision: int) -> Any:
        near = self.__grid.getNearIndexes(
            i, j, rayOfVision=rayOfVision, withData=True)
        # print(near)

        if self.__grid.getTypeInGrid(i, j) == 1:
            pp = self.__pp(i, j,
                           near)
            # open('analise.txt', 'a').write('{},{}\n'.format(pp, 0))
            if pp > random.uniform(0, 0.5):
                # open('logs.txt', 'a').write(
                #     '{} - {}\n'.format(datetime.now().strftime("%H:%M:%S:%f"), 'CATOU'))
                return self.__grid.get(i, j)
            else:
                None
        else:
            return None

    def sigmoid(self, x) -> float:  # x = 0 => 0 // x = 1 =>
        mult = math.exp(-Simulation.k1*x)
        return (1-mult)/(1+mult)

    def __pp(self, i: int, j: int, near) -> float:
        f = self.__f(self.__grid.get(i, j), near)
        # open('valoresF.txt', 'a').write(
        #     '{},{},{}\n'.format(1-self.sigmoid(f), 'pp', self.__era))
        # return 1-self.sigmoid(f)
        # ret = 1-self.sigmoid(f)
        ret = (Simulation.k1/Simulation.k1+f)**2
        return ret

    def __drop(self, i: int, j: int, rayOfVision: int) -> bool:
        near = self.__grid.getNearIndexes(
            i, j, rayOfVision=rayOfVision, withData=True)
        pd = self.__pd(i, j, near)
        if pd > random.uniform(0, 0.5):
            # open('analise.txt', 'a').write('{},{}\n'.format(pd, 1))
            # open('logs.txt', 'a').write(
            #     '{} - {}\n'.format(datetime.now().strftime("%H:%M:%S:%f"), 'DROPOU'))
            return True
        else:
            return False

    def calculateAlpha(self) -> float:
        datas = []
        for i in range(self.__grid.getN()):
            for j in range(self.__grid.getM()):
                if self.__grid.isOcupated(i, j):
                    datas.append((self.__grid.get(i, j), i, j))
        distDatas = 0
        contDatas = 0
        for i in range(len(datas)):
            for j in range(len(datas)):
                if i != j:
                    distDatas += datas[i][0].euclidianDistance(
                        another=datas[j][0])
                    contDatas += 1
        Simulation.alpha = distDatas/contDatas
        print('New Alpha: {}'.format(Simulation.alpha))

    def __normalizaPos(self, i) -> float:
        return 100 - i if i > 50 else i

    def __pd(self, i: int, j: int, near) -> float:
        f = self.__f(self.getAntInPoint(i, j).getData(), near)
        # open('valoresF.txt', 'a').write(
        #     '{},{},{}\n'.format(self.sigmoid(f), 'pd', self.__era))
        # return self.sigmoid(f)
        # ret = self.sigmoid(f)
        ret = 2*f if f < Simulation.k2 else 1
        return ret

    def cataFumiga(self) -> Any:
        return self.__ants

    def __hasAntInPoint(self, i: int, j: int) -> Any:
        return [i, j] in list(self.__ants.values())

    def __move(self, ant: Ant) -> None:
        nears = self.__grid.getNearIndexes(
            self.__ants[ant][0], self.__ants[ant][1], rayOfVision=1)
        random.shuffle(nears)
        for point in nears:
            if self.getTypeInGrid(point[0], point[1]) != 0:
                # Atualiza a posicao da formiga no dicionario ants
                self.__ants[ant] = point
            return

    def countCarring(self) -> int:
        cont = 0
        for i in self.__ants.keys():
            if i.isCarrying():
                cont += 1
        return cont

    def countsCarringAnts(self) -> str:
        return '{}/{} carregando'.format(self.countCarring(), len(self.__ants))

    def next(self) -> Any:
        self = deepcopy(self)
        self.__era += 1
        for ant in list(self.__ants.keys()):
            pos = self.__ants[ant]
            if not ant.isCarrying() and self.__grid.getTypeInGrid(pos[0], pos[1]) == 1 and Simulation.stop != True:
                item = self.__grab(pos[0], pos[1], ant.getRayOfVision())
                if item is not None:
                    ant.grab(item)
                    self.__grid.put(None, pos[0], pos[1])
            if ant.isCarrying() and self.__grid.getTypeInGrid(pos[0], pos[1]) == 2:
                if self.__drop(pos[0], pos[1], ant.getRayOfVision()):
                    item = ant.drop()
                    self.__grid.put(item, pos[0], pos[1])

            self.__move(ant)
        return self

    def __repr__(self) -> str:
        return str(self.__grid)

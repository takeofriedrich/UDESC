from typing import Any
from Ant import Ant
from Data import Data


class Grid:

    def __init__(self, m, n) -> None:
        self.__n = n
        self.__m = m
        self.__grid = {}
        for i in range(self.__n):
            self.__grid[i] = [None for j in range(self.__m)]

    def getN(self) -> int:
        return self.__n

    def n(self, n) -> None:
        self.__n = n

    def getM(self) -> int:
        return self.__m

    def n(self, m) -> None:
        self.__m = m

    def isOcupated(self, i, j) -> bool:
        return self.__grid[i][j] is not None

    def put(self, elementos, i, j) -> None:
        self.__grid[i][j] = elementos

    def get(self, i: int, j: int) -> Any:
        return self.__grid[i][j]

    def getPosition(self, i, j) -> Any:
        if i < 0:
            i = self.__m - abs(i)
        if i >= self.__m:
            i -= self.__m
        if j < 0:
            j = self.__n - abs(j)
        if j >= self.__n:
            j -= self.__n
        return [i, j]

    def isInLimit(self, i, j) -> bool:
        return (i >= 0 and i < self.__n) and (j >= 0 and j < self.__m)

    def getNearIndexes(self, i: int, j: int, rayOfVision: int, withData: bool = False) -> list:
        indexes = []
        for k in range(1, rayOfVision+1):
            leftUpperBorder = [i-k, j-k]
            leftDownerBorder = [i+k, j-k]
            rightUpperBorder = [i-k, j+k]
            rightDownerBorder = [i+k, j+k]

            # fixo leftUpper[0] for (leftUpper[1],rightUpper[1]+1)
            for it in range(leftUpperBorder[1], rightUpperBorder[1]+1, 1):
                pos = self.getPosition(leftUpperBorder[0], it)
                if withData and isinstance(self.__grid[pos[0]][pos[1]], Data) and pos not in indexes:
                    indexes.append(pos)
                elif not withData and pos not in indexes:
                    indexes.append(pos)

            # fixo leftDowner[1] for (leftDowner[0],rightDowner[0]+1)
            for it in range(leftDownerBorder[1], rightDownerBorder[1]+1, 1):
                pos = self.getPosition(rightDownerBorder[0], it)
                if withData and isinstance(self.__grid[pos[0]][pos[1]], Data) and pos not in indexes:
                    indexes.append(pos)
                elif not withData and pos not in indexes:
                    indexes.append(pos)

            # fixo leftUpper[1] for (leftUpper[0],leftDowner[0] + 1)
            for jt in range(leftUpperBorder[0], leftDownerBorder[0]+1, 1):
                pos = self.getPosition(jt, leftUpperBorder[1])
                if withData and isinstance(self.__grid[pos[0]][pos[1]], Data) and pos not in indexes:
                    indexes.append(pos)
                elif not withData and pos not in indexes:
                    indexes.append(pos)

            # fixo rightUpper[1] for (rightUpper[0],rightDowner[0] + 1)
            for jt in range(rightUpperBorder[0], rightDownerBorder[0]+1, 1):
                pos = self.getPosition(jt, rightUpperBorder[1])
                if withData and isinstance(self.__grid[pos[0]][pos[1]], Data) and pos not in indexes:
                    indexes.append(pos)
                elif not withData and pos not in indexes:
                    indexes.append(pos)

            # print(indexes)
        return indexes

    # Retorna 1 caso dado e 2 caso None
    def getTypeInGrid(self, i: int, j: int) -> int:

        return 2 if self.__grid[i][j] is None else 1

    def __repr__(self) -> str:
        s = ''
        for i in self.__grid.keys():
            for j in range(self.__m):
                s += '{}\t'.format(str(Data(self.__grid[i][j]))
                                   if self.__grid[i][j] is not None else None)
            s += '\n'
        return s[:-1]

# 0: [1,2,3,4,5]
# 1: [2,3,4,5,6]

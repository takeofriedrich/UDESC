from typing import Any
import math


class Data:
    def __init__(self, datas=[], hasLabel=False) -> None:
        self.__hasLabel = hasLabel
        self.__datas = datas

    def setDatas(self, datas: list) -> None:
        self.__datas = datas

    def getDatas(self) -> list:
        return self.__datas

    def euclidianDistance(self, another: Any) -> float:
        # if not isinstance(another, Data):
        #     return 99999
        if len(self.__datas) != len(another.getDatas()):
            raise Exception(
                'Datas have different dimensions, not possible to calculate Euclidian Distance')
        else:
            sum = 0
            limit = len(self.__datas) if self.__hasLabel else len(
                self.__datas)-1
            for i in range(limit):
                sum += (self.__datas[i] - another.getDatas()[i])**2
            return math.sqrt(sum)

    def __repr__(self) -> str:
        return str(self.__datas).replace('[', '').replace(']', '') if self.__datas is not None else None

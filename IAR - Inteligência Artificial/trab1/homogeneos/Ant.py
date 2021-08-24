from Data import Data
from random import randint
from typing import Any


class Ant:

    def __init__(self, rayOfVision=10) -> None:
        self.__bornedVision = rayOfVision
        self.__rayOfVision = rayOfVision
        self.__bag = None

    # Formiguinha consegue carregar apenas um item por vez em sua "mochilinha"
    def isCarrying(self) -> bool:
        return self.__bag is not None

    def grab(self, item) -> None:
        self.__bag = item

    def miope(self) -> None:
        self.__rayOfVision -= 1

    def getData(self) -> Data:
        return self.__bag

    def drop(self) -> Any:
        item = self.__bag
        self.__bag = None
        return item

    def getRayOfVision(self) -> int:
        return self.__rayOfVision

    def __repr__(self) -> str:
        return '-ant-'

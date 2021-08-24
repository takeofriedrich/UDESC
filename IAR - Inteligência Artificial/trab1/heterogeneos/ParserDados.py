class ParserDados:

    @staticmethod
    def parseDados(fileName, transformacao=None) -> list:
        lines = [line.replace('\n', '')
                 for line in open(fileName, 'r').readlines()]
        datas = []
        for line in lines:
            info = line.split('\t')
            if transformacao is not None:
                datas.append(
                    (transformacao(float(info[0].replace(',', '.'))), transformacao(float(info[1].replace(',', '.'))), int(info[2])))
            else:
                datas.append(
                    (float(info[0].replace(',', '.')), float(info[1].replace(',', '.')), int(info[2])))
        return datas

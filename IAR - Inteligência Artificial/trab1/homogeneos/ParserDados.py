class ParserDados:

    @staticmethod
    def parseDados(fileName) -> list:
        lines = [line.replace('\n', '')
                 for line in open(fileName, 'r').readlines()]
        datas = []
        for line in lines:
            info = line.split('\t')

            datas.append(
                (float(info[0].replace(',', '.')), float(info[1].replace(',', '.')), int(info[2])))
        return datas

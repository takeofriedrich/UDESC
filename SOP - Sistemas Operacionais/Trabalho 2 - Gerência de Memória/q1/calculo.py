def pg(el,tam):
    return int(el/tam)

def d(el,tam):
    return el % tam

def ef(el,tam):
    return (pg(el,tam)*tam)+d(el,tam)

def calcula(end,tam):
    print('endereco logico: '+str(end))
    print('pagina: '+str(pg(end,tam)))
    print('deslocamento: '+str(d(end,tam)))
    print('ef: '+str(ef(end,tam)))

calcula(27527,4096)
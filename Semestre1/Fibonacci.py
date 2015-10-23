def fibonacci(n):
    sequenciaAtual = 1
    sequenciaAnterior = 1
    while(sequenciaAtual<=n):
        if(sequenciaAtual==1):
            print(sequenciaAtual)
            print(sequenciaAnterior)
            sequenciaAtual = sequenciaAnterior+sequenciaAtual
        else:
            print(sequenciaAtual)
            sequenciaAtual = sequenciaAnterior+sequenciaAtual
            sequenciaAnterior = sequenciaAtual-sequenciaAnterior

fibonacci(145)

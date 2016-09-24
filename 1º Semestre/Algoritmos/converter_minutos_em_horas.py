entrada = float(input('Digite a quantidade de tempo em minutos: '))

horas = entrada//60
minutos = int(str(entrada%60)[:str(entrada%60).find('.')])
segundos = (entrada-(horas*60+minutos))*60

print('%i Horas, %i Minutos e %.2f segundos'%(horas,minutos,segundos))






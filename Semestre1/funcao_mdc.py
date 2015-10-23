def mdc(num1,num2):
    maior = max(num1,num2)
    menor = min(num1,num2)
    if(maior%menor==0):
        return menor
    else:
        return mdc(menor,(maior%menor))

print(mdc(48,30))

def mmc(num1,num2):
    return abs(num1*num2)/mdc(num1,num2)

print(mmc(30,12))



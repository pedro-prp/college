digitos = {
    0: "zero", 1: "um", 2: "dois", 3: "três", 4: "quatro", 5: "cinco", 
    6: "seis", 7: "sete", 8: "oito", 9: "nove", 10: "dez",
}
numero = 97

print(digitos[int(str(numero)[0])] + " " + digitos[int(str(numero)[1])])

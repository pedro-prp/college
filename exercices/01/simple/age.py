idade = 65

if idade >= 18 and idade < 64:
    categoria = 'regular'
elif idade < 0 or idade > 120:
    categoria = 'inválido'
elif idade < 14 or idade > 80:
    categoria = 'bloqueado'
elif idade >= 14 and idade <= 17:
    categoria = 'aprendiz'
elif idade >= 65 and idade < 80:
    categoria = 'idoso'

print('usuário está na categoria', categoria)
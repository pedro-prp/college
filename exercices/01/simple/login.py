user = {
    "name": "Fábio Mendes",
    "email": "fabiomendes@unb.br",
    "age": 38,
    "password": "passwrd1234",
}

password = "passwrd1234"
email = "fabiomendes@unb.br"

login = (email == user['email']) and (password == user['password'])
print(login)
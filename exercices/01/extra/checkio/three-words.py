def checkio(worlds):
    s = 0
    for str in worlds.split():
        print(str)
        if str.isdigit() and s < 3:
            s = 0
        else:
            s += 1

    return s >= 3

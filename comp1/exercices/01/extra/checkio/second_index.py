def second_index(text: str, symbol: str) -> [int, None]:

    p = text.replace(symbol, '', 1).find(symbol)

    if p > 0:
        return p+1
    else:
        return None

def popular_words(text: str, words: list) -> dict:
    d = sorted(list(map(lambda x: {'value': text.upper().split().count(x.upper()), x: text.upper().split().count(x.upper())}, words)), key=lambda k: k['value'], reverse=True)
    list(map(lambda x: x.pop('value'), d))

    r = dict()

    for i in d:
        r[list(i.items())[0][0]] = list(i.items())[0][1]

    return r

def first_word(text: str) -> str:
    text = text.replace(',', '').replace('.', ' ').split()

    if text[0][0] == ' ':
        return text[1]
    
    return text[0]

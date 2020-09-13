def count_digits(text: str) -> int:
    return len([c for c in text if c.isdigit()])
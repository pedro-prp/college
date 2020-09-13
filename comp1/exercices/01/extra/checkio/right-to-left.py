def left_join(phrases: tuple) -> str:
    return ','.join([s.replace('right', 'left') for s in list(phrases)])
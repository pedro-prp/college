import math


def split_list(items: list) -> list:

    return [items[0:math.ceil(len(items)/2)], items[math.ceil(len(items)/2):len(items)]]

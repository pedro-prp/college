from typing import List, Any


def all_the_same(elements: List[Any]) -> bool:
    return all(x == elements[0] for x in elements)

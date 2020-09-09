def checkio(array: list) -> int:
    
    if array == []:
        return 0
    
    return sum(array[0::2])*array[-1]
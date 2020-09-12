def bigger_price(limit: int, data: list) -> list:

    return (sorted(data, key=lambda k: k['price'], reverse=True))[0:limit]
3
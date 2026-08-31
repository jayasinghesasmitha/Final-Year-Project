def expansion(x, w, bias=0):
    return bias + sum(a * b for a, b in zip(x, w))

def depthwise(window, kernel, bias=0):
    return bias + sum(a * b for a, b in zip(window, kernel))

def projection(x, w, bias=0):
    return bias + sum(a * b for a, b in zip(x, w))

if __name__ == "__main__":
    x = list(range(1, 9))
    w = [2] * 8
    print("Expansion:", expansion(x, w, 5))

    window = list(range(1, 10))
    kernel = [1] * 9
    print("Depthwise:", depthwise(window, kernel, -3))

    x = [i - 4 for i in range(24)]
    w = [1] * 24
    print("Projection:", projection(x, w, 10))

import math

target = 0

def f(x: float) -> float:
    return math.pow(9,x) + math.pow(25, x) - math.pow(45, x);

def df(x: float) -> float:
    return math.pow(9,x)*math.log(9) + math.pow(25, x)*math.log(25) - math.pow(45, x)*math.log(45);

def newton(inital_value: float, threshold: float = 1e-65535, epsilon: float = 1e-255) -> tuple[bool, float, float, float]:
    unlimited = False
    x = inital_value
    y = f(x)
    dy = df(x)
    print(f"Calculated values are x={x}, y={y}, dy={dy}")
    while abs(y-target) > threshold and not unlimited:
        x = x - y/dy
        y = f(x)
        dy = df(x)
        if (abs(dy) < epsilon):
            unlimited = True
            break
        print(f"Calculated values are x={x}, y={y}, dy={dy}")
    
    return unlimited, x, y, dy


estimated_left = -3
estimated_right = 5

if __name__ == "__main__":
    for inital_value in range(estimated_left, estimated_right):
        unlimited, x, y, dy = newton(inital_value)
        if not unlimited:
            print(f"final distance calculated values are x={x}, y={y}, dy={dy}")
            break
        else:
            print(f"wrong selection of inital value x={inital_value}")


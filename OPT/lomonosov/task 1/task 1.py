def convert(num : float):
    exponent = 0
    shifted_num = num

    while shifted_num != int(shifted_num):        
        shifted_num *= 2
        exponent += 1

    if exponent == 0:
        return '{0:0b}'.format(int(shifted_num))
    
    binary = '{0:0{1}b}'.format(int(shifted_num),exponent + 1)
    integer_part = binary[:-exponent]
    fractional_part = binary[-exponent:].rstrip('0')
    return '{0}.{1}'.format(integer_part, fractional_part)   

def f(s : str, start : int, side : float, color) -> (float, int):
    count = 0
    answer, i = 0.0, start
    while i < len(s) and count < 8:
        if s[i] == color:
            answer += side ** 3
        if s[i] == 'Q':
            d, j = f(s, i + 1, side / 2, color)
            answer += d
            i = j - 1
        count += 1
        i += 1
    return answer, i

s = str(input())
c = input()

answer, _ = f(s, 0, 1, c)
print(float(convert(answer)))
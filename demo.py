def print_area():
    for i in reversed(range(1, N+1)):
        row = area[i]
        print('{0:2}'.format(i), end=' ')
        print(' '.join(row[1:]))
    print('   ', end='')
    for i in range(1, 3*N+1):
        print('{0:2}'.format(i), end=' ')


N = int(input())
H = list(map(int, input().split()))

area = [['  '] * (3 * N + 1) for _ in range(N+1)]
for i in range(N):
    h = H[i]
    for j in range(1, h+1):
        area[j][(i+1)*3] = '**'
x = 1
y = N
direction = '>>'
area[y][x] = direction
print_area()
while y > 0 and x > 0:
    area[y][x] = '  '
    if direction == '>>':
        if (x + 1) % 3 == 0 and H[x // 3] >= y:
            y -= 1
            direction = '<<'
        else:
            x += 1
    else:
        if (x - 1) % 3 == 0 and H[x // 3 - 1] >= y:
            y -= 1
            direction = '>>'
        else:
            x -= 1
    area[y][x] = direction
    input()
    print_area()



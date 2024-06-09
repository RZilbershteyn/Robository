import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def animate(i):
    ax.clear()
    line = (ax.plot(x, y_1, 'b', label='\u03A9'), ax.plot(x, y_2, 'b'),
            ax.plot(b[i][0], b[i][1], 'c', label=r'$\omega_1$'), ax.plot(b[i][0], b[i][2], 'c'),
            ax.plot(C[i][0], C[i][1], 'm', label=r'$\omega_2$'), ax.plot(C[i][0], C[i][2], 'm'),
            ax.plot([d[i][0], d[i][0]], [A[1], d[i][1]], 'y', label='Кас-я к \u03A9'),
            ax.scatter(0, 0, marker='o', c='b'),
            ax.scatter(x[i], y_1[i], marker='o', c='c', label=r'$\forall точка \in \Omega$'),
            ax.scatter(c[i][0], c[i][1], marker='o', c='m', label=r'$\Omega \cap \omega_1$'),
            ax.scatter(d[i][0], d[i][1], marker='o', c='y', label=r'$\omega_2 \cap \omega_1$'),
            ax.scatter(A[0], A[1], s=80, marker='o', c='black', label='A')
            )
    ax.set_ylim(-4, 4)
    ax.set_xlim(-4, 4)
    ax.legend()
    ax.grid()
    ax.set_title('Построить касательную к окружности \u03A9 в данной точке A.')
    return line


def sqal(m, n):
    return m[0] * n[0] + m[1] * n[1]


def len2(v):
    return v[0] ** 2 + v[1] ** 2


N = 100

x = np.linspace(-1, 1, N)
y_1 = np.sqrt(1 - x ** 2)
y_2 = -y_1

A = [-1, 0]
b = []
c = []
for i in range(0, N):
    R_1 = (A[0] - x[i]) ** 2 + (A[1] - y_1[i]) ** 2
    x_2 = np.linspace(x[i] - np.sqrt(R_1), x[i] + np.sqrt(R_1), N)
    y2_1 = y_1[i] + np.sqrt(R_1 - (x_2 - x[i]) ** 2)
    y2_2 = 2 * y_1[i] - y2_1
    b.append([x_2, y2_1, y2_2])
    c.append([-A[0] + 2 * sqal(A, [x[i], y_1[i]]) * x[i] / len2([x[i], y_1[i]]),
              -A[1] + 2 * sqal(A, [x[i], y_1[i]]) * y_1[i] / len2([x[i], y_1[i]])])

d = []
C = []
for i in range(N):
    R_2 = (A[0] - c[i][0]) ** 2 + (A[1] - c[i][1]) ** 2
    x_3 = np.linspace(A[0] - np.sqrt(R_2), A[0] + np.sqrt(R_2), N)
    y3_1 = A[1] + np.sqrt(R_2 - (x_3 - A[0]) ** 2)
    y3_2 = 2 * A[1] - y3_1
    d.append([A[0], np.sqrt(R_2)])
    C.append([x_3, y3_1, y3_2])

fig, ax = plt.subplots()

gif = animation.FuncAnimation(fig, animate, frames=len(b), interval=20, repeat=1)

plt.show()

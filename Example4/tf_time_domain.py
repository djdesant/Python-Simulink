import numpy as np
import control as ctl
import matplotlib.pyplot as plt

t = np.linspace(0., 1.5, 100)
sys = ctl.tf([1., -4.], [1., -4., 13.])

T = np.zeros(len(t))
yout = np.zeros(len(t))

for i in range(len(t)+1):
    T[i], yout[i] = ctl.impulse_response(sys, T=t[i])  # HERE is what I wanted

# T, yout = ctl.impulse_response(sys, T=t)  # HERE is what I wanted

y_ans = lambda x: 1/3*np.exp(2*x)*(3*np.cos(3*x) - 2*np.sin(3*x))

plt.plot(t, y_ans(t), '-.', color='gray', alpha=0.5, linewidth=3, label='correct answer')
plt.plot(T, yout, 'r', label='simulated')
plt.legend()

plt.show()
from bus_test import *
from tests.test_01 import *
import matplotlib.pyplot as plt

if __name__ == '__main__':

    Ts = 0.001
    mdl = bus_test(ts=uint32_T(20))
    # test_step_response(mdl, Ts)
    #test_1(mdl, Ts)

    # mdl.plot()
    # plt.show()

    mdl.initialize()
    mdl.P.p.ts = uint32_T(20)
    mdl.P.p.Para1 = uint32_T(2)
    mdl.P.p.Para2 = uint32_T(4)

    mdl.input_signal = 2.0
    mdl.U.U.In1 = uint32_T(1000)
    mdl.U.U.In2 = uint16_T(2)

    for i in range(100):
        mdl.step()
        print(mdl.Y.Y.Out1, mdl.Y.Y.Out2)



    mdl.terminate()

    # mprint(mdl.__repr__())

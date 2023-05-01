import os
import platform

from rtwtypes import *
from ctypes import *


class bus_test_Para_t(Structure):
    def __init__(self):
        self.ts = uint32_T(20)
        self.Para1 = uint32_T(2)
        self.Para2 = uint32_T(4)
        super().__init__(ts=self.ts,
                         Para1=self.Para1,
                         Para2=self.Para2)
    _fields_ = [("ts", uint32_T),
                ("Para1", uint32_T),
                ("Para2", uint32_T)]


class bus_test_Diag_t(Structure):
    def __init__(self):
        self.Diag1 = uint32_T(0)
        self.Diag2 = uint16_T(0)
        super().__init__(Diag1=self.Diag1,
                         Diag2=self.Diag2)
    _fields_ = [("Diag1", uint32_T),
                ("Diag2", uint16_T)]


class bus_test_In_t(Structure):
    def __init__(self):
        self.In1 = uint32_T(0)
        self.In2 = uint16_T(0)
        super().__init__(In1=self.In1,
                         In2=self.In2)
    _fields_ = [("In1", uint32_T),
                ("In2", uint16_T)]
    # def __repr__(self):
    #     return 'bus_test__In_t({},{})'.format(self.In1, self.In2)


class bus_test_Out_t(Structure):
    def __init__(self):
        self.Out1 = uint32_T(0)
        self.Out2 = uint16_T(0)
        super().__init__(Out1=self.Out1,
                         Out2=self.Out2)
    _fields_ = [("Out1", uint32_T),
                ("Out2", uint16_T)]


# /* Block states (default storage) for system '<Root>' */
class D_Work_bus_test(Structure):
    _fields_ = [("d", bus_test_Diag_t),
                ("UnitDelay_DSTATE", uint32_T),
                ("DiscreteTimeIntegrator_DSTATE", int32_T)]


class InstP_bus_test(Structure):
    def __init__(self):
        self.p = bus_test_Para_t()
        super().__init__(p=self.p)
    _fields_ = [("p", bus_test_Para_t)]


class ExternalInputs_bus_test(Structure):
    def __init__(self):
        self.U = bus_test_In_t()
        super().__init__(U=self.U)

    _fields_ = [("U", bus_test_In_t)]


class ExternalOutputs_bus_test(Structure):
    def __init__(self):
        self.Y = bus_test_Out_t()
        self.D = bus_test_Diag_t()
        super().__init__(Y=self.Y,
                         D=self.D)
    _fields_ = [("Y", bus_test_Out_t),
                ("D", bus_test_Diag_t)]


# /* Forward declaration for rtModel */
class RT_MODEL_bus_test(Structure):
    # def __init__(self):
    #     self.dwork = POINTER(D_Work_bus_test)
    #     self.bus_test_InstP_ref = POINTER(InstP_bus_test)
    #     super().__init__(dwork=self.dwork,
    #                      bus_test_InstP_ref=self.bus_test_InstP_ref)
    _fields_ = [("dwork", POINTER(D_Work_bus_test)),
                ("bus_test_InstP_ref", POINTER(InstP_bus_test))]


class bus_test:
    def __init__(self, ts=None):
        self.U = ExternalInputs_bus_test()
        self.Y = ExternalOutputs_bus_test()
        self.M = RT_MODEL_bus_test()
        self.P = InstP_bus_test()

        if ts is not None:
            self.ts = ts
        else:
            self.ts = uint32_T(1)

        # self.model = "bus_test"  # model="bus_test" # model
        if platform.system() == "Linux":
            self.dll_path = os.path.abspath(f"bus_test.so")
            self.dll = ctypes.cdll.LoadLibrary(self.dll_path)
        elif platform.system() == "Windows":
            self.dll_path = os.path.abspath(f"bus_test_win64.dll")
            self.dll = ctypes.windll.LoadLibrary(self.dll_path)
        else:
            raise Exception("System Not Supported")

        # Now mimic their declaration in ert_main.c
        self.DWork = D_Work_bus_test()
        self.M_ = RT_MODEL_bus_test()
        self.MPtr = pointer(self.M_)

        # Model entry point functions
        self._initialize = getattr(self.dll, f"bus_test_initialize")
        self._step = getattr(self.dll, f"bus_test_step")
        self._terminate = getattr(self.dll, f"bus_test_terminate")


    def initialize(self):
        """Initialize the Model."""
        # / * Pack model data into RTM * /
        self.M.dwork = pointer(self.DWork)
        self.M.bus_test_InstP_ref = pointer(self.P)

        # self.P.contents = [20, 2, 4]

        self.P.p.ts = self.ts

        self._initialize(self.M)
        self.step_num = -1

    def step(self):
        """Step through the model Model."""
        self._step(self.M, byref(self.U), byref(self.Y))
        self.step_num += 1

    def terminate(self):
        """Terminate the model Model."""
        self._terminate(self.M)

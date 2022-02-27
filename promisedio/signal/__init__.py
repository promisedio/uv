# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os
import sys

if os.environ.get("PROMISEDIO_DEBUG"):
    from . import _signal_debug
    sys.modules[f"{__name__}._signal"] = _signal_debug

from . _signal import *
del os, sys

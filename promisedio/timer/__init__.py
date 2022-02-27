# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os
import sys

if os.environ.get("PROMISEDIO_DEBUG"):
    from . import _timer_debug
    sys.modules[f"{__name__}._timer"] = _timer_debug

from . _timer import *
del os, sys

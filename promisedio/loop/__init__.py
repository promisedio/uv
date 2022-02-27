# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os
import sys

if os.environ.get("PROMISEDIO_DEBUG"):
    from . import _loop_debug
    sys.modules[f"{__name__}._loop"] = _loop_debug

from . _loop import *
del os, sys

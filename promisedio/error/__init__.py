# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os
import sys

if os.environ.get("PROMISEDIO_DEBUG"):
    from . import _error_debug
    sys.modules[f"{__name__}._error"] = _error_debug

from . _error import *
del os, sys

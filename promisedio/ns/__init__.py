# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os
import sys

if os.environ.get("PROMISEDIO_DEBUG"):
    from . import _ns_debug
    sys.modules[f"{__name__}._ns"] = _ns_debug

from . _ns import *
del os, sys


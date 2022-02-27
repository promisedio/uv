# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os
import sys

if os.environ.get("PROMISEDIO_DEBUG"):
    from . import _fs_debug
    sys.modules[f"{__name__}._fs"] = _fs_debug

from . _fs import *
del os, sys

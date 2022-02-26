# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os

if os.environ.get("PROMISEDIO_DEBUG"):
    from . _fs_debug import *
else:
    from . _fs import *

del os

# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os

if os.environ.get("PROMISEDIO_DEBUG"):
    from . _error_debug import *
else:
    from . _error import *

del os

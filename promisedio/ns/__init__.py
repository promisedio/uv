# Copyright (c) 2021-2022 Andrey Churin <aachurin@gmail.com> Promisedio

import os

if os.environ.get("PROMISEDIO_DEBUG"):
    from . _ns_debug import *
else:
    from . _ns import *

del os

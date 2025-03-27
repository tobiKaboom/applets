import time
import sys

loading = ['[*    ]', '[ *   ]', '[  *  ]', '[   * ]', '[    *]', '[   * ]', '[  *  ]', '[ *   ]']

while True:
    for i in loading:
        sys.stdout.write(f"\rLoading... {i}")
        sys.stdout.flush()
        time.sleep(0.3)

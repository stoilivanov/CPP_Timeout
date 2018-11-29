# CPP_Timeout
executes anonymous functions with a delay

# Usage

```CPP
#include "Timeout.h"
sivanov::Timeout Timeout;
Timeout(lambda, delay_in_seconds);
Timeout([]()
    {
    std::cout << "Function is executed with 3 seconds delay";
    }, 3);
}
```

[![Build Status](https://travis-ci.org/stoilivanov/CPP_Timeout.svg?branch=master)](https://travis-ci.org/stoilivanov/CPP_Timeout)

# CPP_Timeout
executes anonymous functions with a delay

# Usage

```CPP
#include "Timeout.h"
sivanov::Timeout Timeout;

// Timeout(lambda, delay_in_seconds);

Timeout([]()
    {
    std::cout << "Function is executed with 3 seconds delay";
    }, 3);
}
```

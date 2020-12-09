#include "And.h"

bool And::produceOutput()
{
    return output = (input[0] && input[1]);
}
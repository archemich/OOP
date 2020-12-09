#include "Or.h"

bool Or::produceOutput()
{
    return output = (input[0] || input[1]);
}
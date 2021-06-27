#include "BasicDataTypeDeclarations.h"

i32 CS_iclamp(i32 min, i32 x, i32 max)
{
	return (x < min ? min : (x > max ? max : x));
}

#include"CutOff.h"
const ubyte LEFT_BOUND = 0x1;
const ubyte RIGHT_BOUND = 0x2;
const ubyte BOTTOM_BOUND = 0x4;
const ubyte TOP_BOUND = 0x8;

void CutOffLine(vec2 *&data, int& length, vec2 start, vec2 end, vec2 min, vec2 max)
{
	ubyte startcode = Decode(start, min, max);
	ubyte endcode = Decode(end, min, max);

}

ubyte Decode(vec2 point, vec2 min, vec2 max)
{
	ubyte code = 0x00;
	if (point.x < min.x)
		code = code | LEFT_BOUND;
	if (point.x > max.x)
		code = code | RIGHT_BOUND;
	if (point.y < min.y)
		code = code | BOTTOM_BOUND;
	if (point.y > max.y)
		code = code | TOP_BOUND;
	return code;
}
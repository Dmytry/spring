/**
 * @file float3.cpp
 * @brief float3 source
 *
 * Implementation of float3 class
 */

#include "float3.h"
#include "Vec2.h"


// TODO: this should go in Vec2.cpp if that is ever created
CR_BIND(int2, );
CR_REG_METADATA(int2, (CR_MEMBER(x), CR_MEMBER(y)));
CR_BIND(float2, );
CR_REG_METADATA(float2, (CR_MEMBER(x), CR_MEMBER(y)));

CR_BIND(float3, );
CR_REG_METADATA(float3, (CR_MEMBER(x), CR_MEMBER(y), CR_MEMBER(z)));

float float3::maxxpos = 2048.0f; /**< Maximum x position is 2048 */
float float3::maxzpos = 2048.0f; /**< Maximum z position is 2048 */

#ifdef _MSC_VER
const float float3::CMP_EPS = 1e-4f;
const float float3::NORMALIZE_EPS = 1e-6f;
#endif

bool float3::IsInBounds() const
{
	return ((x >= 0.0f && x <= maxxpos) && (z >= 0.0f && z <= maxzpos));
}

/**
 * @return whether or not it's in bounds
 *
 * Tests whether this vector is in the
 * bounds of the maximum x and z positions.
 */
bool float3::CheckInBounds()
{
	bool in = true;

	if (x < 1.0f) {
		x = 1.0f;
		in = false;
	}
	if (z < 1.0f) {
		z = 1.0f;
		in = false;
	}
	if (x > maxxpos) {
		x = maxxpos;
		in = false;
	}
	if (z > maxzpos) {
		z = maxzpos;
		in = false;
	}

	return in;
}

SAIFloat3 float3::toSAIFloat3() const {

	SAIFloat3 sAIFloat3;

	sAIFloat3.x = x;
	sAIFloat3.y = y;
	sAIFloat3.z = z;

	return  sAIFloat3;
}

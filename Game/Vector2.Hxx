#ifndef __VECTOR2_HXX__
#define __VECTOR2_HXX__

#include "Vector2Base.Hxx" // VCIC-Excluded 

namespace Game {

	#define NEW_VECTOR(name, type)								\
		struct name : Vector2Base<type> {						\
			name() : Vector2Base<type>() {}						\
			name(type x, type y) : Vector2Base<type>(x, y) {}	\
		};

	NEW_VECTOR(Vector2, float)
	NEW_VECTOR(Vector2Int, int)

}

#endif
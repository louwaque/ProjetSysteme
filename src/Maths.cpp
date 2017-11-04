#include "../include/Maths.hpp"

#include "../include/Face.hpp"
#include "../include/Vector.hpp"

Vector Maths::normal(const Object &obj, const size_t iFace) {
  const Face &f = obj.faces()[iFace];
  const Vector &v0 = obj.vertices()[f.v0];
  return Vector(v0, obj.vertices()[f.v1]) ^ Vector(v0, obj.vertices()[f.v2]);
}

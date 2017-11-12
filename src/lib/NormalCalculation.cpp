#include <lib/NormalCalculation.hpp>

#include <lib/OpenMPNormalCalculation.hpp>
#include <lib/SequentialNormalCalculation.hpp>

using namespace lib;

NormalCalculation::NormalCalculation(const Object& object)
  : _object(object)
{}

NormalCalculation::~NormalCalculation() {}

NormalCalculation*
NormalCalculation::factory(const Method m, const Object& o)
{
  switch (m) {
    case Method::Sequential:
      return new SequentialNormalCalculation(o);
    case Method::OpenMP:
      return new OpenMPNormalCalculation(o);
    default:
      return nullptr;
      break;
  }
}

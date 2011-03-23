#include <ruby_bwdi.h>

VALUE rb_int2fix(int i) {
  return INT2FIX(i);
}
VALUE rb_unit_state_get_hitpoints(VALUE);

using namespace BWDI;

void Init_UnitState() {
  VALUE mBWDI = rb_define_module("RubyBWDI");
  VALUE cUnitState = rb_define_class_under(mBWDI, "UnitStateVisible", rb_cObject);
  DEFINE_GETTER(cUnitState, "hitpoints", int, UnitStateVisible, hitPoints);
}

VALUE rb_wrap_unit_state(BWDI::UnitState * us) {
  VALUE mBWDI = rb_define_module("RubyBWDI");
  VALUE cUnitState = rb_define_class_under(mBWDI, "UnitState", rb_cObject);
  VALUE obj = Data_Wrap_Struct(cUnitState, 0, 0, us);
  return obj;
}

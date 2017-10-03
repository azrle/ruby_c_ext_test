#include "ruby.h"

static VALUE bar_bad, bar_good;

VALUE method_bar_bad(VALUE self) {
    return bar_bad;
}

VALUE method_bar_good(VALUE self) {
    return bar_good;
}

void Init_bar() {
    static VALUE mark_ary_bad, mark_ary_good;

    VALUE Bar = rb_define_class("Bar", rb_cObject);

    mark_ary_bad  = rb_ary_new();
    mark_ary_good = rb_ary_new();

    // add "good" to global_list
    rb_global_variable(&mark_ary_good);

    bar_bad  = rb_obj_freeze(rb_str_new("bar", 3));
    bar_good = rb_obj_freeze(rb_str_new("bar", 3));

    rb_ary_push(mark_ary_bad, bar_bad);
    rb_ary_push(mark_ary_good, bar_good);

    // trigger GC
    rb_str_new(0, 1 + (1<<26));

    OBJ_FREEZE(mark_ary_bad);
    OBJ_FREEZE(mark_ary_good);

    // add "bad" to global_list (too late)
    rb_global_variable(&mark_ary_bad);

    rb_define_method(Bar, "bar_bad", method_bar_bad, 0);
    rb_define_method(Bar, "bar_good", method_bar_good, 0);
}

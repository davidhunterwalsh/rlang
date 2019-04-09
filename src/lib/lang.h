#ifndef RLANG_LANG_H
#define RLANG_LANG_H

#include "node.h"


static inline sexp* r_new_call(sexp* car, sexp* cdr) {
  return Rf_lcons(car, cdr);
}

static inline sexp* r_build_call(sexp* head) {
  return r_new_call(head, r_null);
}
static inline sexp* r_build_call1(sexp* head, sexp* arg1) {
  return r_new_call(head, r_pairlist(arg1));
}
static inline sexp* r_build_call2(sexp* head, sexp* arg1, sexp* arg2) {
  return r_new_call(head, r_pairlist2(arg1, arg2));
}

bool r_is_call(sexp* x, const char* name);
bool r_is_call_any(sexp* x, const char** names, int n);

bool r_is_prefixed_call(sexp* x, const char* name);
bool r_is_prefixed_call_any(sexp* x, const char ** names, int n);
bool r_is_maybe_prefixed_call_any(sexp* x, const char ** names, int n);

bool r_is_namespaced_call(sexp* x, const char* ns, const char* name);
bool r_is_namespaced_call_any(sexp* x, const char* ns, const char** names, int n);

bool r_is_special_op_call(sexp* x);

sexp* r_expr_protect(sexp* x);


#endif

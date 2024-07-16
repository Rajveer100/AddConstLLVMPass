; ModuleID = 'examples/foo2.ll'
source_filename = "examples/foo.ll"

define i32 @foo(i32 %a, i32 %b) {
  %e = add i32 %a, %b
  %g = add i32 %e, 10
  ret i32 %g
}

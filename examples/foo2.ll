; ModuleID = 'examples/foo.ll'
source_filename = "examples/foo.ll"

define i32 @foo(i32 %a, i32 %b) {
  %e = add i32 %a, %b
  %f = add i32 3, 7
  %g = add i32 %e, %f
  ret i32 %g
}

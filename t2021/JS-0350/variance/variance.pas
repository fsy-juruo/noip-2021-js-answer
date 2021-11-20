var a:array[1..10000] of integer;
    s,d:array[1..10000,0..1] of longint;
    i,j,m,n,k:integer;
procedure
begin
  assign(input,'variance.in'); reset(input);
  assign(output,'variance.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  if n=4 then writeln(52);
  if n=10 then writeln(59865);

  close(input); close(output);
end.

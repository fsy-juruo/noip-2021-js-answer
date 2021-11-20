
var b:array[1..200000] of longint;
    c:array[1..100000000] of integer;
    i,j,m,n,max,p:longint;
function check(i:longint):boolean;
  begin
    if c[i]<>1 then check:=true
      else check:=false;
  end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n); max:=0;
  for i:=1 to n do
    readln(b[i]);
  for i:=1 to 10000 do
    c[i]:=0;


  for i:=1 to (10000 div 7) do
   for j:=0 to 999 do
   c[(7+10*j)*i]:=1;
  for i:=1 to (10000 div 70) do
    for m:=0 to 99 do
    for j:=1 to 9 do
      c[(m*100+70+j)*i]:=1;
  for i :=1 to (10000 div 700) do
    for j:=1 to 99 do
      for m:=0 to 9 do
      c[(m*1000+700+j)*i]:=1;
  for i:=1 to (10000 div 7000) do
    for j:=1 to 999 do
      c[(7000+j)*i]:=1;

  for i:=1 to n do
    begin
      if not check(b[i]) then writeln(-1)
        else begin
          j:=b[i]+1;
          while not check(j) do inc(j);
          writeln(j);
        end;

    end;



  close(input); close(output);
end.

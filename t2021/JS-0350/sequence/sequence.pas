var a:array[0..100] of longint;
    c:array[0..100] of longint;
    i,j,m,k,n,s,p:longint;
    ans:int64;
function jie(m:integer):integer;
  var i,l:integer;
begin
  l:=1;
  for i:=2 to m do
    l:=l*i;
  jie:=l;
end;


procedure cacu;
  var i,j,v,l:longint;
begin

  v:=1;
  for i:=0 to m do
    for j:=1 to c[i] do
    v:=v*a[i];
  //for i:=0 to m do write(c[i],' ');
  //writeln;
  l:=jie(n);
  for i:=0 to m do
    if c[i]>1 then l:=l div jie(c[i]);
  //writeln(k);
  ans:=(ans+l*v) mod 998244353;

end;
procedure down(s:longint);
var i,j:longint;
begin
  if s=n then writeln('a')//cacu
  else begin

    for i:=0 to m-1 do
      if (c[i]>1) then begin
      c[i]:=c[i]-2; c[i+1]:=c[i+1]+1;
      down(s-1);
      c[i]:=c[i]+2; dec(c[i+1]);
    end;
  end;
end;

function check(s:longint):boolean;
  var i,j,m,n:longint;
begin
  i:=1; m:=0; n:=0;
  while i<=s do
    begin
      if (i and s)<>0 then begin inc(m); c[n]:=1; p:=n; end;
      i:=i shl 1; inc(n);
    end;

  if m<=k then check:=true
    else check:=false;
end;

procedure search(s:longint);
  var i,j,sum:longint;
begin
  for i:=p downto 1 do
    begin
      c[i-1]:=c[i-1]+2*c[i];
      c[i]:=0;
    end;
  sum:=c[0];
  down(sum);

end;


begin
  assign(input,'sequence.in'); reset(input);
  assign(output,'sequence.out'); rewrite(output);
  readln(n,m,k);
  for i:=0 to m do
    read(a[i]);
  j:=1;
  for i:=1 to m do
    j:=j*2;
  for s:=n to n*j do
    begin
      p:=0;
      for i:=0 to 20 do c[i]:=0;
      if check(s)  then search(s);
    end;
  writeln(ans);
  close(input); close(output);
end.
